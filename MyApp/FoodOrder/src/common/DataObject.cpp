#include "DataObject.h"


DataObject::DataObject(QString name, QString pathImage, int inventory, bool isOrder, int price, int itemOrder, QObject *parent)
    :QObject{parent}
{
    m_name = name;
    m_pathImage = pathImage;
    m_inventory = inventory;
    m_itemOrdered = itemOrder;
    m_isOrdered = isOrder;
    m_price = price;
}

int DataObject::itemOdered() const
{
    return m_itemOrdered;
}

void DataObject::setItemOdered(int newItemOrdered)
{
    if (m_itemOrdered == newItemOrdered)
        return;
    m_itemOrdered = newItemOrdered;
    emit itemOderedChanged();
}

const QString &DataObject::name() const
{
    return m_name;
}

void DataObject::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

const QString &DataObject::pathImage() const
{
    return m_pathImage;
}

void DataObject::setPathImage(const QString &newPathImage)
{
    if (m_pathImage == newPathImage)
        return;
    m_pathImage = newPathImage;
    emit pathImageChanged();
}

int DataObject::inventory() const
{
    return m_inventory;
}

void DataObject::setInventory(int newInventory)
{
    if (m_inventory == newInventory)
        return;
    m_inventory = newInventory;
    emit inventoryChanged();
}

bool DataObject::isOrdered() const
{
    return m_isOrdered;
}

void DataObject::setIsOrdered(bool newIsOrdered)
{
    if (m_isOrdered == newIsOrdered)
        return;
    m_isOrdered = newIsOrdered;
    emit isOrderedChanged();
}


int DataObject::price() const
{
    return m_price;
}

void DataObject::setPrice(int newPrice)
{
    if (m_price == newPrice)
        return;
    m_price = newPrice;
    emit priceChanged();
}
