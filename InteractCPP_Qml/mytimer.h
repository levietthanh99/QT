#ifndef MYTIMER_H
#define MYTIMER_H

#include <QObject>
#include <QDebug>
#include <QQmlApplicationEngine>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    explicit MyTimer(QObject *parent = nullptr);
    ~MyTimer();
    Q_INVOKABLE void start();

    void setEngine(QQmlApplicationEngine *engine);

private:
    QQmlApplicationEngine *m_engine;
};

#endif // MYTIMER_H
