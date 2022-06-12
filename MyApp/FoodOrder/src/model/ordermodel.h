#ifndef ORDERMODEL_H
#define ORDERMODEL_H

#include <QObject>
#include <QQmlContext>
#include <QDebug>
#include "DataObject.h"
#include "FoodMenuModel.h"

class OrderModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> listModel READ listModel WRITE setListModel NOTIFY listModelChanged)
    explicit OrderModel(QObject *parent = nullptr);
public:
    //singelton pattern
    static OrderModel *getInstance();

    enum DataRoles {
        name = Qt::UserRole + 1,
        pathImage,
        inventory,
        itemOrder,
        isOrdered
    };



    Q_INVOKABLE void upDateList(){
        m_listModel.clear();
        QList<DataObject*> listMenu = FoodMenuModel::getInstance()->getList();
        for(int i = 0; i < listMenu.size(); i++){
            if(listMenu[i]->itemOdered() > 0){
                QString name = listMenu[i]->name();
                QString pathImage = listMenu[i]->pathImage();
                int itemOrder = listMenu[i]->itemOdered();
                int price = listMenu[i]->price();
                m_listModel.append(new DataObject(name,pathImage,0,true,price, itemOrder));
            }
        }
        emit listModelChanged();

    }

    void initialize(QQmlContext *context);
    void addItem(QString name, QString pathImage, int inventory);

    Q_INVOKABLE void printList(){
        for(int i = 0; i < m_listModel.size(); i++){

            qDebug() << ((DataObject *) m_listModel[i])->name();
            qDebug() << ((DataObject *) m_listModel[i])->pathImage();
            qDebug() << ((DataObject *) m_listModel[i])->inventory();
            qDebug() << ((DataObject *) m_listModel[i])->itemOdered();
            qDebug() << ((DataObject *) m_listModel[i])->isOrdered();
        }
    }


    const QList<QObject *> &listModel() const;
    void setListModel(const QList<QObject *> &newListModel);

signals:

    void listModelChanged();

private:
    static OrderModel *m_instance;
    bool m_initialized;
    QList<QObject*> m_listModel;

};

#endif // ORDERMODEL_H
