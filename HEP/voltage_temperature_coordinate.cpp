#include "voltage_temperature_coordinate.h"
#include "coordinate_service.h"


/**
 * @brief VoltageTemperatureCoordinate::VoltageTemperatureCoordinate
 * @param parent
 * 温度、电压坐标轴
 */

VoltageTemperatureCoordinate::VoltageTemperatureCoordinate(QWidget *parent) : QWidget(parent)
{
    // 画布的初始化大小设为800*500
    image = QImage(800, 500, QImage::Format_RGB32);
    // 画布初始化背景色使用白色
    QColor backColor = qRgb(255, 255, 255);
    // 对画布进行填充
    image.fill(backColor);

    initCoordinate();
}

// 绘制坐标轴
void VoltageTemperatureCoordinate::initCoordinate() {
    coordinate = new Coordinate(*new QPoint(40, 180), 160, 620, 160, 0);
    coordinate->setCoordinateX("T/℃");
    coordinate->setCoordinateY("V/mv");
    coordinate->render(&image);
}

// 得到要画的点
void VoltageTemperatureCoordinate::paint(AccessPoint accessPoint) {
    QPointF *point = new QPointF();
    point->setX(accessPoint.getTemperature());
    point->setY(accessPoint.getVoltage());
    coordinate->addpoint(point);
}
