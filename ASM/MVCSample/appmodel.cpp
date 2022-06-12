#include "appmodel.h"

AppModel::AppModel(QObject *parent)
    : QObject{parent}
    ,m_data(0)
{
    qDebug() << Q_FUNC_INFO;
}

int AppModel::data() const
{
    qDebug() << Q_FUNC_INFO;
    return m_data;
}

void AppModel::setData(int data)
{
    if(m_data != data){
        qDebug() << Q_FUNC_INFO;
        m_data = data;
        emit dataChanged();
    }
}
