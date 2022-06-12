#include "myclass.h"

MyClass::MyClass(QObject *parent)
    : QObject{parent}
{
    // Conect signal với 1 signal khác của cùng 1 objet trong class
    connect(this, SIGNAL(signaltest()), this, SIGNAL(signaltest2()));

    // Conect signal với slot của cùng 1 object thuộc 1 class
    connect(this, SIGNAL(signaltest2()), this, SLOT(onSignaltest()));

    // Conect signal với slot giữa 2 object thuộc 2 class khác nhau
    connect(this, SIGNAL(signaltest()), &test2, SLOT(onSignalObject2()));
}

void MyClass::initMyClass()
{
    qDebug() << "initMyClass";
    emit signaltest();
}

void MyClass::onSignaltest()
{
    qDebug() << "onSignaltest";
}

