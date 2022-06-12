#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QtDebug>
#include <appmodel.h>
#include <QQmlEngine>
#include <QQmlContext>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

    void initialize(QQmlEngine *engine);

    Q_INVOKABLE void changeData(int data);



signals:

private:
    AppModel m_model;
    bool m_initialize;

};

#endif // CONTROLLER_H
