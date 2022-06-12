#ifndef SONGMODEL_H
#define SONGMODEL_H

#include <QObject>
#include <QAbstractListModel>

class Song {
public:
    Song(QString name);
    QString getName() const;
    QString getSourceFolder() const;
    static const QString pathFolder;
private:
    QString songName;
};

class SongModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum SongRoles {
        name = Qt::UserRole + 1,
        path
    };
    explicit SongModel(QObject *parent = nullptr);
    void addSong(const Song &song);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Song> listSong;
};
#endif // SONGMODEL_H
