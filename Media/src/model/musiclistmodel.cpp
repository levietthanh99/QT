#include "musiclistmodel.h"
#include "appdefines.h"


QString MusicListModel::m_pathFolder = "";

MusicListModel::MusicListModel(QObject *parent)
    : QObject{parent}
{

}

MusicListModel::~MusicListModel()
{

}

QStringList MusicListModel::listSong() const
{
    return m_listSong;
}

void MusicListModel::setListSong(const QStringList &newListSong)
{
    if (m_listSong == newListSong)
        return;

    m_listSong = newListSong;
    emit listSongChanged();
}
