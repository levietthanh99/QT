#ifndef THREADSAMPLE2_H
#define THREADSAMPLE2_H

#include <QThread>

class ThreadSample2 : public QThread
{
    Q_OBJECT
public:
    explicit ThreadSample2(QObject *parent = nullptr);

    void run() override;
signals:
    void testSignal();

};

#endif // THREADSAMPLE2_H
