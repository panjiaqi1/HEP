#include "temperature_coordinate.h"
#include "coordinate.h"
/**
 * @brief TemperatureCoordinate::TemperatureCoordinate
 * @param parent
 * 时间、温度坐标轴
 */

TemperatureCoordinate::TemperatureCoordinate(QWidget *parent) : QWidget(parent)
{
    // 画布的初始化大小设为800*340
    image = QImage(800, 340, QImage::Format_RGB32);
    // 画布初始化背景色使用白色
    QColor backColor = qRgb(255, 255, 255);
    // 对画布进行填充
    image.fill(backColor);

    initCoordinate();
}

// 绘制坐标轴
void TemperatureCoordinate::initCoordinate(){
    coordinate = new Coordinate(*new QPoint(40, 280), 260, 280, 0, 0);
    coordinate->setWidth(300);
    coordinate->setHeight(240);
    coordinate->setShareX(10);
    coordinate->setShareY(10);
    coordinate->setPositiveX(90);
    coordinate->setPositiveY(10);
    coordinate->setCoordinateX("t/s");
    coordinate->setCoordinateY("T/℃");
    coordinate->render(&image);
}

// 得到要画的点
void TemperatureCoordinate::paint(AccessPoint accessPoint) {
    QPointF *point = new QPointF();
    point->setX(accessPoint.getSec());
    point->setY(accessPoint.getTemperature());
    coordinate->addpoint(point);
}

