#ifndef MEDIAMODEL_H
#define MEDIAMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QFileInfo>
#include <QStandardPaths>
#include <QDebug>
#include <QDir>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QMediaObject>

class Song{
public:
    Song(QString name, QString title){
        m_name = name;
        m_title = title;
    }
    const QString &name() const;
    void setName(const QString &newName);

    const QString &title() const;
    void settitle(const QString &newTitle);

private:
    QString m_name;
    QString m_title;
};


class MediaModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString pathFolder READ pathFolder WRITE setPathFolder NOTIFY pathFolderChanged)
public:
    explicit MediaModel(QObject *parent = nullptr);
    ~MediaModel();

    enum MEDIA_ROLE {
        MEDIA_FILE_NAME = Qt::UserRole + 1,
        MEDIA_SONG_TITLE
    };
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    void loadMediaList();

    const QString &pathFolder() const;
    void setPathFolder(const QString &newPathFolder);

    Q_INVOKABLE void playMedia(QString pathFile){
          qDebug() << "ahihi";
         mPlayer->setMedia(QUrl::fromLocalFile(pathFile));
            mPlayer->isMetaDataAvailable();
            if(mPlayer->isMetaDataAvailable()){
                qDebug() << test;
            }
//         mPlayer->play();
    }

signals:

    void pathFolderChanged();
    void mPlayerChanged();

public slots:
    void onMediaStatusChanged(){
//        if (status == QMediaPlayer::LoadedMedia)
//        qDebug() << mPlayer->isMetaDataAvailable();
          test =  mPlayer->metaData(QMediaMetaData::Title).toString();
    }


private:
    QList<Song> mSongList;
    QMediaPlayer* mPlayer;

    QString test;
    QStringList m_list;

    QString m_pathFolder;
};

#endif // MEDIAMODEL_H
