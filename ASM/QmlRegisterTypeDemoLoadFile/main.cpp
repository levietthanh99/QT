#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <mydata.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    qmlRegisterType<MyData>("Custom.Library",1,0,"MyData");
    engine.load(url);

    return app.exec();
}
