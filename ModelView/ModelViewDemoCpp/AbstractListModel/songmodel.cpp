#include "songmodel.h"
const QString Song::pathFolder = "E:\\OneDrive\\Music\\Nhac khong loi TQ";
Song::Song(QString name)
{
    songName = name;
}
QString Song::getName() const
{
    return songName;
}
QString Song::getSourceFolder() const
{
    return pathFolder;
}
SongModel::SongModel(QObject *parent)
    : QAbstractListModel{parent}
{

}
void SongModel::addSong(const Song &song)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    listSong << song;
    endInsertRows();
}
QVariant SongModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= listSong.count())
        return QVariant();
    const Song &song = listSong[index.row()];
    if(role == name)
        return song.getName();
    if(role == path)
        return song.getSourceFolder();
    return QVariant();
}
int SongModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return listSong.count();
}
QHash<int, QByteArray> SongModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[name] = "name";
    roles[path] = "path";
    return roles;
}


