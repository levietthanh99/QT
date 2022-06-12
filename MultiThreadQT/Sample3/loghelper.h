#ifndef LOGHELPER_H
#define LOGHELPER_H

#include <QDebug>
#include <QThread>
#include <unistd.h>

#define LOG_INFO qDebug().nospace() << "[Thread #" << QThread::currentThreadId () << "]" << Q_FUNC_INFO << " "

#endif // LOGHELPER_H
