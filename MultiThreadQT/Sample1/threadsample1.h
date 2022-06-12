#ifndef THREADSAMPLE1_H
#define THREADSAMPLE1_H

#include <QObject>
#include <QThread>

class ThreadSample1 : public QObject
{
    Q_OBJECT
public:
    explicit ThreadSample1(QObject *parent = nullptr);

    void testFunc(int param);

signals:

};

#endif // THREADSAMPLE1_H
