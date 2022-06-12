#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <songmodel.h>
#include <QDir>
#include <QtCore>

int main(int argc, char *argv[])
{
    SongModel model;
    QDir directory(Song::pathFolder);
    QStringList listSongs = directory.entryList(QStringList() << "*mp3" << "*MP3", QDir::Files);

    foreach(QString filename, listSongs){
        model.addSong(Song(filename));
    }
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.rootContext()->setContextProperty("SongModel", &model);
    engine.load(url);
    if(engine.rootObjects().isEmpty()){
        return -1;
    }
    return app.exec();

}
