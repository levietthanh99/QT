#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
//    engine.load(QStringLiteral("qrc:/main.qml"));
    engine.load(QStringLiteral("qrc:/DemoColumnRepeater.qml"));

    return app.exec();
}
