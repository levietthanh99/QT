#include "hmicontroller.h"
#include "loghelper.h"

HmiController::HmiController(QObject *parent)
    : QObject{parent}
    , m_initialized(false)
    , m_taskCount(0)
    , m_thread(new QThread())
{
    LOG_INFO;
}

HmiController::~HmiController()
{
    LOG_INFO;
}

void HmiController::initialize(QQmlContext *ctx)
{
    LOG_INFO << m_initialized;
    if(!m_initialized){
        m_initialized = true;

        //set context property
        if(ctx != nullptr){
            ctx->setContextProperty("HMI_CTRL", this);
        }

        //connect signal slot
        QObject::connect(m_thread, SIGNAL(finished()), m_thread, SLOT(deleteLater()));
        QObject::connect(this, &HmiController::requestBgTask, &m_worker, &SampleWorker::doBgTask);
        QObject::connect(&m_worker, &SampleWorker::bgTaskDone, this, &HmiController::onBgTaskDone);

        // move work to thread
        m_worker.moveToThread(m_thread);

        //start thread
        m_thread->start();

    }
}

void HmiController::doTask()
{
    LOG_INFO << m_initialized << ", " << m_taskCount;
    if(m_initialized){
        emit requestBgTask(m_taskCount);
        m_taskCount++;
    }

}

void HmiController::onBgTaskDone(int taskId)
{
    LOG_INFO << taskId;

}
