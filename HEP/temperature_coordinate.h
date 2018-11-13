#ifndef COORDINATETEMPERATURE_H
#define COORDINATETEMPERATURE_H

#include <QWidget>
#include <QPaintEvent> //绘画事件
#include <QPainter>
#include <QtGui>       //引入用到的控件


class TemperatureCoordinate : public QWidget
{
    Q_OBJECT
public:
    explicit TemperatureCoordinate(QWidget *parent = nullptr);
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

#endif // COORDINATETEMPERATURE_H
