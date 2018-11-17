#ifndef COORDINATE_H
#define COORDINATE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QtGui>
#include "access_point.h"
#include "coordinate.h"

class VoltageTemperatureCoordinate : public QWidget
{
    Q_OBJECT
public:
    explicit VoltageTemperatureCoordinate(QWidget *parent = nullptr);
    void initCoordinate();
    void paint(AccessPoint);

signals:

public slots:

private:
    QImage image;
    Coordinate *coordinate;
protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }
};

#endif // COORDINATE_H
