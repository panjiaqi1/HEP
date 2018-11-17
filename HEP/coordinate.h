#ifndef Coordinate_H
#define Coordinate_H

#include <QImage>
#include <QPen>
#include <QPointF>
#include <QPainter>

/**
 * @brief The Coordinate class
 * 二维坐标系
 */

class Coordinate
{
public:
    Coordinate();
    Coordinate(QPoint, int);
    Coordinate(QPoint, int, int);
    Coordinate(QPoint, int, int, int);
    Coordinate(QPoint, int, int, int, int);
    void setWidth(int);               // x轴刻度长度
    void setHeight(int);              // y轴刻度长度
    void setShareX(int);              // x轴份数
    void setShareY(int);              // y轴份数
    void setPositiveX(int);           // x轴正半轴刻度系数
    void setNegativeX(int);           // x轴负半轴刻度系数
    void setPositiveY(int);           // y轴正半轴刻度系数
    void setNegativeY(int);           // y轴负半轴刻度系数
    void setCoordinateX(QString);     // x轴标题
    void setCoordinateY(QString);     // y轴标题
    void render(QImage*);             // 画布
    void addpoint(QPointF*);           // 添加点
private:
    int top,                  // y轴正半轴长度
    right,                    // x轴正半轴长度
    bottom,                   // y轴负半轴长度
    left,                     // x轴负半轴长度
    width,                    // x轴刻度长度
    height,                   // y轴刻度长度
    shareX,                   // x轴份数
    shareY,                   // y轴份数
    positiveX,                // x轴正半轴刻度系数
    negativeX,                // x轴负半轴刻度系数
    positiveY,                // y轴正半轴刻度系数
    negativeY;                // y轴负半轴刻度系数
    QString coordinateX,      // x轴标题
    coordinateY;              // y轴标题
    QPoint originPoint;       // 点
    QPointF *addPoint;        // 添加的点
    QImage *qImage;           // 画布
    QPainter *painter;
    QPen penBlack, penBlue, pointPen;  // 笔
};

#endif // Coordinate_H
