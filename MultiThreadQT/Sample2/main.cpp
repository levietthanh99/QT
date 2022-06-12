#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "hmicontroller.h"
#include "threadsample2.h"
#include "loghelper.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QStringLiteral("qrc:/main.qml"));

    LOG_INFO;
    HmiController controller;
    ThreadSample2 sample;

    QObject::connect(&sample, &ThreadSample2::testSignal,
                     &controller, &HmiController::onTestChanged);

    sample.start();


    return app.exec();

}
