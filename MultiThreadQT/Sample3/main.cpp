#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "hmicontroller.h"
#include "loghelper.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    LOG_INFO;
    HmiController controller;
    controller.initialize(engine.rootContext());

    engine.load(url);

    return app.exec();
}
