#include "mydata.h"

MyData::MyData(QObject *parent)
    : QObject{parent}
    ,m_pathFile("")
{}
bool MyData::loadFile()
{
    QFile inputFile(m_pathFile);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       m_list.clear();
       while (!in.atEnd())
       {
          QString line = in.readLine();
          m_list.append(line);
       }
       inputFile.close();
       emit myListChanged();
       return true;
    }else{
        return false;
    }
}
const QString &MyData::myPathFile() const
{
    return m_pathFile;
}

void MyData::setMyPathFile(const QString &newMyPathFile)
{
    if (m_pathFile == newMyPathFile)
        return;
    m_pathFile = newMyPathFile;
    emit myPathFileChanged();
}
const QStringList &MyData::myList() const
{
    return m_list;
}
void MyData::setMyList(const QStringList &newMyList)
{
    if (m_list == newMyList)
        return;
    m_list = newMyList;
    emit myListChanged();
}



