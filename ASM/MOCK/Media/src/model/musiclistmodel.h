#ifndef MUSICLISTMODEL_H
#define MUSICLISTMODEL_H

#include <QObject>

//handel list data model for display music list screen
class MusicListModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList listSong READ listSong WRITE setListSong NOTIFY listSongChanged)
public:
    explicit MusicListModel(QObject *parent = nullptr);
    ~MusicListModel();
    static QString m_pathFolder;

    Q_INVOKABLE QStringList listSong() const;

public slots:
    void setListSong(const QStringList &newListSong);
signals:
    void listSongChanged();

private:
     QStringList m_listSong;

};

#endif // MUSICLISTMODEL_H
