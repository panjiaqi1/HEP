#ifndef COORDINATE_H
#define COORDINATE_H

#include <QWidget>
#include <QPaintEvent> //绘画事件
#include <QPainter>
#include <QtGui>       //引入用到的控件

class VoltageTemperatureCoordinate : public QWidget
{
    Q_OBJECT
public:
    explicit VoltageTemperatureCoordinate(QWidget *parent = nullptr);
    void Paint();

signals:

public slots:

private:
    QImage image;

protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }
};

#endif // COORDINATE_H
