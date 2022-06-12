#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


#include <mytranslation.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    MyTranslation myTranslation;

    engine.rootContext()->setContextProperty(
                "myTranslation", &myTranslation);
    engine.load(QStringLiteral("qrc:/main.qml"));

    QString abc = QString(PROJECT_PATH) + "ahihi";

    qDebug() << abc;

    return app.exec();
}
