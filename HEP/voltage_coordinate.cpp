#include "voltage_coordinate.h"
#include "coordinate_service.h"
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

    initCoordinate();
}

// 绘制坐标轴
void VoltageCoordinate::initCoordinate() {
    coordinate = new Coordinate(*new QPoint(40, 180), 140, 280, 140, 0);
    coordinate->setWidth(300);
    coordinate->setHeight(120);
    coordinate->setShareX(10);
    coordinate->setPositiveX(90);
    coordinate->setShareY(5);
    coordinate->setCoordinateX("t/s");
    coordinate->setCoordinateY("V/mv");
    coordinate->render(&image);
}

// 得到要画的点
void VoltageCoordinate::paint(AccessPoint accessPoint) {
    QPointF *point = new QPointF();
    point->setX(accessPoint.getSec());
    point->setY(accessPoint.getVoltage());
    coordinate->addpoint(point);
}

