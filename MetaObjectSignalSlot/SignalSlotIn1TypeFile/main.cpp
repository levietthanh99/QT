#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "myclass.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    MyClass test;

    Object2 test2;

    // Cú pháp conect kiểu mới, Khác nhau khi signal và slot có tham số
    //(Sinal phải có số lượng tham số lớn hơn hoặc bằng số lượng tham số của slot)
    // Khi sử dụng cách mới này thì nó sẽ kiểm tra kết nối và kiểu dữ liệu truyền vào.
    QObject::connect(&test, &MyClass::signaltest, &test,  &MyClass::onSignaltest);

    test.initMyClass();

    return app.exec();
}
