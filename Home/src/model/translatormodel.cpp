#include "translatormodel.h"

TranslatorModel::TranslatorModel(QObject *parent)
    : QObject{parent}
    , m_currentLanguage(g_language)
{
    // default language when start running app
    if(g_language == "English"){
        m_translator.load(":/localization/AppLanguage_en.qm");
    }else{
        m_translator.load(":/localization/AppLanguage_vi.qm");
    }
    qApp->installTranslator(&m_translator);
    emit languageChanged();
}

void TranslatorModel::setTranslation(QString language)
{
    m_translator.load(":/localization/" + language + ".qm");
    qApp->installTranslator(&m_translator);
    emit languageChanged();
}

QString TranslatorModel::currentLanguage() const
{
    return m_currentLanguage;
}

void TranslatorModel::setCurrentLanguage(QString currentLanguage)
{
    if (m_currentLanguage == currentLanguage)
        return;

    m_currentLanguage = currentLanguage;
    g_language = m_currentLanguage;
    testWriteToJson(g_language, g_volume);
    emit languageChanged();
}
