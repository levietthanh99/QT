#ifndef LOGHELPER_H
#define LOGHELPER_H

#include <QDebug>
#include <unistd.h>
//#include <sys/syscall.h>

#include <iostream>
#define LOG_INFO std::cout << "[Thread #" << syscall(SYS_gettid) MM "]" << Q_FUNC_INFO << " " << std::endl
#endif // LOGHELPER_H
