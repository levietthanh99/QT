#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <person.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QList<QObject *> personList;
    personList.append(new Person("Thanh","red",24));
    personList.append(new Person("Minh","blue",22));
    personList.append(new Person("Bach","green",21));
    personList.append(new Person("Vinh","pink",22));
    personList.append(new Person("Thuan","yellow",20));
    personList.append(new Person("Hai","gray",14));
    personList.append(new Person("Quang","cyan",34));

    engine.rootContext()->setContextProperty
            ("myModel",QVariant::fromValue(personList));

    engine.load(url);

    return app.exec();
}
