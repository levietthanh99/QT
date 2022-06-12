#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <QStack>
#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDebug>
#include "screenmodel.h"

extern int g_volume;
extern QString g_language;
extern void testWriteToJson(QString language, int volume);


class ScreenController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool modeDisplay READ modeDisplay WRITE setModeDisplay NOTIFY modeDisplayChanged)
    Q_PROPERTY(int currentVolume READ currentVolume WRITE setCurrentVolume NOTIFY currentVolumeChanged)

    // property receiver from media app
    Q_PROPERTY(QString currentTitle READ currentTitle WRITE setCurrentTitle NOTIFY metaDataChanged)
    Q_PROPERTY(QString currentArtist READ currentArtist WRITE setCurrentArtist NOTIFY metaDataChanged)
    Q_PROPERTY(bool isCurrentCoverArtNull READ isCurrentCoverArtNull WRITE setIsCurrentCoverArtNull NOTIFY metaDataChanged)
    Q_PROPERTY(QString currentPathCoverArt READ currentPathCoverArt WRITE setCurrentPathCoverArt NOTIFY metaDataChanged)
    Q_PROPERTY(QString currentVideoName READ currentVideoName WRITE setCurrentVideoName NOTIFY currentVideoNameChanged)

private:
    explicit ScreenController(QObject *parent = nullptr);
public:
    ~ScreenController();

    // singleton pattern
    static ScreenController *getInstance();

    // initialize controller
    void initialize(QQmlContext *context);
    void initializeScreen(QQmlApplicationEngine *engine);

    // screen transition
    Q_INVOKABLE void pushScreen(int screenId);
    Q_INVOKABLE void replaceScreen(int screenId);
    Q_INVOKABLE void popScreen();
    Q_INVOKABLE void popToRoot();

    // create signal using Dbus to request media app
    Q_INVOKABLE void requestDisplayMusic();
    Q_INVOKABLE void requestDisplayVideo();
    Q_INVOKABLE void requestChangeVolume();

    bool modeDisplay() const;
    int currentVolume() const;

    // meta data for music player
    QString currentTitle() const;
    QString currentArtist() const;
    bool isCurrentCoverArtNull() const;
    QString currentPathCoverArt() const;

    QString currentVideoName() const;

public slots:
    void onReceivedRequestBackToHome();
    void setModeDisplay(bool newmodeDisplay);
    void setCurrentVolume(int newCurrentVolume);

    // set meta data for music player
    void setCurrentTitle(const QString &newCurrentTitle);
    void setCurrentArtist(const QString &newCurrentArtist);
    void setIsCurrentCoverArtNull(bool newIsCurrentCoverArtNull);
    void setCurrentPathCoverArt(const QString &newCurrentPathCoverArt);

    void onReceivedRequestSendMetaData(QString title, QString artist, bool isPathNull, QString pathCoverArt, QString videoName);

    void setCurrentVideoName(const QString &newCurrentVideoName);

signals:
    void modeDisplayChanged();
    void currentVolumeChanged();

    void metaDataChanged();

    void currentVideoNameChanged();

private:
    void reloadScreen();

private:
    static ScreenController *m_instance;
    bool m_initialized;
    // get mode display true: display app, false: hidden app
    bool m_modeDisplay;
    ScreenModel m_model;
    QStack<int> m_screenStack;
    QQmlApplicationEngine *m_engine;
    int m_currentVolume;
    QString m_currentTitle;
    QString m_currentArtist;
    bool m_isCurrentCoverArtNull;
    QString m_currentPathCoverArt;
    QString m_currentVideoName;
};

#endif // SCREENCONTROLLER_H
