#include "coordinatevoltage.h"
#include "window.h"
#include "ui_window.h"

CoordinateVoltage::CoordinateVoltage(QWidget *parent) : QWidget(parent)
{
    //画布的初始化大小设为2000*800，使用32位颜色
    image = QImage(800,340,QImage::Format_RGB32);
    //画布初始化背景色使用白色
    QColor backColor = qRgb(255,255,255);
    //对画布进行填充
    image.fill(backColor);

    Paint();
}

void CoordinateVoltage::Paint(){
    QPainter painter(&image);

    //设置反锯齿模式
    painter.setRenderHint(QPainter::Antialiasing,true);

    //确定坐标轴起点坐标
    int pointx=40,pointy=170;
    //确定坐标轴宽度跟高度
    int width=300-pointx,height=130;

    //画x，y轴
    QPen penBlack,penDot;
    penBlack.setWidth(3);
    painter.setPen(penBlack);

    //x轴
    painter.drawLine(pointx,pointy,width+pointx+20,pointy);
    painter.drawLine(width+pointx+20,pointy,width+pointx+12,pointy-8);
    painter.drawLine(width+pointx+20,pointy,width+pointx+12,pointy+8);

    //y轴
    painter.drawLine(pointx,pointy-height-20,pointx,pointy+height+20);
    painter.drawLine(pointx,pointy-height-20,pointx+8,pointy-height-12);
    painter.drawLine(pointx,pointy-height-20,pointx-8,pointy-height-12);

    // y轴，刻度
    for(int i=-6;i<-1;i++)
    {
        painter.drawText(pointx-30,pointy-(i+1)*height/5,QString::number((30*(i+1))));
    }
    for(int i=0;i<5;i++)
    {
        painter.drawText(pointx-30,pointy-(i+1)*height/5,QString::number((30*(i+1))));
    }
    painter.drawText(pointx-40,pointy-height-20,QString("V/mv"));

    //x轴，刻度
    for(int i=-1;i<10;i++)
    {
        painter.drawText((pointx+3)+(i+1)*width/10,pointy+20,QString::number(((i+1)*(90))));
    }
    painter.drawText(pointx+width+25,pointy+10,QString("t/s"));

    //画网格线
    penDot.setStyle(Qt::DotLine);
    penDot.setWidth(1);
    penDot.setColor(Qt::blue);
    painter.setPen(penDot);

    //x轴线方向，网格线
    for(int i=-6;i<5;i++)
    {
        painter.drawLine(pointx,pointy-(i+1)*height/5,pointx+width+20,pointy-(i+1)*height/5);

    }

    // y轴线方向，网格线
    for(int i=0;i<10;i++)
    {
        painter.drawLine(pointx+(i+1)*width/10,pointy,pointx+(i+1)*width/10,pointy+height+20);
        painter.drawLine(pointx+(i+1)*width/10,pointy,pointx+(i+1)*width/10,pointy-height-20);
    }
}

