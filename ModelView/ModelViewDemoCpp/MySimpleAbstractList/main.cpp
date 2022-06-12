#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <animalmodel.h>
#include <mediamodel.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/mainMedia.qml"));

//    AnimalModel myModel;
//    myModel.addAnimal(animal("cho", "to"));
//    myModel.addAnimal(animal("meo", "nho"));
//    myModel.addAnimal(animal("dog", "cat"));
//    engine.rootContext()->setContextProperty("myModel", &myModel);

    MediaModel model;
    engine.rootContext()->setContextProperty("MediaModel", &model);

    model.loadMediaList();
    engine.load(url);

    return app.exec();
}
