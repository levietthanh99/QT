#include "myclass.h"

MyClass::MyClass(QObject *parent)
    : QObject{parent}
{

}

void MyClass::initTest()
{
    qDebug() << "initTest";
    emit signaltest();
}


