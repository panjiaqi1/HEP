#include "temperature_coordinate.h"
#include "coordinate.h"
/*
 * 时间、温度坐标轴
 * */

TemperatureCoordinate::TemperatureCoordinate(QWidget *parent) : QWidget(parent)
{
    //画布的初始化大小设为800*340
    image = QImage(800, 340, QImage::Format_RGB32);
    //画布初始化背景色使用白色
    QColor backColor = qRgb(255, 255, 255);
    //对画布进行填充
    image.fill(backColor);


    Paint();
}

//绘制坐标轴
void TemperatureCoordinate::Paint(){
    Coordinate *coordinate = new Coordinate(new Point(40, 280), 150, 100, 150, 0);
    coordinate->setWidth(320);
    coordinate->setHeight(180);
    coordinate->render(&image);
}

