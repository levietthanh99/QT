#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <mycolor.h>
#include <mytimer.h>
#include <QQmlEngine>



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<MyColor>("customcomponents",1,0, "Fcolor");
    //qmlRegisterUncreatableType<MyColor>("customcomponents",1,0, "Fcolor", "Cannot create instance");


    MyTimer *testTimer  = new MyTimer();
    qDebug() << "testTimer: " << testTimer;
    testTimer->setEngine(&engine);

    engine.rootContext()->setContextProperty("ABCXX", testTimer);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
