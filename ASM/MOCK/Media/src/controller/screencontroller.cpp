#include "screencontroller.h"
#include "appdefines.h"
#include "loghelper.h"

ScreenController* ScreenController::m_instance = nullptr;

ScreenController::ScreenController(QObject *parent)
    : QObject{parent}
    , m_initialized(false)
    , m_modeDisplay(false)
    , m_engine(nullptr)
{
    //    LOG_INFO;
    // connect with requestDisplayMedia signal from home app
    QDBusConnection::sessionBus().connect("",
                                          "/home/appInterface",
                                          "home.appInterface",
                                          "requestDisplayMusic",
                                          this, SLOT(onReceivedRequestDisplayMusic()));

    // connect with requestDisplayVideo signal from home app
    QDBusConnection::sessionBus().connect("",
                                          "/home/appInterface",
                                          "home.appInterface",
                                          "requestDisplayVideo",
                                          this, SLOT(onReceivedRequestDisplayVideo()));
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

void ScreenController::requestBackToHome()
{
    // 1. create a dbus signal
        QDBusMessage msg = QDBusMessage::createSignal(
                    "/media/appInterface",       // object path
                    "media.appInterface",        // service interface
                    "requestBackToHome"       // signal name
                    );
        // 2. broadcast signal (using session)
        QDBusConnection::sessionBus().send(msg);
}

bool ScreenController::modeDisplay() const
{
    return m_modeDisplay;
}

int ScreenController::countScreenInStack(){
    return m_screenStack.count();
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

void ScreenController::onReceivedRequestDisplayMusic()
{
    if(m_screenStack.count() == 0){
        pushScreen(AppEnums::SCREEN_ID_MUSIC_PLAYER);
        return;
    }

    if(m_screenStack.top() == AppEnums::SCREEN_ID_VIDEO_PLAYER){
        m_screenStack.clear();
        pushScreen(AppEnums::SCREEN_ID_MUSIC_PLAYER);
    }
    setModeDisplay(true);
}

void ScreenController::onReceivedRequestDisplayVideo()
{
    if(m_screenStack.count() == 0){
        pushScreen(AppEnums::SCREEN_ID_VIDEO_PLAYER);
        
    }

    if(m_screenStack.top() != AppEnums::SCREEN_ID_VIDEO_PLAYER){
        m_screenStack.clear();

        pushScreen(AppEnums::SCREEN_ID_VIDEO_PLAYER);
    }
    setModeDisplay(true);
}

void ScreenController::setModeDisplay(bool modeDisplay)
{
    if (m_modeDisplay == modeDisplay)
        

    m_modeDisplay = modeDisplay;
    emit modeDisplayChanged();
}
