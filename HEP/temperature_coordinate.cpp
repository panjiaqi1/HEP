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

    Paint();
}

// 绘制坐标轴
void TemperatureCoordinate::Paint(){
    Coordinate *coordinate = new Coordinate(new Point(40, 180), 140, 280, 140, 0);
    coordinate->setWidth(300);
    coordinate->setHeight(120);
    coordinate->setShareX(10);
    coordinate->setPositiveX(90);
    coordinate->setShareY(5);
    coordinate->setCoordinateX("t/s");
    coordinate->setCoordinateY("V/mv");
    coordinate->render(&image);
}

