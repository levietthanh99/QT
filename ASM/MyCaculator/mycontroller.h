#ifndef MYCONTROLLER_H
#define MYCONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QQmlEngine>
#include <QQmlContext>
#include <math.h>

class MyController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double para1 READ para1 WRITE setPara1 NOTIFY para1Changed)
    Q_PROPERTY(double para2 READ para2 WRITE setPara2 NOTIFY para2Changed)
    Q_PROPERTY(QString myOperator READ myOperator WRITE setOperator NOTIFY myOperatorChanged)
    Q_PROPERTY(QString result READ result NOTIFY resultChanged)
public:
    explicit MyController(QObject *parent = nullptr);

    void initialize(QQmlEngine *engine);
    double para1() const;
    double para2() const;
    const QString &myOperator() const;
    const QString &result() const;

    Q_INVOKABLE void setPara1(double num1);
    Q_INVOKABLE void setPara2(double num2);
    Q_INVOKABLE void setOperator(QString myOperator);
    Q_INVOKABLE void myCacluate();
    Q_INVOKABLE bool isUnaryOperator();

signals:
    void para1Changed();
    void para2Changed();
    void myOperatorChanged();
    void resultChanged();

private:
    double m_para1;
    double m_para2;
    QString m_operator;
    QString m_result;
};

#endif // MYCONTROLLER_H
