#include "baseplaybackmodel.h"

BasePlaybackModel::BasePlaybackModel()
    :m_currentMediaName(MusicListController::m_listModel.listSong().isEmpty()?"":MusicListController::m_listModel.listSong().first())
    ,m_currentIndex(0)
    ,m_currentStatus(QMediaPlayer::StoppedState)
    ,m_currentTitle("")
    ,m_currentAlbumName("")
    ,m_currentArtist("")
    ,m_currentPathCoverArt("")
    ,m_isCurrentCoverArtNull(true)
    ,m_videoName("")
{

}

QString BasePlaybackModel::currentMediaName() const
{
    return m_currentMediaName;
}

QMediaPlayer::State BasePlaybackModel::currentStatus() const
{
    return m_currentStatus;
}

int BasePlaybackModel::currentIndex() const
{
    return m_currentIndex;
}

QString BasePlaybackModel::currentTitle() const
{
    return m_currentTitle;
}

QString BasePlaybackModel::currentAlbumName() const
{
    return m_currentAlbumName;
}

QString BasePlaybackModel::currentArtist() const
{
    return m_currentArtist;
}

bool BasePlaybackModel::isCurrentCoverArtNull() const
{
    return m_isCurrentCoverArtNull;
}

QString BasePlaybackModel::currentPathCoverArt() const
{
    return m_currentPathCoverArt;
}

QString BasePlaybackModel::videoName() const
{
    return m_videoName;
}

void BasePlaybackModel::setCurrentMediaName(const QString &newCurrentMediaName)
{

    if (m_currentMediaName == newCurrentMediaName)
        return;

    m_currentMediaName = newCurrentMediaName;
    m_currentIndex = MusicListController::m_listModel.listSong().indexOf(newCurrentMediaName);
    emit currentMediaNameChanged();
    emit currentIndexChanged();
}

void BasePlaybackModel::setCurrentStatus(QMediaPlayer::State newCurrentStatus)
{
    if (m_currentStatus == newCurrentStatus)
        return;

    m_currentStatus = newCurrentStatus;
    emit currentStatusChanged();
}

void BasePlaybackModel::setCurrentIndex(int newCurrentIndex)
{
    if (m_currentIndex == newCurrentIndex)
        return;

    m_currentIndex = newCurrentIndex;
    emit currentIndexChanged();
}

void BasePlaybackModel::setCurrentTitle(const QString &newCurrentTitle)
{
    if (m_currentTitle == newCurrentTitle)
        return;

    m_currentTitle = newCurrentTitle;
    emit metaDataChanged();
}

void BasePlaybackModel::setCurrentAlbumName(const QString &newCurrentAlbumName)
{
    if (m_currentAlbumName == newCurrentAlbumName)
        return;

    m_currentAlbumName = newCurrentAlbumName;
    emit metaDataChanged();
}

void BasePlaybackModel::setCurrentArtist(const QString &newCurrentArtist)
{
    if (m_currentArtist == newCurrentArtist)
        return;

    m_currentArtist = newCurrentArtist;
    emit metaDataChanged();
}

void BasePlaybackModel::setIsCurrentCoverArtNull(bool newIsCurrentCoverArtNull)
{
    if (m_isCurrentCoverArtNull == newIsCurrentCoverArtNull)
        return;

    m_isCurrentCoverArtNull = newIsCurrentCoverArtNull;
    emit metaDataChanged();
}

void BasePlaybackModel::setCurrentPathCoverArt(const QString &newCurrentPathCoverArt)
{
    if (m_currentPathCoverArt == newCurrentPathCoverArt)
        return;

    m_currentPathCoverArt = newCurrentPathCoverArt;
    emit metaDataChanged();
}

void BasePlaybackModel::setVideoName(const QString &newCurrentVideoName)
{
    if (m_videoName == newCurrentVideoName)
        return;

    m_videoName = newCurrentVideoName;
    emit videoNameChanged();
}
