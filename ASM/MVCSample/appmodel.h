#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QtDebug>

class AppModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int data READ data WRITE setData NOTIFY dataChanged)
public:
    explicit AppModel(QObject *parent = nullptr);
    int data() const;
    void setData(int data);

signals:
void dataChanged();

private:
    int m_data;
};

#endif // APPMODEL_H
