#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QtDebug>

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);
    Q_INVOKABLE void initTest();

signals:
    void signaltest();


};

#endif // MYCLASS_H
