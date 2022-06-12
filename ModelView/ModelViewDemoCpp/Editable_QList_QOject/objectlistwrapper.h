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
public:
    explicit ObjectListWrapper(QObject *parent = nullptr);
    bool initialize();

    Q_INVOKABLE void setNames(int index, const QString names);
    Q_INVOKABLE void setAge(int index, const int age);
    Q_INVOKABLE void setFavoriteColor(int index, const QString color);
    Q_INVOKABLE QList<QObject  *> persons();
    Q_INVOKABLE void addPerson();
private:
    void populateModelWithData();
    void resetModel();
    void printPersons();

    QList<QObject *> m_persons; // This should be QObject*, Person* is not working on qml
    QQmlApplicationEngine m_engine;
};

#endif // OBJECTLISTWRAPPER_H
