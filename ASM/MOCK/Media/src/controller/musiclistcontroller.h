#ifndef MUSICLISTCONTROLLER_H
#define MUSICLISTCONTROLLER_H

#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "musiclistmodel.h"
#include <QDebug>
#include <QStandardPaths>
#include <QDir>











// this class will handel read all .mp3 file in a directory then it push to model
class MusicListController : public QObject
{
private:
    explicit MusicListController(QObject *parent = nullptr);

public:
    ~MusicListController();

    // singleton pattern
    static MusicListController *getInstance();

    // initialize controller
    void initialize(QQmlContext *context);

    // load list song
    void loadListSong();

    static MusicListModel m_listModel;

private:
    static MusicListController *m_instance;
    bool m_initialized;



};

#endif // MUSICLISTCONTROLLER_H
