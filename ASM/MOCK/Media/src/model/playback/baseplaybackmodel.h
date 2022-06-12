#ifndef BASEPLAYBACKMODEL_H
#define BASEPLAYBACKMODEL_H

#include <QObject>
#include "musiclistcontroller.h"
#include <QMediaPlayer>

// tim nhung cai property chung giua music va video
class BasePlaybackModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentMediaName READ currentMediaName WRITE setCurrentMediaName NOTIFY currentMediaNameChanged)
    Q_PROPERTY(QMediaPlayer::State currentStatus READ currentStatus WRITE setCurrentStatus NOTIFY currentStatusChanged)
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)

    Q_PROPERTY(QString currentTitle READ currentTitle WRITE setCurrentTitle NOTIFY metaDataChanged)
    Q_PROPERTY(QString currentAlbumName READ currentAlbumName WRITE setCurrentAlbumName NOTIFY metaDataChanged)
    Q_PROPERTY(QString currentArtist READ currentArtist WRITE setCurrentArtist NOTIFY metaDataChanged)
    Q_PROPERTY(bool isCurrentCoverArtNull READ isCurrentCoverArtNull WRITE setIsCurrentCoverArtNull NOTIFY metaDataChanged)
    Q_PROPERTY(QString currentPathCoverArt READ currentPathCoverArt WRITE setCurrentPathCoverArt NOTIFY metaDataChanged)

    Q_PROPERTY(QString m_videoName READ videoName WRITE setVideoName NOTIFY videoNameChanged)



public:
    BasePlaybackModel();

    QString currentMediaName() const;
    QMediaPlayer::State currentStatus() const;
    int currentIndex() const;


    QString currentTitle() const;
    QString currentAlbumName() const;
    QString currentArtist() const;
    bool isCurrentCoverArtNull() const;
    QString currentPathCoverArt() const;

    QString videoName() const;

public slots:
    void setCurrentMediaName(const QString &newCurrentMediaName);
    void setCurrentStatus(QMediaPlayer::State newCurrentStatus);
    void setCurrentIndex(int newCurrentIndex);

    void setCurrentTitle(const QString &newCurrentTitle);
    void setCurrentAlbumName(const QString &newCurrentAlbumName);
    void setCurrentArtist(const QString &newCurrentArtist);

    void setIsCurrentCoverArtNull(bool newIsCurrentCoverArtNull);

    void setCurrentPathCoverArt(const QString &newCurrentPathCoverArt);

    void setVideoName(const QString &newCurrentVideoName);

signals:

    void currentMediaNameChanged();
    void currentStatusChanged();
    void currentIndexChanged();

    void metaDataChanged();



    void videoNameChanged();

protected:

    QString m_currentMediaName;
    QMediaPlayer::State m_currentStatus;
    int m_currentIndex;
    QString m_currentTitle;
    QString m_currentAlbumName;
    QString m_currentArtist;
    QString m_currentPathCoverArt;
    bool m_isCurrentCoverArtNull;

    QString m_videoName;

};

#endif // BASEPLAYBACKMODEL_H
