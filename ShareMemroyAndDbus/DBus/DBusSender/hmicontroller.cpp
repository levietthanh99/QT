#include "hmicontroller.h"

HMIController::HMIController(QObject *parent)
    : QObject{parent}
{}
// phat ra signal cho tat ca cac app khac co the nhan duoc
void HMIController::broadcastDbusSignal()
{

    //1. Create a dbus signal
    QDBusMessage msg = QDBusMessage::createSignal(
                "object/path",          //object path
                "service.interface",    // service interface
                "notifyTestSignal");    // method name

    //2. append input argument
    msg << 1 << "Test message";

    //3. broadcast signal (using session or sytem bus)
    QDBusConnection::sessionBus().send(msg);
    qDebug() << Q_FUNC_INFO;
}

// goi 1 method tu app khac voi object path va service interface la cua app khac do.
void HMIController::callDbusMethod()
{
    // 1. create a dbus method call
    QDBusMessage msg = QDBusMessage::createMethodCall(
                "service name",          //service name
                "object/path",          //object path
                "service.interface",    // service interface
                "notifyTestSignal");    // method name
    // 2. append input arguments
    msg << 2 << "Test call method";

    // 3. call method (using call or asyncCall)
    QDBusMessage response = QDBusConnection::sessionBus().call(msg);
    // 4.check return value
    if(!response.errorMessage().isEmpty()){
        qDebug() << "response error: " << response.errorMessage();
    }else{
        qDebug() << "call method successfully " << response.arguments().at(0).toString();
    }
}
