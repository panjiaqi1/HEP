#ifndef COORDINATETEMPERATURE_H
#define COORDINATETEMPERATURE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QtGui>
#include "coordinate_service.h"
#include "coordinate.h"


class TemperatureCoordinate : public QWidget
{
    Q_OBJECT
public:
    explicit TemperatureCoordinate(QWidget *parent = nullptr);
    void initCoordinate();
    void paint(AccessPoint);

signals:

private:
    QImage image;
    Coordinate *coordinate;
protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }


public slots:
};

#endif // COORDINATETEMPERATURE_H
