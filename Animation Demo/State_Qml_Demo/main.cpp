#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.load(QStringLiteral("qrc:/main.qml"));
    engine.load(QStringLiteral("qrc:/Change_Anchor_With_State_Qml.qml"));

    return app.exec();
}
