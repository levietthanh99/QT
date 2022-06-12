#ifndef FOODMENMODEL_H
#define FOODMENMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QQmlContext>
#include <QDebug>
#include <DataObject.h>

class FoodMenuModel : public QAbstractListModel
{
    Q_OBJECT
    explicit FoodMenuModel(QObject *parent = nullptr);
public:
    //singelton pattern
    static FoodMenuModel *getInstance();

    enum DataRoles {
        name = Qt::UserRole + 1,
        pathImage,
        inventory,
        itemOrder,
        isOrdered
    };

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int,QByteArray> roleNames() const;


    Q_INVOKABLE void updateData(bool check,int idx, int val){

        m_listModel.at(idx)->setItemOdered(val);
        if(val > 0){
            m_listModel.at(idx)->setIsOrdered(true);
        }else {
            m_listModel.at(idx)->setIsOrdered(false);
        }
//
        if(check == true){
            m_listModel.at(idx)->setInventory(m_listModel.at(idx)->inventory() - 1);
        }else {
            m_listModel.at(idx)->setInventory(m_listModel.at(idx)->inventory() + 1);
        }
        QModelIndex topLeft = createIndex(0,0);
        QModelIndex bottomRight = createIndex( rowCount() ,0);
        emit dataChanged( topLeft, bottomRight );


    }

    void initialize(QQmlContext *context);
    void addItem(QString name, QString pathImage, int inventory, int price);
    Q_INVOKABLE void printList(){
        for(int i = 0; i < m_listModel.size(); i++){
//            qDebug() << m_listModel[i]->name();
//            qDebug() << m_listModel[i]->pathImage();
//            qDebug() << m_listModel[i]->inventory();
//            qDebug() << m_listModel[i]->itemOdered();
            qDebug() << m_listModel[i]->isOrdered();
        }
    }

    Q_INVOKABLE bool isTakeOrder(){
        for(int i = 0; i < m_listModel.size(); i++){
            if(m_listModel[i]->isOrdered() == true){
                return true;
            }
        }
        return false;
    }

    QList<DataObject*> getList(){
        return m_listModel;
    }




signals:

private:
    static FoodMenuModel *m_instance;
    bool m_initialized;
    QList<DataObject*> m_listModel;

};

#endif // FOODMENMODEL_H
