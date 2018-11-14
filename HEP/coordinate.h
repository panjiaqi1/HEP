#ifndef Coordinate_H
#define Coordinate_H

#include <QImage>
#include "point.h"

class Coordinate
{
public:
    Coordinate();
    Coordinate(Point*, int);
    Coordinate(Point*, int, int);
    Coordinate(Point*, int, int, int);
    Coordinate(Point*, int, int, int, int);
    void setWidth(int);               //x轴刻度长度
    void setHeight(int);              //y轴刻度长度
    void setShareX(int);              // x轴份数
    void setShareY(int);              // y轴份数
    void setPositiveX(int);           // x轴正半轴刻度系数
    void setNegativeX(int);           // x轴负半轴刻度系数
    void setPositiveY(int);           // y轴正半轴刻度系数
    void setNegativeY(int);           // y轴负半轴刻度系数
    void setCoordinateX(QString);     //x轴标题
    void setCoordinateY(QString);     //y轴标题
    void render(QImage*);
private:
    int top, right, bottom, left, width, height, shareX, shareY, positiveX, negativeX, positiveY, negativeY;
    QString coordinateX, coordinateY;
    Point *originPoint;
};

#endif // Coordinate_H
