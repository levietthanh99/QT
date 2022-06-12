#ifndef OBJECTLISTWRAPPER_H
#define OBJECTLISTWRAPPER_H
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <person.h>
#include <QDebug>

class ObjectListWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject *> myListPerson READ myListPerson
               WRITE setMyListPerson NOTIFY myListPersonChanged)
public:
    explicit ObjectListWrapper(QObject *parent = nullptr);
    bool initialize();

    Q_INVOKABLE void setNames(int index, const QString names);
    Q_INVOKABLE void setAge(int index, const int age);
    Q_INVOKABLE void setFavoriteColor(int index, const QString color);
    Q_INVOKABLE QList<QObject  *> persons();
    Q_INVOKABLE void addPerson();
    const QList<QObject *> &myListPerson() const;
    void setMyListPerson(const QList<QObject *> &newMyListPerson);
signals:
    void myListPersonChanged();
private:
    void populateModelWithData();
    void printPersons();
// This should be QObject*, Person* is not working on qml
    QList<QObject *> m_persons;
    QQmlApplicationEngine m_engine;
    QList<QObject *> m_myListPerson;
};
#endif // OBJECTLISTWRAPPER_H
