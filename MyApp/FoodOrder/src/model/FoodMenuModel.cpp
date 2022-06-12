#include "FoodMenuModel.h"

FoodMenuModel* FoodMenuModel::m_instance = nullptr;

FoodMenuModel::FoodMenuModel(QObject *parent)
    : QAbstractListModel{parent}
    , m_initialized(false)
{

}

FoodMenuModel *FoodMenuModel::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new FoodMenuModel();
    }
    return m_instance;
}

QVariant FoodMenuModel::data(const QModelIndex &index, int role) const
{
    if(index.row() <0 || index.row() >= rowCount())
                return QVariant();
    const DataObject* obj =  m_listModel.at(index.row());
    if(role == name){
        return obj->name();
    }
    if(role == pathImage){
        return obj->pathImage();
    }
    if(role == inventory){
        return obj->inventory();
    }
    if(role == itemOrder){
        return obj->itemOdered();
    }
    return QVariant();
}


int FoodMenuModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_listModel.count();
}

QHash<int, QByteArray> FoodMenuModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[name] = "name_";
    roles[pathImage] = "pathImage_";
    roles[inventory] = "inventory_";
    roles[itemOrder] = "itemOrder_";
    roles[isOrdered] = "isOrdered_";
    return roles;
}

void FoodMenuModel::initialize(QQmlContext *context)
{
    //    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        context->setContextProperty("FOOD_MENU_MODEL", this);
    }
}

void FoodMenuModel::addItem(QString name, QString pathImage, int inventory, int price)
{
    DataObject *obj = new DataObject(name,pathImage, inventory, false, price);
    beginInsertRows(QModelIndex(), rowCount(), rowCount() + 1);
    m_listModel.append(obj);
    endInsertRows();
}
