#ifndef OBJECT2_H
#define OBJECT2_H

#include <QObject>
#include <QDebug>


class Object2 : public QObject
{
    Q_OBJECT
public:
    explicit Object2(QObject *parent = nullptr);

signals:
    void signalObject2();

public slots:
    void onSignalObject2();


};

#endif // OBJECT2_H
