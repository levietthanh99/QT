#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <loghelper.h>
#include <threadsample1.h>
#include <QtConcurrent>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    LOG_INFO;
    ThreadSample1 test;
    QThreadPool pool;
    pool.setMaxThreadCount(4);

    for(int i = 0; i < 20; i++){
         QtConcurrent::run(&pool, &test, &ThreadSample1::testFunc, i);
    }


    return 0;
}
