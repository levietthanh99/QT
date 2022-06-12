#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QStringList dataList;
    dataList.append("Item 1");
    dataList.append("Item 2");
    dataList.append("Item 3");
    dataList.append("Item 4");

    engine.rootContext()->setContextProperty(
                "myModel", QVariant::fromValue(dataList));
//    engine.rootContext()->setContextProperty(
//                "myModel", dataList);


    engine.load(url);

    return app.exec();
}
