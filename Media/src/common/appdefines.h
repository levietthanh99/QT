#ifndef APPDEFINES_H
#define APPDEFINES_H

#include <QObject>
#include <QMap>

#define MAIN_QML    "qrc:/qml/main.qml"

class AppEnums: public QObject
{
    Q_OBJECT

    Q_ENUMS(SCREEN_ID)

public:
    enum SCREEN_ID: int
    {
        //MUSIC SCREENS
        SCREEN_ID_MUSIC_PLAYER,
        SCREEN_ID_MUSIC_LIST,
        //VIDEO SCREEN
        SCREEN_ID_VIDEO_PLAYER,
    };
};

const QMap<int, QString> ScreenNameMap
{
    //MUSIC SCREENS
    {AppEnums::SCREEN_ID_MUSIC_PLAYER, "qrc:/qml/screens/MusicPlayerScreen.qml"},
    {AppEnums::SCREEN_ID_MUSIC_LIST, "qrc:/qml/screens/MusicListScreen.qml"},
    //VIDEO SCREEN
    {AppEnums::SCREEN_ID_VIDEO_PLAYER, "qrc:/qml/screens/VideoPlayerScreen.qml"},
};

#endif // APPDEFINES_H
