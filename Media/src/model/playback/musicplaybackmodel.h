#ifndef MUSICPLAYBACKMODEL_H
#define MUSICPLAYBACKMODEL_H

#include <QObject>
#include <QMediaMetaData>
#include <QMediaObject>
#include <baseplaybackmodel.h>

// handle property display on music
class MusicPlaybackModel : public BasePlaybackModel
{
    Q_OBJECT
public:
    MusicPlaybackModel();

};

#endif // MUSICPLAYBACKMODEL_H
