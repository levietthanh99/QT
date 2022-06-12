#ifndef HMICONTROLLER_H
#define HMICONTROLLER_H

#include <QObject>

class HmiController : public QObject
{
    Q_OBJECT
public:
    explicit HmiController(QObject *parent = nullptr);

public slots:
    void onTestChanged();

};

#endif // HMICONTROLLER_H
