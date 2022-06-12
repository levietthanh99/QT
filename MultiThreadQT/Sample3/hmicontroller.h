#ifndef HMICONTROLLER_H
#define HMICONTROLLER_H

#include <QObject>
#include <QQmlContext>
#include <QThread>
#include <sampleworker.h>

class HmiController : public QObject
{
    Q_OBJECT
public:
    explicit HmiController(QObject *parent = nullptr);
    ~HmiController();

    void initialize(QQmlContext *ctx);
    Q_INVOKABLE void doTask();
signals:
    void requestBgTask(int taskId);
public slots:
    void onBgTaskDone(int taskId);

private:
    bool m_initialized;
    int m_taskCount;

    QThread *m_thread;
    SampleWorker m_worker;

};

#endif // HMICONTROLLER_H
