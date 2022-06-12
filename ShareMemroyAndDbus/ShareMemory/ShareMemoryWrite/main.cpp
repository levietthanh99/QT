#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <hmicontroller.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    HMIController hmiController;

    engine.rootContext()->setContextProperty("HMI_CTRL", &hmiController);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
