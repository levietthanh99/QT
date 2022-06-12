#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QtDebug>
#include "object2.h"

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);

    void initMyClass();
signals:
    void signaltest();
    void signaltest2();
public slots:
        void onSignaltest();

private:
    Object2 test2;
};

#endif // MYCLASS_H
