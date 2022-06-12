#ifndef HMICONTROLLER_H
#define HMICONTROLLER_H

#include <QObject>
#include <QSharedMemory>
#include <QDebug>
#include <QThread>

struct SHARE_INFO {
    int id;
    char message[1000];
};

class HMIController : public QObject
{
    Q_OBJECT
public:
    explicit HMIController(QObject *parent = nullptr);

    Q_INVOKABLE bool writeShareMemory();
    Q_INVOKABLE void readShareMemory(); //not use in this project
private:
    QSharedMemory m_shareMemWrite;
    QSharedMemory m_shareMemRead; //not use in this project
    int m_testCount;
};

#endif // HMICONTROLLER_H
