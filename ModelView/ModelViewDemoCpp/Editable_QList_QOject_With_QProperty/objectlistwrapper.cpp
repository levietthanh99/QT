#include "objectlistwrapper.h"
ObjectListWrapper::ObjectListWrapper(QObject *parent)
    : QObject{parent}
{
    populateModelWithData();
}
bool ObjectListWrapper::initialize()
{
    m_engine.rootContext()->setContextProperty("Wrapper", this);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    m_engine.load(url);
    if(m_engine.rootObjects().isEmpty())
        return false;

    return true;
}
void ObjectListWrapper::setNames(int index, const QString names)
{
    if(index >= m_persons.size())
        return;
    Person *person = static_cast<Person *>(m_persons.at(index));
    if(names!= person->name()){
        person->setName(names);
    }
    printPersons();
}
void ObjectListWrapper::setAge(int index, const int age)
{
    if(index >= m_persons.size())
        return;
    Person *person = static_cast<Person *>(m_persons.at(index));
    if(age!= person->age()){
        person->setAge(age);
    }
    printPersons();
}
void ObjectListWrapper::setFavoriteColor(int index, const QString color)
{
    if(index >= m_persons.size())
        return;
    Person *person = static_cast<Person *>(m_persons.at(index));
    if(color!= person->favoriteColor()){
        person->setFavoriteColor(color);
    }
    printPersons();
}
QList<QObject *> ObjectListWrapper::persons()
{
    return m_persons;
}
void ObjectListWrapper::addPerson()
{
    m_persons.append(new Person("New person", "green", 32,this));
    emit myListPersonChanged();
}
void ObjectListWrapper::populateModelWithData()
{
    m_persons.append(new Person("Thanh","red",24,this));
    m_persons.append(new Person("Minh","blue",22,this));
    m_persons.append(new Person("Bach","green",21,this));
}
void ObjectListWrapper::printPersons()
{
    qDebug() << "print out list person";
    for(int i = 0; i < m_persons.size();i++){
        Person *person = static_cast<Person *>(m_persons.at(i));
        qDebug() << person->name();
    }
}
const QList<QObject *> &ObjectListWrapper::myListPerson() const
{
    return m_persons;
}
void ObjectListWrapper::setMyListPerson(const QList<QObject *> &newMyListPerson)
{
    if (m_persons == newMyListPerson)
        return;
    m_persons = newMyListPerson;
    emit myListPersonChanged();
}
