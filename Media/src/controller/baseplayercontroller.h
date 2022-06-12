#ifndef BASEPLAYERCONTROLLER_H
#define BASEPLAYERCONTROLLER_H

#include <QObject>
#include <QQmlContext>
#include <QMediaPlayer>
#include <QDBusConnection>
#include <QImage>
#include <QFileInfo>
#include <QDBusConnection>
#include <QDBusMessage>
#include "baseplaybackmodel.h"
#include "musicplaybackmodel.h"
#include "musiclistmodel.h"

class BasePlayerController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ videoSurface WRITE setVideoSurface NOTIFY videoSurfaceChanged)
    Q_PROPERTY(bool isFullScreenVideo READ isFullScreenVideo WRITE setIsFullScreenVideo NOTIFY isFullScreenVideoChanged)
public:
    ~BasePlayerController();
    // initialize controller
    void initialize(QQmlContext *context);

    Q_INVOKABLE void requestPlay();
    Q_INVOKABLE void requestNext();
    Q_INVOKABLE void requestPrevious();
    Q_INVOKABLE void requestSendMetaData();

    Q_INVOKABLE void requestPlayVideo();

    QAbstractVideoSurface *videoSurface() const
    {
        return m_videoSurface;
    }

    bool isFullScreenVideo() const;

public slots:
    void handelPlaybackStatusChanged(QMediaPlayer::State status);
    void onReceivedRequestChangeVolume(int);
    void onMediaStatuschanged(QMediaPlayer::MediaStatus status);

    void setVideoSurface(QAbstractVideoSurface *newVideoSurface)
    {
        if (m_videoSurface == newVideoSurface)
            return;

        m_videoSurface = newVideoSurface;
        mPlayer.setVideoOutput(m_videoSurface);
        emit videoSurfaceChanged();
    }


    void onRequestedPlayMusic();
    void onRequestedPlayVideo();

    void setIsFullScreenVideo(bool newIsFullScreen);

signals:
    void videoSurfaceChanged();
    void isFullScreenVideoChanged();

private:
    bool m_initialized;
    QAbstractVideoSurface *m_videoSurface;
    bool m_isFullScreenVideo;

protected:
    QMediaPlayer mPlayer;
    BasePlaybackModel *mPlaybackModel;
};

#endif // BASEPLAYERCONTROLLER_H
