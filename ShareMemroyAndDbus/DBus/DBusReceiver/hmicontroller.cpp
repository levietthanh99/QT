#include "hmicontroller.h"

HMIController::HMIController(QObject *parent)
    : QObject{parent}
{

    // kết nối tới signal mà app khác đã broadcast Signal với
    // service interface và method name (phải giống với bên phát ra signal)
    QDBusConnection::sessionBus().connect("",                    // service name: could be empty
                                          "object/path",        //object path: could be empty
                                          "service.interface",  //service interface
                                          "notifyTestSignal",    //method name
                                          this, SLOT(onReceiveTestSignal(int, QString)));
    qDebug() << Q_FUNC_INFO;
}

void HMIController::onReceiveTestSignal(int para1, QString para2)
{
    qDebug() << para1 << "   " << para2;
}


