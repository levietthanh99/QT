#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include <QDebug>



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    QDir myDirect("E:/HOC_TAP/QT/List_Model_Cpp/TestByMine/Image");
    QStringList myList = myDirect.entryList(QStringList() << "*png" << "*jpg");

    foreach (QString fileName, myList){
        qDebug() << fileName;
    }

    return 0;

//    return app.exec();
}
