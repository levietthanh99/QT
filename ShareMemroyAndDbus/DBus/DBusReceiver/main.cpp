#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <hmicontroller.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    HMIController myReceiver;

    return app.exec();
}
