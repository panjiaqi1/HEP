#ifndef COORDINATEVOLTAGE_H
#define COORDINATEVOLTAGE_H

#include <QWidget>
#include <QPaintEvent> //绘画事件
#include <QPainter>
#include <QtGui>       //引入用到的控件


class CoordinateVoltage : public QWidget
{
    Q_OBJECT
public:
    explicit CoordinateVoltage(QWidget *parent = nullptr);
    void Paint();
signals:

private:
    QImage image;

<<<<<<< HEAD:HEP/voltage_coordinate.h

=======
//画布
>>>>>>> parent of 0db38bc... 代码重构:HEP/coordinatevoltage.h
protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }

public slots:
};

#endif // COORDINATEVOLTAGE_H