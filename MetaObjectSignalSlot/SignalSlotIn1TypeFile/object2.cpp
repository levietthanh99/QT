#include "object2.h"

Object2::Object2(QObject *parent)
    : QObject{parent}
{

}

void Object2::onSignalObject2()
{
    qDebug() << "onSignalObject2";
}
