#include "musicplayercontroller.h"
#include "musicplaybackmodel.h"

MusicPlayerController::MusicPlayerController()
{
    mPlaybackModel = new MusicPlaybackModel();
}

MusicPlayerController *MusicPlayerController::getInstance()
{
    static MusicPlayerController instance;
    return &instance;
}
