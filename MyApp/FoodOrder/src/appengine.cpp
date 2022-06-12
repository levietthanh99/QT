#include "appengine.h"
#include "screencontroller.h"
#include "translatorcontroller.h"
#include "appdefines.h"
#include "loghelper.h"
#include "FoodMenuModel.h"
#include "ordermodel.h"

#include <QDebug>

AppEngine* AppEngine::m_instance = nullptr;

AppEngine::AppEngine(QObject *parent)
    : QObject{parent}
    , m_initialized(false)
    , m_app(nullptr)
{
//    LOG_INFO;
}

AppEngine::~AppEngine()
{
//    LOG_INFO;
    m_app = nullptr;
}

AppEngine *AppEngine::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new AppEngine();
    }

    return m_instance;
}

void AppEngine::initialize(QGuiApplication *app)
{
//    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        m_app = app;
        // init app
        registerQmlObjects();
        createControllers();
        initControllers();
        initScreens();

        QString val;
        QFile file;
        file.setFileName("F:\\Onedirve_j2\\OneDrive - www.microsoft365.me\\QT\\MyApp\\FoodOrder\\data.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();
        QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject obj = d.object();
        QStringList keys = obj.keys();
        for(int i = 0; i <keys.size(); i++ ){
             QJsonObject subObj = obj.value(QString(keys[i])).toObject();
             QString name = keys[i];
             QString pathImage = subObj.value(QString("pathImage")).toString();
             int inventory = subObj.value(QString("inventory")).toInt();
             int price = subObj.value(QString("price")).toInt();


             FoodMenuModel::getInstance()->addItem(name,pathImage,inventory,price);
        }
//        FoodMenuModel::getInstance()->printList();
    }
}

void AppEngine::registerQmlObjects()
{
//    LOG_INFO << " => Start";

    qmlRegisterType<AppEnums>("AppEnums", 1, 0, "AppEnums");

//    LOG_INFO << " => End";
}

void AppEngine::createControllers()
{
    //    LOG_INFO << " => Start";
    ScreenController::getInstance();
    //    LOG_INFO << " => End";
}

void AppEngine::initControllers()
{
    //    LOG_INFO << " => Start";
    ScreenController::getInstance()->initialize(m_engine.rootContext());
    TranslatorController::getInstance()->initialize(m_engine.rootContext());
    FoodMenuModel::getInstance()->initialize(m_engine.rootContext());
    OrderModel::getInstance()->initialize(m_engine.rootContext());
    //    LOG_INFO << " => End";
}

void AppEngine::initScreens()
{
    //    LOG_INFO << " => Start";

    ScreenController::getInstance()->initializeScreen(&m_engine);

    //    LOG_INFO << " => End";
}
