#include "mytimer.h"

MyTimer::MyTimer(QObject *parent)
    : QObject{parent}

{
    qDebug() << Q_FUNC_INFO << this;
}

MyTimer::~MyTimer()
{
    qDebug() << Q_FUNC_INFO;
}

void MyTimer::start()
{
    qDebug() << Q_FUNC_INFO << this;
    if(m_engine != nullptr && !m_engine->rootObjects().isEmpty()){
        QObject *rootObj = m_engine->rootObjects()[0];

        QObject *rect = rootObj->findChild<QObject *> ("RectObj");
        if(rect != nullptr){
            qDebug() << Q_FUNC_INFO << rect;
            qDebug() << rect->property("width");
            qDebug() << rect->property("rect_value");
            rect->setProperty("width", 100);
            QMetaObject::invokeMethod(rect,"changeColor");
        }
    }
}

void MyTimer::setEngine(QQmlApplicationEngine *engine)
{
    m_engine = engine;
}

