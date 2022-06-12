#ifndef MYCLASS_H
#define MYCLASS_H
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include <QObject>


class myClass : public QObject
{
    Q_OBJECT

public:
    explicit myClass(QObject *parent = nullptr){}
    void setEngine(QQmlApplicationEngine *engine){
        mEngine = engine;
    }
    Q_INVOKABLE void testFunc(){
        QObject *myObject = mEngine->rootObjects().at(0);
        QObject *rect = myObject->findChild<QObject *> ("myRect");

        qDebug() << rect->property("width");
    }

private:
    QQmlApplicationEngine *mEngine;
};

#endif // MYCLASS_H
