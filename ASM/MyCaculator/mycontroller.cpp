#include "mycontroller.h"

MyController::MyController(QObject *parent)
    : QObject{parent}
    , m_para1(0)
    , m_para2(0)
    , m_operator("")
    , m_result("")
{

}

void MyController::initialize(QQmlEngine *engine)
{
    engine->rootContext()->setContextProperty("myControl", this);
}

void MyController::setPara1(double num1)
{
    m_para1 = num1;
    emit para1Changed();
    qDebug() << Q_FUNC_INFO << m_para1;
}

void MyController::setPara2(double num2)
{
    qDebug() << Q_FUNC_INFO << num2;
    m_para2 = num2;
    emit para2Changed();
}

void MyController::setOperator(QString myOperator)
{
    m_operator = myOperator;
    emit myOperatorChanged();
    qDebug() << Q_FUNC_INFO << m_operator;
}

void MyController::myCacluate()
{
    if(m_operator == "+"){
        m_result =  QString::number(m_para1 + m_para2);
        qDebug() << "Results: " << m_result;
        emit resultChanged();
    }else if(m_operator == "-"){
        m_result =  QString::number(m_para1 - m_para2);
        qDebug() << "Results: " << m_result;
        emit resultChanged();
    }else if(m_operator == "x"){
        m_result =  QString::number(m_para1 * m_para2);
        qDebug() << "Results: " << m_result;
        emit resultChanged();
    }else if(m_operator == ":"){
        m_result =  QString::number(m_para1 / m_para2);
        qDebug() << "Results: " << m_result;
        emit resultChanged();
    }else if(m_operator == "sqrt"){
        m_result =  QString::number(std::sqrt(m_para1));
        qDebug() << "Results: " << m_result;
        emit resultChanged();
    }else if(m_operator == "sqr"){
        m_result =  QString::number(m_para1 * m_para1);
        qDebug() << "Results: " << m_result;
        emit resultChanged();
    }else if(m_operator == "1/"){
        m_result =  QString::number(1/ m_para1);
        qDebug() << "Results: " << m_result;
        emit resultChanged();
    }else if(m_operator == "%"){
        m_result =  QString::number(m_para1/100);
        qDebug() << "Results: " << m_result;
        emit resultChanged();
    }
    if(m_result == "nan"){
        m_result = "Invalid input";
        qDebug() << "Results: " << m_result;
        emit resultChanged();
    }
    if(m_result == "inf"){
        m_result = "Cannot divide by 0";
        emit resultChanged();
    }

}

bool MyController::isUnaryOperator()
{
    if(m_operator != "+" && m_operator != "-" && m_operator != "x" && m_operator != ":"){
        return true;
    }
    return false;
}



double MyController::para1() const
{
    return m_para1;
}

double MyController::para2() const
{
    return m_para2;
}

const QString &MyController::result() const
{
    return m_result;
}

const QString &MyController::myOperator() const
{
    return m_operator;
}


