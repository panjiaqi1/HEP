#include <QImage>
#include <QPainter>
#include "Coordinate.h"

/**
 * @brief Coordinate::Coordinate
 * 二维坐标系
 */

Coordinate::Coordinate()
{
    Coordinate(new Point(), 0);
}

Coordinate::Coordinate(Point *point, int top) {
    Coordinate(point, top, top, top, top);
}

Coordinate::Coordinate(Point *point, int top, int right) {
    Coordinate(point, top, right, top, right);
}

Coordinate::Coordinate(Point *point, int top, int right, int bottom) {
    Coordinate(point, top, right, bottom, right);
}

Coordinate::Coordinate(Point *point, int top, int right, int bottom, int left) {
    this->originPoint = point;
    this->top = top;
    this->right = right;
    this->bottom = bottom;
    this->left = left;
    this->width = 640;
    this->height = 140;
}

void Coordinate::setWidth(int width) {
    this->width = width;
}

void Coordinate::setHeight(int height) {
    this->height = height;
}

void Coordinate::render(QImage *qImage) {
    QPainter painter(qImage);

    //设置反锯齿模式
    painter.setRenderHint(QPainter::Antialiasing, true);

    //确定坐标轴宽度跟高度
    int width = this->width - originPoint->getX();

    //画x，y轴
    QPen penBlack, penBlue;
    penBlack.setWidth(3);
    painter.setPen(penBlack);

    //x轴
    painter.drawLine(originPoint->getX(),
                     originPoint->getY(),
                     width + originPoint->getX() + 20,
                     originPoint->getY());
    painter.drawLine(width + originPoint->getX() + 20,
                     originPoint->getY(),
                     width + originPoint->getX() + 12,
                     originPoint->getY() - 8);
    painter.drawLine(width + originPoint->getX() + 20,
                     originPoint->getY(),
                     width + originPoint->getX() + 12,
                     originPoint->getY() + 8);

    //y轴
    painter.drawLine(originPoint->getX(),
                     originPoint->getY() - height - 20,
                     originPoint->getX(),
                     originPoint->getY() + height + 20);
    painter.drawLine(originPoint->getX(),
                     originPoint->getY() - height - 20,
                     originPoint->getX() + 8,
                     originPoint->getY() - height - 12);
    painter.drawLine(originPoint->getX(),
                     originPoint->getY() - height - 20,
                     originPoint->getX() - 8,
                     originPoint->getY() - height - 12);

    // y轴，刻度
    for(int i=-6; i<-1; i++)
    {
        painter.drawText(originPoint->getX() - 30, originPoint->getY() - (i + 1) * height/5, QString::number((30 * (i + 1))));
    }
    for(int i=0; i<5; i++)
    {
        painter.drawText(originPoint->getX() - 30, originPoint->getY() - (i + 1) * height/5, QString::number((30 * (i + 1))));
    }
    painter.drawText(originPoint->getX() - 40, originPoint->getY() - height - 20, QString("V/mv"));

    //x轴，刻度
    for(int i=-1; i<20; i++)
    {
        painter.drawText((originPoint->getX() + 3) + (i + 1) * width/20, originPoint->getY() + 20, QString::number((5 * (i + 1))));
    }
    painter.drawText(originPoint->getX() + width + 25, originPoint->getY() + 10, QString("T/℃"));

    //画网格线
    penBlue.setStyle(Qt::DotLine);
    penBlue.setWidth(1);
    penBlue.setColor(Qt::blue);
    painter.setPen(penBlue);

    //x轴线方向，网格线
    for(int i=-6; i<5; i++)
    {
        painter.drawLine(originPoint->getX(), originPoint->getY() - (i + 1) * height/5, originPoint->getX() + width + 20, originPoint->getY() - (i + 1) * height/5);

    }

    // y轴线方向，网格线
    for(int i=0; i<20; i++)
    {
        painter.drawLine(originPoint->getX() + (i + 1) * width/20, originPoint->getY(), originPoint->getX() + (i + 1) * width/20, originPoint->getY() + height + 20);
        painter.drawLine(originPoint->getX() + (i + 1) * width/20, originPoint->getY(), originPoint->getX() + (i + 1) * width/20, originPoint->getY() - height - 20);
    }
}

