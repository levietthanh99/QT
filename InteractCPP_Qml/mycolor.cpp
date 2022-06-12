#include "mycolor.h"

MyColor::MyColor(QObject *parent)
    : QObject{parent}
    , m_value(0)
    , m_color(GREEN)
    , m_timer(new MyTimer(this))
{
    qDebug() << Q_FUNC_INFO;
}

MyColor::~MyColor()
{
    qDebug() << Q_FUNC_INFO;
}

void MyColor::print()
{
    qDebug() << Q_FUNC_INFO;
}

int MyColor::value()
{
    return m_value;
}

void MyColor::setValue(int value)
{

    if(m_value != value){
        qDebug() << Q_FUNC_INFO << m_value << "=>" << value;
        m_value = value;
        emit valueChanged();
    }
}

MyColor::RgbColor MyColor::color() const
{
    return m_color;
}

void MyColor::setColor(RgbColor color)
{

    if(m_color != color){
        qDebug() << Q_FUNC_INFO << m_color << "=>" << color;
        m_color = color;
        emit colorChanged();
    }
}

MyTimer* MyColor::timer()
{
    return m_timer;
}


void MyColor::print2()
{
    qDebug() << Q_FUNC_INFO;
}
