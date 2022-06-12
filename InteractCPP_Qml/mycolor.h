#ifndef MYCOLOR_H
#define MYCOLOR_H

#include <QObject>
#include <QtDebug>
#include <mytimer.h>

class MyColor : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(RgbColor color READ color WRITE setColor NOTIFY colorChanged)
    //Q_PROPERTY(RgbColor color READ color CONSTANT)
    Q_PROPERTY(MyTimer* timer READ timer CONSTANT)

public:
    explicit MyColor(QObject *parent = nullptr);
    ~MyColor();

    enum RgbColor {
        RED,
        GREEN,
        BLUE,
    };

    Q_ENUM(RgbColor);

    Q_INVOKABLE void print();
    int value();
    void setValue(int value);
    RgbColor color() const;
    void setColor(RgbColor color);
    MyTimer* timer();


signals:
    void valueChanged();
    void colorChanged();

public slots:
    void print2();

private:
    int m_value;
    RgbColor m_color;
    MyTimer *m_timer;

};

#endif // MYCOLOR_H
