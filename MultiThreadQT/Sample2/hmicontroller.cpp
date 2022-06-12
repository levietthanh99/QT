#include "hmicontroller.h"
#include "loghelper.h"

HmiController::HmiController(QObject *parent)
    : QObject{parent}
{
    LOG_INFO;
}

void HmiController::onTestChanged()
{
    LOG_INFO;
}
