#include <QGuiApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QFile>
#include <appengine.h>
#include <iostream>


int g_volume;
QString g_language;

void testWriteToJson(QString language, int volume);
void testReadFromJson();


int main(int argc, char *argv[])
{
    testReadFromJson();
    QGuiApplication app(argc, argv);
    AppEngine::getInstance()->initialize(&app);
    return app.exec();
}

void testWriteToJson(QString language, int volume)
{

    QJsonObject jsObj;
    jsObj["language"] = language;
    jsObj["volume"] = volume;

    QJsonDocument jsDoc(jsObj);
    QFile file(QString(PROJECT_PATH) + "config.json");
    if(file.open(QFile::WriteOnly))
    {
        file.write(jsDoc.toJson());
        file.flush();
        file.close();
    }
}

void testReadFromJson()
{
    QFile file(QString(PROJECT_PATH) + "config.json");
    if(file.open(QFile::ReadOnly))
    {
        QByteArray ba = file.readAll();
        QJsonDocument jsDoc = QJsonDocument::fromJson(ba);

        QJsonObject jsObj = jsDoc.object();
        g_volume = jsObj["volume"].toInt();
        g_language = jsObj["language"].toString();

        file.close();
    }
}
