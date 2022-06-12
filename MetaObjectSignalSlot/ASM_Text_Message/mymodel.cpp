#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    : QObject{parent}
{}
bool MyModel::initialize()
{
    m_engine.rootContext()->setContextProperty("myControl", this);
    m_engine.rootContext()->setContextProperty("myModel", m_list);
    onEditList();
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    m_engine.load(url);

    if(m_engine.rootObjects().isEmpty()){
        return false;
    }
    return true;
}

void MyModel::addTextToList(QString txt)
{
    m_list.append(txt);
    emit editList();
}

void MyModel::onEditList()
{
    m_engine.rootContext()->setContextProperty("myModel", m_list);
}


