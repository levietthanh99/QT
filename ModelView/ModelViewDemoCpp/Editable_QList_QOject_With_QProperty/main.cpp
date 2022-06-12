#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <objectlistwrapper.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ObjectListWrapper wrapper;

    if(!wrapper.initialize()){
        return -1;
    }

    return app.exec();
}
