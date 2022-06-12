#ifndef SAMPLEWORKER_H
#define SAMPLEWORKER_H

#include <QObject>
#include <QThread>

class SampleWorker : public QObject
{
    Q_OBJECT
public:
    explicit SampleWorker(QObject *parent = nullptr);

signals:
    void bgTaskDone(int taskId);
public slots:
    void doBgTask(int taskId);
};

#endif // SAMPLEWORKER_H
