#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
    ,m_initialize(false)
{
    qDebug() << Q_FUNC_INFO;
}

void Controller::initialize(QQmlEngine *engine)
{
    qDebug() << Q_FUNC_INFO << m_initialize;
    if(!m_initialize){
        m_initialize = true;

        engine->rootContext()->setContextProperty("APP_CTR", this);
        engine->rootContext()->setContextProperty("APP_MODEL", &m_model);

    }
}

void Controller::changeData(int data)
{
    qDebug() << Q_FUNC_INFO;


    // Update model
    m_model.setData(data);
}
