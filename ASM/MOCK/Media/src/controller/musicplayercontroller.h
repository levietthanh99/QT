#ifndef MUSICPLAYERCONTROLLER_H
#define MUSICPLAYERCONTROLLER_H

#include "baseplayercontroller.h"
#include <QMediaMetaData>
#include <QMediaPlayer>

class MusicPlayerController : public BasePlayerController
{
public:
    MusicPlayerController();
    static MusicPlayerController *getInstance();

signals:

};

#endif // MUSICPLAYERCONTROLLER_H
