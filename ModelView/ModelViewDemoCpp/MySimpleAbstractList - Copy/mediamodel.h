#ifndef MEDIAMODEL_H
#define MEDIAMODEL_H

#include <QObject>
#include <QAbstractListModel>
//#include <QFileInfo>
#include <QStandardPaths>
#include <QDebug>
#include <QDir>
#include <QMediaPlayer>
#include <QMediaMetaData>
//#include <QMediaObject>
#include <QImage>


class MediaModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString pathFolder READ pathFolder NOTIFY pathFolderChanged)

    //Meta data
    Q_PROPERTY(QString currentSongTitle READ currentSongTitle NOTIFY metaDataChanged)
    Q_PROPERTY(QString currentArtist READ currentArtist NOTIFY metaDataChanged)
    Q_PROPERTY(bool iscurrentThumbnailNull READ iscurrentThumbnailNull NOTIFY metaDataChanged)
    Q_PROPERTY(QString currentPathThubnail READ currentPathThubnail NOTIFY metaDataChanged)
public:
    explicit MediaModel(QObject *parent = nullptr);
    ~MediaModel();

    enum MEDIA_ROLE {
        MEDIA_FILE_NAME = Qt::UserRole + 1,
        MEDIA_SONG_NAME
    };
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    void loadMediaList();
    const QString &pathFolder() const;
    QMediaPlayer *player() const;
    const QString &currentSongTitle() const;
    const QString &currentArtist() const;
    bool iscurrentThumbnailNull() const;
    const QString &currentPathThubnail() const;

    Q_INVOKABLE void playMedia(QString pathFolder, QString songName){
        m_player->setMedia(QUrl::fromLocalFile(pathFolder + "/" + songName + ".mp3"));
        m_player->play();
        m_currentSongName = songName;
    }

signals:
    void pathFolderChanged();
    void metaDataChanged();
    void currentPathThubnailChanged();

public slots:
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status)
    {
        if(status == QMediaPlayer::BufferedMedia){
            m_currentSongTitle = m_player->metaData(QMediaMetaData::Title).toString();
            m_currentArtist = m_player->metaData(QMediaMetaData::ContributingArtist).toString();
            m_currentThumbnail = m_player->metaData(QMediaMetaData::ThumbnailImage).value<QImage>();

            if(m_currentThumbnail.isNull()){
                m_iscurrentThumbnailNull = true;
            }else {
                m_iscurrentThumbnailNull = false;
                m_currentPathThubnail = QString(PROJECT_PATH) + "/Image/"+  m_currentSongName + ".jpg";
                m_currentThumbnail.save(m_currentPathThubnail);
            }
            emit metaDataChanged();
        }

        //        for (auto key: m_player->availableMetaData()){
        //            qDebug() << key << m_player->metaData(key);
        //        }
    }
private:
    QList<QString> mSongList;
    QMediaPlayer* m_player;
    QString m_pathFolder;
    QString m_currentSongName;
    //meta data
    QString m_currentSongTitle;
    QString m_currentArtist;
    QImage m_currentThumbnail;
    QString m_currentPathThubnail;
    bool m_iscurrentThumbnailNull;
};

#endif // MEDIAMODEL_H
