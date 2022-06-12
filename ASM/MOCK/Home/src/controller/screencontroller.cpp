#include "screencontroller.h"
#include "appdefines.h"
#include "loghelper.h"

ScreenController* ScreenController::m_instance = nullptr;

ScreenController::ScreenController(QObject *parent)
    : QObject{parent}
    , m_initialized(false)
    , m_modeDisplay(true)
    , m_engine(nullptr)
    , m_currentVolume(g_volume)
    , m_currentTitle("")
    , m_currentArtist("")
    , m_isCurrentCoverArtNull(true)
    , m_currentPathCoverArt(""), m_currentVideoName("")
{
    //    LOG_INFO;
    // connect with requestBackToHome signal form media app
    QDBusConnection::sessionBus().connect("",
                                          "/media/appInterface",
                                          "media.appInterface",
                                          "requestBackToHome",
                                          this, SLOT(onReceivedRequestBackToHome()));
    // set volume when start app
    requestChangeVolume();

    // connect with requestSendMetaData signal form media app
    QDBusConnection::sessionBus().connect("",
                                          "/media/appInterface",
                                          "media.appInterface",
                                          "requestSendMetaData",
                                          this, SLOT(onReceivedRequestSendMetaData(QString, QString, bool, QString, QString)));
}

ScreenController::~ScreenController()
{
    //    LOG_INFO;
    m_engine = nullptr;
}

ScreenController *ScreenController::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new ScreenController();
    }
    return m_instance;
}

void ScreenController::initialize(QQmlContext *context)
{
    //    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        context->setContextProperty("SCREEN_CTRL", this);
        context->setContextProperty("SCREEN_MODEL", &m_model);
    }
}

void ScreenController::initializeScreen(QQmlApplicationEngine *engine)
{
    //    LOG_INFO;
    if(m_engine == nullptr)
    {
        m_engine = engine;
        //load main qml
        m_engine->load(QUrl(QStringLiteral(MAIN_QML)));
        //show home menu screen
        pushScreen(AppEnums::SCREEN_ID_HOME_MENU);
    }
}

void ScreenController::pushScreen(int screenId)
{
    //    LOG_INFO << screenId;
    m_screenStack.push(screenId);
    reloadScreen();
}

void ScreenController::replaceScreen(int screenId)
{
    //    LOG_INFO << screenId;
    if(m_screenStack.isEmpty())
    {
        m_screenStack.pop();
    }
    m_screenStack.push(screenId);
    reloadScreen();
}

void ScreenController::popScreen()
{
    //    LOG_INFO << m_screenStack.count();
    if(m_screenStack.count() > 1)
    {
        m_screenStack.pop();
        reloadScreen();
    }
}

void ScreenController::popToRoot()
{
    //    LOG_INFO << m_screenStack.count();
    if(m_screenStack.count() > 1)
    {
        m_screenStack.pop();
    }
    reloadScreen();
}

void ScreenController::requestDisplayMusic()
{
    // 1. create a dbus signal
    QDBusMessage msg = QDBusMessage::createSignal(
                "/home/appInterface",       // object path
                "home.appInterface",        // service interface
                "requestDisplayMusic"       // signal name
                );
    // 2. broadcast signal (using session)
    QDBusConnection::sessionBus().send(msg);
}

void ScreenController::requestDisplayVideo()
{
    // 1. create a dbus signal
    QDBusMessage msg = QDBusMessage::createSignal(
                "/home/appInterface",       // object path
                "home.appInterface",        // service interface
                "requestDisplayVideo"       // signal name
                );

    // 2. broadcast signal (using session)
    QDBusConnection::sessionBus().send(msg);
}

void ScreenController::requestChangeVolume()
{
    // 1. create a dbus signal
    QDBusMessage msg = QDBusMessage::createSignal(
                "/home/appInterface",       // object path
                "home.appInterface",        // service interface
                "requestChangeVolume"       // signal name
                );
    // 2. append input arguments
    msg << m_currentVolume;

    // 3. broadcast signal (using session)
    QDBusConnection::sessionBus().send(msg);




}

bool ScreenController::modeDisplay() const
{
    return m_modeDisplay;
}

int ScreenController::currentVolume() const
{
    return m_currentVolume;
}

QString ScreenController::currentTitle() const
{
    return m_currentTitle;
}

QString ScreenController::currentArtist() const
{
    return m_currentArtist;
}

bool ScreenController::isCurrentCoverArtNull() const
{
    return m_isCurrentCoverArtNull;
}

QString ScreenController::currentPathCoverArt() const
{
    return m_currentPathCoverArt;
}

QString ScreenController::currentVideoName() const
{
    return m_currentVideoName;
}

void ScreenController::onReceivedRequestBackToHome()
{
    setModeDisplay(true);
}

void ScreenController::setModeDisplay(bool newModeDisplay)
{
    if (m_modeDisplay == newModeDisplay)
        return;

    m_modeDisplay = newModeDisplay;
    emit modeDisplayChanged();
}

void ScreenController::setCurrentVolume(int newCurrentVolume)
{
    if (m_currentVolume == newCurrentVolume)
        return;

    m_currentVolume = newCurrentVolume;
    g_volume = m_currentVolume;
    testWriteToJson(g_language, g_volume);
    emit currentVolumeChanged();
}

void ScreenController::setCurrentTitle(const QString &newCurrentTitle)
{
    if (m_currentTitle == newCurrentTitle)
        return;

    m_currentTitle = newCurrentTitle;
    emit metaDataChanged();
}

void ScreenController::setCurrentArtist(const QString &newCurrentArtist)
{
    if (m_currentArtist == newCurrentArtist)
        return;

    m_currentArtist = newCurrentArtist;
    emit metaDataChanged();
}

void ScreenController::setIsCurrentCoverArtNull(bool newIsCurrentCoverArtNull)
{
    if (m_isCurrentCoverArtNull == newIsCurrentCoverArtNull)
        return;

    m_isCurrentCoverArtNull = newIsCurrentCoverArtNull;
    emit metaDataChanged();
}

void ScreenController::setCurrentPathCoverArt(const QString &newCurrentPathCoverArt)
{
    if (m_currentPathCoverArt == newCurrentPathCoverArt)
        return;

    m_currentPathCoverArt = newCurrentPathCoverArt;
    emit metaDataChanged();
}

void ScreenController::onReceivedRequestSendMetaData(QString title, QString artist, bool isPathNull, QString pathCoverArt, QString videoName)
{
    qDebug() << Q_FUNC_INFO << "Receiver meta data form media app";
    qDebug() << "Title: " << title;
    qDebug() << "Artist: " << artist;
    qDebug() << "isCoverArtNull: " << isPathNull;
    qDebug() << "path cover art: " << pathCoverArt;
    qDebug() << "Video name: " << videoName;
    setCurrentTitle(title);
    setCurrentArtist(artist);
    setIsCurrentCoverArtNull(isPathNull);
    setCurrentPathCoverArt(pathCoverArt);
    setCurrentVideoName(videoName);
}

void ScreenController::setCurrentVideoName(const QString &newCurrentVideoName)
{
    if (m_currentVideoName == newCurrentVideoName)
        return;

    m_currentVideoName = newCurrentVideoName;
    emit currentVideoNameChanged();
}

void ScreenController::reloadScreen()
{
    if(!m_screenStack.isEmpty())
    {
        QString screenName = ScreenNameMap.value(m_screenStack.top());
        // reload screen on qml
        m_model.setCurrentScreen(screenName);
        if((m_engine != nullptr) && (m_engine->rootObjects().count() > 0))
        {
            QMetaObject::invokeMethod(m_engine->rootObjects().at(0), "reloadScreen");
        }
    }
}
