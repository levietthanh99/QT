#include "person.h"
Person::Person(QString name, QString favoriteColor, int age, QObject *parent)
    : QObject{parent},m_name(name),m_favoriteColor(favoriteColor),m_age(age)
{}
const QString &Person::name() const
{
    return m_name;
}
void Person::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}
const QString &Person::favoriteColor() const
{
    return m_favoriteColor;
}
void Person::setFavoriteColor(const QString &newFavoriteColor)
{
    if (m_favoriteColor == newFavoriteColor)
        return;
    m_favoriteColor = newFavoriteColor;
    emit favoriteColorChanged();
}
int Person::age() const
{
    return m_age;
}
void Person::setAge(int newAge)
{
    if (m_age == newAge)
        return;
    m_age = newAge;
    emit ageChanged();
}
