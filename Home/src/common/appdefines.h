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
        SCREEN_ID_HOME_MENU,
        SCREEN_ID_HOME_SETTUP
    };
};

const QMap<int, QString> ScreenNameMap
{
    {AppEnums::SCREEN_ID_HOME_MENU, "qrc:/qml/screens/HomeMenuScreen.qml"},
    {AppEnums::SCREEN_ID_HOME_SETTUP, "qrc:/qml/screens/HomeSettupScreen.qml"},
};

#endif // APPDEFINES_H
