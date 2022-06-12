#include "ordermodel.h"

OrderModel* OrderModel::m_instance = nullptr;

OrderModel::OrderModel(QObject *parent)
    : QObject{parent}
    , m_initialized(false)
{

}

OrderModel *OrderModel::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new OrderModel();
    }
    return m_instance;
}

void OrderModel::initialize(QQmlContext *context)
{
    //    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        context->setContextProperty("ORDER_CTRL", this);
        context->setContextProperty("ORDER_MODEL", QVariant::fromValue(m_listModel));
    }
}

void OrderModel::addItem(QString name, QString pathImage, int inventory)
{

}

const QList<QObject *> &OrderModel::listModel() const
{
    return m_listModel;
}

void OrderModel::setListModel(const QList<QObject *> &newListModel)
{
    if (m_listModel == newListModel)
        return;
    m_listModel = newListModel;
    emit listModelChanged();
}
