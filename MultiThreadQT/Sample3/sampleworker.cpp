#include "sampleworker.h"
#include "loghelper.h"

SampleWorker::SampleWorker(QObject *parent)
    : QObject{parent}
{
    LOG_INFO;
}

void SampleWorker::doBgTask(int taskId)
{
    LOG_INFO << "==> start: " << taskId;

    QThread::msleep(2000);

    emit bgTaskDone(taskId);

    LOG_INFO << "==> end: " << taskId;

}
