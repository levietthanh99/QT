#include "threadsample1.h"
#include "loghelper.h"

ThreadSample1::ThreadSample1(QObject *parent)
    : QObject{parent}
{
    LOG_INFO;
}

void ThreadSample1::testFunc(int param)
{
    LOG_INFO << param;
    QThread::sleep(5);
}
