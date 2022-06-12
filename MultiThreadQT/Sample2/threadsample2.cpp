#include "threadsample2.h"
#include "loghelper.h"

ThreadSample2::ThreadSample2(QObject *parent)
    : QThread{parent}
{

}

void ThreadSample2::run()
{
    LOG_INFO << "==> start";
    QThread::sleep(2);

    emit testSignal();
    QThread::sleep(5);
    LOG_INFO << "==> end";

}
