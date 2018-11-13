#ifndef COORDINATEVOLTAGE_H
#define COORDINATEVOLTAGE_H

#include <QWidget>
#include <QPaintEvent> //绘画事件
#include <QPainter>
#include <QtGui>       //引入用到的控件


class VoltageCoordinate : public QWidget
{
    Q_OBJECT
public:
    explicit VoltageCoordinate(QWidget *parent = nullptr);
    void Paint();
signals:

private:
    QImage image;

    //画布
protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }

public slots:
};

#endif // COORDINATEVOLTAGE_H
