#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString favoriteColor READ favoriteColor WRITE setFavoriteColor NOTIFY favoriteColorChanged)
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
public:
    Person(QString name, QString favoriteColor, int age, QObject *parent = nullptr);

    const QString &name() const;
    void setName(const QString &newName);

    const QString &favoriteColor() const;
    void setFavoriteColor(const QString &newFavoriteColor);

    int age() const;
    void setAge(int newAge);

signals:
    void nameChanged();
    void favoriteColorChanged();
    void ageChanged();

private:
    QString m_name;
    QString m_favoriteColor;
    int m_age;

};

#endif // PERSON_H
