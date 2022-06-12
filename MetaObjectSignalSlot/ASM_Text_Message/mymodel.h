#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>

class MyModel : public QObject
{
    Q_OBJECT
public:
    explicit MyModel(QObject *parent = nullptr);
    Q_INVOKABLE void addTextToList(QString txt);
    bool initialize();
signals:
    void editList();


public slots:
    void onEditList();

private:
    QStringList m_list;
    QQmlApplicationEngine m_engine;
//    void onEditList();
};

#endif // MYMODEL_H
