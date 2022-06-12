#include "mediamodel.h"

MediaModel::MediaModel(QObject *parent)
    : QAbstractListModel{parent}
    , m_player(new QMediaPlayer())
    , m_currentSongTitle("")
    , m_currentArtist("")
    , m_currentThumbnail("")
    , m_currentPathThubnail("")
    , m_iscurrentThumbnailNull(true)
{
    connect(m_player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
            this, SLOT(onMediaStatusChanged(QMediaPlayer::MediaStatus)));
}

MediaModel::~MediaModel()
{
    if(m_player != nullptr){
        delete m_player;
        m_player = nullptr;
    }
}

QHash<int, QByteArray> MediaModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[MEDIA_FILE_NAME] = "MediaFileName";
    roles[MEDIA_SONG_NAME] = "MeidaSongName";
    return roles;
}

int MediaModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mSongList.count();
}

QVariant MediaModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() > mSongList.count()){
        return QVariant();
    }
    const QString item = mSongList[index.row()];
    if(role == MEDIA_FILE_NAME){
        return item;
    }else if(role == MEDIA_SONG_NAME){
        return QFileInfo(item).completeBaseName();
    }
    return QVariant();
}

void MediaModel::loadMediaList()
{
    QStringList path = QStandardPaths::standardLocations(QStandardPaths::MusicLocation);
    if(path.count() > 0){
        qDebug() << Q_FUNC_INFO << path.at(0);
        m_pathFolder = path.at(0);
        emit pathFolderChanged();
        QDir dir(path.at(0));
        QStringList list = dir.entryList(QStringList() << "*.mp3", QDir::Files);

        beginInsertRows(QModelIndex(), mSongList.count(), list.count() - 1);
        foreach(QString item, list){
            qDebug() << Q_FUNC_INFO << item;
            mSongList << item;
        }
        endInsertRows();
    }else {
        qDebug() << "Load list song fail";
    }
}

const QString &MediaModel::pathFolder() const
{
    return m_pathFolder;
}

const QString &MediaModel::currentSongTitle() const
{
    return m_currentSongTitle;
}

const QString &MediaModel::currentArtist() const
{
    return m_currentArtist;
}

bool MediaModel::iscurrentThumbnailNull() const
{
    return m_iscurrentThumbnailNull;
}

const QString &MediaModel::currentPathThubnail() const
{
    return m_currentPathThubnail;
}


