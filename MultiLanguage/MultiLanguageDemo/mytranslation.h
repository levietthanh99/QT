#ifndef MYTRANSLATION_H
#define MYTRANSLATION_H

#include <QObject>
#include <QTranslator>
#include <QGuiApplication>
#include <QDebug>

#define STRING_ID(Name, Value) \
    public: \
    Q_PROPERTY(QString Name READ Name NOTIFY languageChanged) \
    static QString Name() { \
    return (Value); \
    }
class MyTranslation : public QObject
{
    Q_OBJECT
    STRING_ID(WINDOW_TITLE_STRING_ID, tr("WINDOW_TITLE_STRING_ID"))
    STRING_ID(LABEL_STRING_ID, tr("LABEL_STRING_ID"))
    STRING_ID(CONTENT_STRING_ID, tr("CONTENT_STRING_ID"))
    STRING_ID(EMPTY_STRING_ID, tr(""))

public:
    explicit MyTranslation(QObject *parent = nullptr);
    Q_INVOKABLE void setTranslation(QString translation);

signals:
    void languageChanged();

private:
    QTranslator m_translator;
};

#endif // MYTRANSLATION_H
