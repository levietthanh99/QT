#ifndef HMICONTROLLER_H
#define HMICONTROLLER_H

#include <QObject>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QDebug>

class HMIController : public QObject
{
    Q_OBJECT
public:
    explicit HMIController(QObject *parent = nullptr);

    Q_INVOKABLE void broadcastDbusSignal();
    Q_INVOKABLE void callDbusMethod();

};

#endif // HMICONTROLLER_H
