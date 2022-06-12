#include "mediamodel.h"

MediaModel::MediaModel(QObject *parent)
    : QAbstractListModel{parent}
    ,mPlayer(new QMediaPlayer())
{
    connect(mPlayer, &QMediaPlayer::metaDataAvailableChanged, this, &MediaModel::onMediaStatusChanged);
}

MediaModel::~MediaModel()
{
    if(mPlayer != nullptr){
        delete mPlayer;
        mPlayer = nullptr;
    }
}

QHash<int, QByteArray> MediaModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[MEDIA_FILE_NAME] = "MediaFileName";
    roles[MEDIA_SONG_TITLE] = "MeidaSongTitle";
    return roles;
}

int MediaModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mSongList.count();
}

QVariant MediaModel::data(const QModelIndex &index, int role) const
{

    if(index.row() < 0 || index.row() > mSongList.count()){
        return QVariant();
    }
    const Song &song = mSongList[index.row()];
    if(role == MEDIA_FILE_NAME){
        return song.name();
    }else if(role == MEDIA_SONG_TITLE){
        return song.title();
    }

    return QVariant();

}

void MediaModel::loadMediaList()
{
    QStringList path = QStandardPaths::standardLocations(QStandardPaths::MusicLocation);
    if(path.count() > 0){
        qDebug() << Q_FUNC_INFO << path.at(0);
        m_pathFolder = path.at(0);
        QDir dir(path.at(0));
        m_list = dir.entryList(QStringList() << "*.mp3", QDir::Files);
    }

}

const QString &MediaModel::pathFolder() const
{
    return m_pathFolder;
}

void MediaModel::setPathFolder(const QString &newPathFolder)
{
    if (m_pathFolder == newPathFolder)
        return;
    m_pathFolder = newPathFolder;
    emit pathFolderChanged();
}

const QString &Song::name() const
{
    return m_name;
}

void Song::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
}

const QString &Song::title() const
{
    return m_title;
}

void Song::settitle(const QString &newTitle)
{
    if (m_title == newTitle)
        return;
    m_title = newTitle;
}
