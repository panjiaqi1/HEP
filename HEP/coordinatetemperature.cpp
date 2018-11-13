#include "coordinatetemperature.h"
/*
 * 时间、温度坐标轴
 * */

CoordinateTemperature::CoordinateTemperature(QWidget *parent) : QWidget(parent)
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
void CoordinateTemperature::Paint(){
    QPainter painter(&image);

    //设置反锯齿模式
    painter.setRenderHint(QPainter::Antialiasing, true);

    //确定坐标轴起点坐标
    int pointx=40, pointy=280;

    //确定坐标轴宽度跟高度
    int width=300 - pointx, height=220;

    //画x，y轴
    QPen penBlack, penBlue;
    penBlack.setWidth(3);
    painter.setPen(penBlack);

    //x轴
    painter.drawLine(pointx, pointy, width + pointx + 20, pointy);
    painter.drawLine(width + pointx + 20, pointy, width+pointx + 12, pointy - 8);
    painter.drawLine(width + pointx + 20, pointy, width+pointx + 12, pointy + 8);

    //y轴
    painter.drawLine(pointx, pointy - height - 40, pointx, pointy);
    painter.drawLine(pointx, pointy - height - 40, pointx + 8, pointy - height - 25);
    painter.drawLine(pointx, pointy - height - 40, pointx - 8, pointy - height - 25);

    // X轴，刻度
    for(int i=0; i<10; i++)
    {
        painter.drawText(pointx - 22, pointy - (i + 1) * height/10, QString::number((10*(i + 1))));
    }
    painter.drawText(pointx - 40, pointy - height - 20, QString("T/℃"));

    //x轴，刻度
    for(int i=-1; i<10; i++)
    {
        painter.drawText(pointx + (i + 1) * width/10, pointy + 20, QString::number(((i+1)*(90))));
    }
    painter.drawText(pointx + width + 25, pointy + 10, QString("t/s"));

    //画网格线
    penBlue.setStyle(Qt::DotLine);
    penBlue.setWidth(1);
    penBlue.setColor(Qt::blue);
    painter.setPen(penBlue);

    //x轴线方向，网格线
    for(int i=0; i<10; i++)
    {
        painter.drawLine(pointx, pointy - (i + 1) * height/10, pointx + width + 20, pointy - (i + 1) * height/10);

    }

    // y轴线方向，网格线
    for(int i=0; i<10; i++)
    {
        painter.drawLine(pointx + (i + 1) * width/10, pointy, pointx + (i + 1) * width/10, pointy - height - 20);
    }


}

