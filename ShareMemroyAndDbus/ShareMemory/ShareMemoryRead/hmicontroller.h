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

    Q_INVOKABLE bool writeShareMemory(); //not use in this project
    Q_INVOKABLE void readShareMemory();
private:
    QSharedMemory m_shareMemWrite; //not use in this project
    QSharedMemory m_shareMemRead;
    int m_testCount;
};

#endif // HMICONTROLLER_H
