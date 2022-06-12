#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <myclass.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    qmlRegisterType<MyClass>("myCustom",1,0, "MyClass");
    engine.load(url);

    return app.exec();
}
