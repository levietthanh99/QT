#include "baseplayercontroller.h"
#include "loghelper.h"
#include <typeinfo>
//#include "music

BasePlayerController::~BasePlayerController()
{
    mPlaybackModel = nullptr;
    m_videoSurface = nullptr;
    mPlayer.setVideoOutput(m_videoSurface);
}

void BasePlayerController::initialize(QQmlContext *context)
{
//    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        m_isFullScreenVideo = false;
        context->setContextProperty("MPLAYER_CTRL", this);
        context->setContextProperty("MPLAYER_MODEL", mPlaybackModel);
        context->setContextProperty("MPLAYER", &mPlayer);

        // connect with signal from home app
        QDBusConnection::sessionBus().connect("",
                                              "/home/appInterface",
                                              "home.appInterface",
                                              "requestChangeVolume",
                                              this, SLOT(onReceivedRequestChangeVolume(int)));
        //handel if state Player change
        QObject::connect(&mPlayer, &QMediaPlayer::stateChanged, this,
                         &BasePlayerController::handelPlaybackStatusChanged);

        QObject::connect(&mPlayer,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
                         this, SLOT(onMediaStatuschanged(QMediaPlayer::MediaStatus)));


        // connect with signal from home app
        QDBusConnection::sessionBus().connect("",
                                              "/home/appInterface",
                                              "home.appInterface",
                                              "requestDisplayMusic",
                                              this, SLOT(onRequestDisplayMusic()));
        // connect with signal from home app
        QDBusConnection::sessionBus().connect("",
                                              "/home/appInterface",
                                              "home.appInterface",
                                              "requestDisplayVideo",
                                              this, SLOT(onRequestDisplayVideo()));
    }
}

//Play/Pause
void BasePlayerController::requestPlay()
{
    if(mPlaybackModel->currentMediaName() == "")
    {
//        LOG_INFO << "List empty";
        return;
    }

    if(mPlaybackModel->currentStatus() == QMediaPlayer::StoppedState)
    {

        mPlayer.setMedia(QUrl::fromLocalFile(MusicListModel::m_pathFolder + "/" +
                                             mPlaybackModel->currentMediaName()));
        mPlayer.play();
    }else if(mPlaybackModel->currentStatus() == QMediaPlayer::PlayingState){
        mPlayer.pause();
    }else if (mPlaybackModel->currentStatus() == QMediaPlayer::PausedState)
    {
        mPlayer.play();
    }
}

void BasePlayerController::requestNext()
{
    if(mPlaybackModel->currentMediaName() == "")
    {
//        LOG_INFO << "List empty";
        return;
    }

    if(MusicListController::m_listModel.listSong().count() - 1 == mPlaybackModel->currentIndex()){
        //current index in last -> set current name is first
        mPlaybackModel->setCurrentMediaName(MusicListController::m_listModel.listSong().first());
    }else {
        //set current name in next index
        qDebug() << "Current index: " << mPlaybackModel->currentIndex();
        mPlaybackModel->setCurrentMediaName(MusicListController::m_listModel.listSong()
                                            .at(mPlaybackModel->currentIndex() + 1));
    }
    //stop vurrent media and request play next media
    mPlaybackModel->setCurrentStatus(QMediaPlayer::StoppedState);
    requestPlay();
}

void BasePlayerController::requestPrevious()
{
    if(mPlaybackModel->currentMediaName() == ""){
//        LOG_INFO << "List empty";
        return;
    }


    if(mPlaybackModel->currentIndex() == 0){
        //current index in firest -> set current name is last
        mPlaybackModel->setCurrentMediaName(MusicListController::m_listModel.listSong().last());
    }else{
        //set current name in previous index
        qDebug() << "Current index: " << mPlaybackModel->currentIndex();
        mPlaybackModel->setCurrentMediaName(MusicListController::m_listModel.listSong()
                                            .at(mPlaybackModel->currentIndex() - 1));
    }
    //stop vurrent media and request play next media
    mPlaybackModel->setCurrentStatus(QMediaPlayer::StoppedState);
    requestPlay();
}

void BasePlayerController::requestSendMetaData()
{
    // 1. create a dbus signal
        QDBusMessage msg = QDBusMessage::createSignal(
                    "/media/appInterface",       // object path
                    "media.appInterface",        // service interface
                    "requestSendMetaData"       // signal name
                    );
        // 2. append input arguments
        msg << mPlaybackModel->currentTitle() << mPlaybackModel->currentArtist()
            << mPlaybackModel->isCurrentCoverArtNull() << mPlaybackModel->currentPathCoverArt()
            << mPlaybackModel->videoName();

        // 3. broadcast signal (using session)
        QDBusConnection::sessionBus().send(msg);
}

void BasePlayerController::requestPlayVideo()
{

    if(mPlaybackModel->currentStatus() == QMediaPlayer::StoppedState)
    {
        mPlayer.setMedia(QUrl("abc.mp4"));
        mPlaybackModel->setVideoName("TestVideo.mp4");
        mPlayer.play();
    }else if(mPlaybackModel->currentStatus() == QMediaPlayer::PlayingState){
        mPlayer.pause();
    }else if (mPlaybackModel->currentStatus() == QMediaPlayer::PausedState)
    {
        mPlayer.play();
    }
}

bool BasePlayerController::isFullScreenVideo() const
{
    return m_isFullScreenVideo;
}

void BasePlayerController::handelPlaybackStatusChanged(QMediaPlayer::State status)
{
    mPlaybackModel->setCurrentStatus(status);
    qDebug() << Q_FUNC_INFO << "CurrentMediaName: " << mPlaybackModel->currentMediaName();
    qDebug() << Q_FUNC_INFO << "CurrentIndex: " << mPlaybackModel->currentIndex();
}

void BasePlayerController::onReceivedRequestChangeVolume(int msg)
{
    qDebug() << "Current volume: " << msg;
    mPlayer.setVolume(msg*10);
}

void BasePlayerController::onMediaStatuschanged(QMediaPlayer::MediaStatus status)
{
    Q_UNUSED(status);
    mPlaybackModel->setCurrentTitle(mPlayer.metaData(QMediaMetaData::Title).toString());
    mPlaybackModel->setCurrentAlbumName(mPlayer.metaData(QMediaMetaData::AlbumTitle).toString());
    mPlaybackModel->setCurrentArtist(mPlayer.metaData(QMediaMetaData::ContributingArtist).toString());
    QImage tempImage = mPlayer.metaData(QMediaMetaData::CoverArtImage).value<QImage>();

    if(tempImage.isNull()){
        mPlaybackModel->setIsCurrentCoverArtNull(true);
    }else{
        mPlaybackModel->setCurrentPathCoverArt(QString(PROJECT_PATH) +
                                               "images/" + QFileInfo(mPlaybackModel->currentMediaName()).completeBaseName() + ".png");

        tempImage.save(mPlaybackModel->currentPathCoverArt());
        mPlaybackModel->setIsCurrentCoverArtNull(false);
    }





}


void BasePlayerController::onRequestedPlayMusic()
{
    //stop current media if playing video
    mPlaybackModel->setCurrentStatus(QMediaPlayer::StoppedState);
}

void BasePlayerController::onRequestedPlayVideo()
{
    //stop current media if playing music
    mPlaybackModel->setCurrentStatus(QMediaPlayer::StoppedState);
}

void BasePlayerController::setIsFullScreenVideo(bool newIsFullScreen)
{
    if(m_isFullScreenVideo == newIsFullScreen)
        return;

    m_isFullScreenVideo = newIsFullScreen;
    emit isFullScreenVideoChanged();
}
