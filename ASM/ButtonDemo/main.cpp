#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include <QObject>
//#include <myclass.h>

class myClass1 : public QObject
{
    Q_OBJECT

public:
    void setEngine(QQmlApplicationEngine *engine){
        mEngine = engine;
    }
    Q_INVOKABLE void testFunc(){
        QObject *myObject = mEngine->rootObjects().at(0);
        QObject *rect = myObject->findChild<QObject *> ("myRect");

        qDebug() << rect->property("width");

        rect->setProperty("width", QVariant(20));
    }

private:
    QQmlApplicationEngine *mEngine;
};


namespace MyNamespace
{
    Q_NAMESPACE         // required for meta object creation
    enum EnStyle {
        STYLE_RADIAL = 11,
        STYLE_ENVELOPE,
        STYLE_FILLED
    };
    Q_ENUM_NS(EnStyle)  // register the enum in meta object data
}

#include "main.moc" // Include the generated code
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));


    myClass1 test;
    test.setEngine(&engine);

    qmlRegisterUncreatableMetaObject(
      MyNamespace::staticMetaObject, // meta object created by Q_NAMESPACE macro
      "my.namespace",                // import statement (can be any string)
      1, 0,                          // major and minor version of the import
      "MyNamespace",                 // name in QML (does not have to match C++ name)
      "Error: only enums"            // error in case someone tries to create a MyNamespace object
    );

    engine.rootContext()->setContextProperty("test",&test);


    engine.load(url);



    return app.exec();
}
