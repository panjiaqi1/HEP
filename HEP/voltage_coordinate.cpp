#include "voltage_coordinate.h"
#include "coordinate.h"
/**
 * @brief VoltageCoordinate::VoltageCoordinate
 * @param parent
 * 时间、电压坐标轴
 */

VoltageCoordinate::VoltageCoordinate(QWidget *parent) : QWidget(parent)
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
void VoltageCoordinate::Paint(){
    Coordinate *coordinate = new Coordinate(new Point(40, 280), 260, 280, 0, 0);
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

