#include "objectlistwrapper.h"
ObjectListWrapper::ObjectListWrapper(QObject *parent)
    : QObject{parent}
{
    populateModelWithData();
}
bool ObjectListWrapper::initialize()
{
    m_engine.rootContext()->setContextProperty("Wrapper", this);
    resetModel();
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
        resetModel();
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
        resetModel();
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
        resetModel();
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
    resetModel();
}
void ObjectListWrapper::populateModelWithData()
{
    m_persons.append(new Person("Thanh","red",24,this));
    m_persons.append(new Person("Minh","blue",22,this));
    m_persons.append(new Person("Bach","green",21,this));
}
void ObjectListWrapper::resetModel()
{
    m_engine.rootContext()->setContextProperty("myModel",QVariant::fromValue(persons()));
}
void ObjectListWrapper::printPersons()
{
    qDebug() << "print out list person";
}
