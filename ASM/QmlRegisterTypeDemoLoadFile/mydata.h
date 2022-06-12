#ifndef MYDATA_H
#define MYDATA_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class MyData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString myPathFile READ myPathFile WRITE setMyPathFile
               NOTIFY myPathFileChanged)
    Q_PROPERTY(QStringList myList READ myList WRITE setMyList
               NOTIFY myListChanged)
public:
    explicit MyData(QObject *parent = nullptr);
    Q_INVOKABLE bool loadFile();

    const QString &myPathFile() const;
    void setMyPathFile(const QString &newMyPathFile);

    const QStringList &myList() const;
    void setMyList(const QStringList &newMyList);
signals:
    void myPathFileChanged();
    void myListChanged();
private:
    QString m_pathFile;
    QStringList m_list;
};

#endif // MYDATA_H
