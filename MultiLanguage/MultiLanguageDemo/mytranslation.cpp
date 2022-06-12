#include "mytranslation.h"

MyTranslation::MyTranslation(QObject *parent)
    : QObject{parent}
{

}

void MyTranslation::setTranslation(QString translation)
{

    bool check = m_translator.load(":/" + translation + ".qm");
    qDebug() << Q_FUNC_INFO << translation << "   " << check;
    qApp->installTranslator(&m_translator);
    emit languageChanged();
}
