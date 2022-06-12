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

class ScreenController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool modeDisplay READ modeDisplay WRITE setModeDisplay NOTIFY modeDisplayChanged)
private:
    explicit ScreenController(QObject *parent = nullptr);

public:
    ~ScreenController();

    // singleton pattern
    static ScreenController *getInstance();

    // initialize controller
    void initialize(QQmlContext *context);
    void initializeScreen(QQmlApplicationEngine *engine);

    bool modeDisplay() const;

    // screen transition
    Q_INVOKABLE void pushScreen(int screenId);
    Q_INVOKABLE void replaceScreen(int screenId);
    Q_INVOKABLE void popScreen();
    Q_INVOKABLE void popToRoot();

    // request back screen to home app
    Q_INVOKABLE void requestBackToHome();

    // return count screen in stack screen of media app
    Q_INVOKABLE int countScreenInStack();

private:
    void reloadScreen();

public slots:
    void onReceivedRequestDisplayMusic();
    void onReceivedRequestDisplayVideo();

    void setModeDisplay(bool modeDisplay);

signals:
    void modeDisplayChanged();

private:
    static ScreenController *m_instance;
    bool m_initialized;
    bool m_modeDisplay;

    ScreenModel m_model;
    QStack<int> m_screenStack;
    QQmlApplicationEngine *m_engine;

};

#endif // SCREENCONTROLLER_H
