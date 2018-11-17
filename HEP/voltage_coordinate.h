#ifndef COORDINATEVOLTAGE_H
#define COORDINATEVOLTAGE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QtGui>
#include "coordinate_service.h"
#include "coordinate.h"
#include "access_point.h"


class VoltageCoordinate : public QWidget
{
    Q_OBJECT
public:
    explicit VoltageCoordinate(QWidget *parent = nullptr);
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

#endif // COORDINATEVOLTAGE_H
