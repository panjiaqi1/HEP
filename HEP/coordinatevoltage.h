#ifndef COORDINATEVOLTAGE_H
#define COORDINATEVOLTAGE_H

#include <QWidget>
#include <QPaintEvent> //绘画事件
#include <QtGui>       //引入用到的控件
#include <QPainter>
#include <iostream>
#include <cstdlib>
#include <ctime>


class CoordinateVoltage : public QWidget
{
    Q_OBJECT
public:
    explicit CoordinateVoltage(QWidget *parent = nullptr);
    void Paint();
signals:

private:
    QImage image;

protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }

public slots:
};

#endif // COORDINATEVOLTAGE_H
