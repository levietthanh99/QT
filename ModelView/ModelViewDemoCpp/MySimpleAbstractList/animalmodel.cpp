#include "animalmodel.h"

AnimalModel::AnimalModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

void AnimalModel::addAnimal(const animal &ani)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_listAnimal << ani;
    endInsertRows();

}

int AnimalModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_listAnimal.count();
}

QVariant AnimalModel::data(const QModelIndex &index, int role) const
{
//    if(index.row() < 0 || index.row() >= m_listAnimal.count()){
//        return QVariant();
//    }
    const animal &myAnimal = m_listAnimal[index.row()];
    if(role == NameRole)
        return myAnimal.getName();
    if(role == SizeRole)
        return myAnimal.getSize();
    return QVariant();
}

void AnimalModel::addAnimal1(const QString name, const QString size)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    animal ani(name, size);
    m_listAnimal << ani;
    endInsertRows();
}

QHash<int, QByteArray> AnimalModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[SizeRole] = "size";
    return roles;
}
