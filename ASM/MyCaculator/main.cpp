#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <mycontroller.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    MyController test;
    test.initialize(&engine);

    engine.load(url);

    return app.exec();
}
