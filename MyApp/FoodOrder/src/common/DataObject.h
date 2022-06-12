#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <QObject>

class DataObject :public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString pathImage READ pathImage WRITE setPathImage NOTIFY pathImageChanged)
    Q_PROPERTY(int inventory READ inventory WRITE setInventory NOTIFY inventoryChanged)
    Q_PROPERTY(int itemOrdered READ itemOdered WRITE setItemOdered NOTIFY itemOderedChanged)
    Q_PROPERTY(bool isOrdered READ isOrdered WRITE setIsOrdered NOTIFY isOrderedChanged)
    Q_PROPERTY(int price READ price WRITE setPrice NOTIFY priceChanged)
public:
    DataObject(QString name, QString pathImage, int inventory, bool isOrder, int price, int itemOrder = 0, QObject *parent = nullptr);

    //    QString getName(){
    //        return m_name;
    //    }

    //    QString getPathImage(){
    //        return m_pathImage;
    //    }

    //    int getInventory(){
    //        return m_inventory;
    //    }

    int itemOdered() const;
    void setItemOdered(int newItemOrdered);

    const QString &name() const;
    void setName(const QString &newName);

    const QString &pathImage() const;
    void setPathImage(const QString &newPathImage);

    int inventory() const;
    void setInventory(int newInventory);

    bool isOrdered() const;
    void setIsOrdered(bool newIsOrdered);

    int price() const;
    void setPrice(int newPrice);

signals:
    void itemOderedChanged();

    void nameChanged();

    void pathImageChanged();

    void inventoryChanged();

    void isOrderedChanged();

    void priceChanged();

private:
    QString m_name;
    QString m_pathImage;
    int m_inventory;
    int m_itemOrdered;
    bool m_isOrdered;
    int m_price;
};


#endif // DATAOBJECT_H
