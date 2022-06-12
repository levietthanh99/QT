#ifndef HMICONTROLLER_H
#define HMICONTROLLER_H

#include <QObject>
#include <QDBusConnection>
#include <QDebug>

class HMIController : public QObject
{
    Q_OBJECT
public:
    explicit HMIController(QObject *parent = nullptr);

signals:

public slots:
    void onReceiveTestSignal(int para1, QString para2);

};

#endif // HMICONTROLLER_H
