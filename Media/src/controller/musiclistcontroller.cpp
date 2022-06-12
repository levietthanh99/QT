#include "musiclistcontroller.h"
#include "loghelper.h"

MusicListController* MusicListController::m_instance = nullptr;
MusicListModel MusicListController::m_listModel;

MusicListController::MusicListController(QObject *parent)
    : QObject{parent}
    , m_initialized(false)
{
//    LOG_INFO;
    loadListSong();
}

MusicListController::~MusicListController()
{
//    LOG_INFO;
}

MusicListController *MusicListController::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new MusicListController();
    }

    return m_instance;
}

void MusicListController::initialize(QQmlContext *context)
{
//    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        context->setContextProperty("MLIST_CTRL", this);
        context->setContextProperty("MLIST_MODEL", &m_listModel);
    }
}

void MusicListController::loadListSong()
{
    //load list song
    QStringList path = QStandardPaths::standardLocations(QStandardPaths::MusicLocation);
    if(path.count() >> 0){
        qDebug() << Q_FUNC_INFO << path.at(0);
        MusicListModel::m_pathFolder = path.at(0);
        QDir dir(path.at(0));
        QStringList list = dir.entryList(QStringList() << "*.mp3", QDir::Files);
        m_listModel.setListSong(list);
        foreach(QString item, m_listModel.listSong()){
            qDebug() << Q_FUNC_INFO << item;
        }
    }else {
        qDebug() << "Load list song fail";
    }

}
