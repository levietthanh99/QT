#ifndef ANIMALMODEL_H
#define ANIMALMODEL_H

#include <QAbstractListModel>

class animal{
public:
    animal(const QString &name, const QString &size){
        m_name = name;
        m_size = size;
    }
    QString getName() const{
        return m_name;
    }
    QString getSize() const{
        return m_size;
    }
private:
    QString m_name;
    QString m_size;
};

class AnimalModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AnimalModel(QObject *parent = nullptr);

    enum AnimalRoles {
        NameRole = Qt::UserRole + 1,
        SizeRole
    };
    void addAnimal(const animal &ani);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    Q_INVOKABLE void addAnimal1(const QString name, const QString size);

protected:
    QHash<int, QByteArray> roleNames() const;



private:
    QList<animal> m_listAnimal;

};

#endif // ANIMALMODEL_H
