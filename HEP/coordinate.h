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
    void setWidth(int);
    void setHeight(int);
    void render(QImage*);
private:
    int top, right, bottom, left, width, height;
    Point *originPoint;
};

#endif // Coordinate_H
