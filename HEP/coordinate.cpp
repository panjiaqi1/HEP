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
    this->bottom = bottom ;
    this->left = left;
    this->width = 640;
    this->height = 140;
    this->shareX = 20;
    this->shareY = 5;
    this->coordinateX = "X";
    this->coordinateY = "Y";
    this->positiveX = 5;
    this->negativeX = -5;
    this->positiveY = 30;
    this->negativeY = -30;
}

// x轴刻度长度
void Coordinate::setWidth(int width) {
    this->width = width;
}

// y轴刻度长度
void Coordinate::setHeight(int height) {
    this->height = height;
}

// x轴标题
void Coordinate::setCoordinateX(QString coordinateX) {
    this->coordinateX = coordinateX;
}
// y轴标题
void Coordinate::setCoordinateY(QString coordinateY) {
    this->coordinateY = coordinateY;
}

// x轴份数
void Coordinate::setShareX(int shareX) {
    this->shareX = shareX;
}

// y轴份数
void Coordinate::setShareY(int shareY) {
    this->shareY = shareY;
}

// x轴正半轴刻度系数
void Coordinate::setPositiveX(int positiveX) {
    this->positiveX = positiveX;
}

// x轴负半轴刻度系数
void Coordinate::setNegativeX(int negativeX) {
    this->negativeX = negativeX;
}

// y轴正半轴刻度系数
void Coordinate::setPositiveY(int positiveY) {
    this->positiveY = positiveY;
}

// y轴负半轴刻度系数
void Coordinate::setNegativeY(int negativeY) {
    this->negativeY = negativeY;
}

// 建立坐标系
void Coordinate::render(QImage *qImage) {
    QPainter painter(qImage);

    // 设置反锯齿模式
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 确定坐标轴宽度跟高度
    int width = this->width - originPoint->getX();

    // 画x，y轴
    QPen penBlack, penBlue;
    penBlack.setWidth(3);
    painter.setPen(penBlack);

    // x轴,正半轴
    painter.drawLine(originPoint->getX(),
                     originPoint->getY(),
                     originPoint->getX() + right,
                     originPoint->getY());

    // x轴箭头
    painter.drawLine( originPoint->getX() + right,
                      originPoint->getY(),
                      originPoint->getX() + right - 12,
                      originPoint->getY() - 8);
    painter.drawLine(originPoint->getX() + right,
                     originPoint->getY(),
                     originPoint->getX() + right - 12,
                     originPoint->getY() + 8);

    // x轴，负半轴
    painter.drawLine(originPoint->getX(),
                     originPoint->getY(),
                     originPoint->getX() - left,
                     originPoint->getY());

    // y轴,正半轴
    painter.drawLine(originPoint->getX(),
                     originPoint->getY(),
                     originPoint->getX(),
                     originPoint->getY() - top);
    // y轴箭头
    painter.drawLine(originPoint->getX(),
                     originPoint->getY() - top,
                     originPoint->getX() + 8,
                     originPoint->getY() - top + 12);
    painter.drawLine(originPoint->getX(),
                     originPoint->getY() - top,
                     originPoint->getX() - 8,
                     originPoint->getY() - top + 12);
    // y轴，负半轴
    painter.drawLine(originPoint->getX(),
                     originPoint->getY(),
                     originPoint->getX(),
                     originPoint->getY() + bottom);

    // y轴, 正半轴刻度
    for (int i=0; i<shareY; i++) {
        painter.drawText(originPoint->getX() - 30,
                         originPoint->getY() - (i + 1) * height/shareY,
                         QString::number((positiveY * (i + 1))));
    }

    // y轴标题
    painter.drawText(originPoint->getX() - 30,
                     originPoint->getY() - top,
                     QString(coordinateY));

    // y轴, 负半轴刻度
    if (bottom != 0) {
        for (int i=0; i<shareY; i++) {
            painter.drawText(originPoint->getX() - 30,
                             originPoint->getY() + (i + 1) * height/shareY,
                             QString::number((negativeY * (i + 1))));
        }
    }


    // x轴，正半轴刻度
    for (int i=-1; i<shareX; i++) {
        painter.drawText((originPoint->getX() + 3) + (i + 1) * width/shareX,
                         originPoint->getY() + 15,
                         QString::number((positiveX * (i + 1))));
    }

    // x轴标题
    painter.drawText(originPoint->getX() + width + 25,
                     originPoint->getY() + 10,
                     QString(coordinateX));


    // x轴，负半轴刻度
    if (left != 0) {
        for(int i=-1; i<shareX; i++) {
            painter.drawText((originPoint->getX() + 3) - (i + 1) * width/shareX,
                             originPoint->getY() + 15,
                             QString::number((negativeX * (i + 1))));
        }
    }


    // 画网格线
    penBlue.setStyle(Qt::DotLine);
    penBlue.setWidth(2);
    penBlue.setColor(Qt::blue);
    painter.setPen(penBlue);

    // 一象限网格线
    if (left == 0 && bottom == 0) {
        for (int i=0; i<shareY; i++) {
            painter.drawLine(originPoint->getX(),
                             originPoint->getY() - (i + 1) * height/shareY,
                             originPoint->getX() + right,
                             originPoint->getY() - (i + 1) * height/shareY);
        }
        for (int i=0; i<shareX; i++){
            painter.drawLine(originPoint->getX() + (i + 1) * width/shareX,
                             originPoint->getY(),
                             originPoint->getX() + (i + 1) * width/shareX,
                             originPoint->getY() - top);
        }
    }

    // 一、 二象限网格线
    if (left != 0 && bottom ==0) {
        for (int i = 0; i<shareY; i++) {
            painter.drawLine(originPoint->getX(),
                             originPoint->getY() - (i + 1) * height/shareY,
                             originPoint->getX() + right,
                             originPoint->getY() - (i + 1) * height/shareY);

            painter.drawLine(originPoint->getX(),
                             originPoint->getY() - (i + 1) * height/shareY,
                             originPoint->getX() - left,
                             originPoint->getY() - (i + 1) * height/shareY);


        }
        for (int i=0; i<shareX; i++) {
            painter.drawLine(originPoint->getX() + (i + 1) * width/shareX,
                             originPoint->getY(),
                             originPoint->getX() + (i + 1) * width/shareX,
                             originPoint->getY() - top);

            painter.drawLine(originPoint->getX() - (i + 1) * width/shareX,
                             originPoint->getY(),
                             originPoint->getX() - (i + 1) * width/shareX,
                             originPoint->getY() - top);
        }
    }

    // 一、四象限网格线
    if (left ==0 && bottom !=0) {
        for (int i = 0; i<shareY; i++) {
            painter.drawLine(originPoint->getX(),
                             originPoint->getY() - (i + 1) * height/shareY,
                             originPoint->getX() + right,
                             originPoint->getY() - (i + 1) * height/shareY);

            painter.drawLine(originPoint->getX(),
                             originPoint->getY() + (i + 1) * height/shareY,
                             originPoint->getX() + right,
                             originPoint->getY() + (i + 1) * height/shareY);


        }
        for (int i=0; i<shareX; i++) {
            painter.drawLine(originPoint->getX() + (i + 1) * width/shareX,
                             originPoint->getY(),
                             originPoint->getX() + (i + 1) * width/shareX,
                             originPoint->getY() - top);

            painter.drawLine(originPoint->getX() + (i + 1) * width/shareX,
                             originPoint->getY(),
                             originPoint->getX() + (i + 1) * width/shareX,
                             originPoint->getY() + bottom);
        }
    }

    // 一、二、三、四象限网格线
    if (left !=0 && bottom !=0) {
        for (int i = 0; i<shareY; i++) {
            painter.drawLine(originPoint->getX(),
                             originPoint->getY() - (i + 1) * height/shareY,
                             originPoint->getX() + right,
                             originPoint->getY() - (i + 1) * height/shareY);

            painter.drawLine(originPoint->getX(),
                             originPoint->getY() + (i + 1) * height/shareY,
                             originPoint->getX() + right,
                             originPoint->getY() + (i + 1) * height/shareY);

            painter.drawLine(originPoint->getX(),
                             originPoint->getY() - (i + 1) * height/shareY,
                             originPoint->getX() - left,
                             originPoint->getY() - (i + 1) * height/shareY);

            painter.drawLine(originPoint->getX(),
                             originPoint->getY() + (i + 1) * height/shareY,
                             originPoint->getX() - left,
                             originPoint->getY() + (i + 1) * height/shareY);
        }
        for (int i=0; i<shareX; i++) {
            painter.drawLine(originPoint->getX() + (i + 1) * width/shareX,
                             originPoint->getY(),
                             originPoint->getX() + (i + 1) * width/shareX,
                             originPoint->getY() - top);

            painter.drawLine(originPoint->getX() - (i + 1) * width/shareX,
                             originPoint->getY(),
                             originPoint->getX() - (i + 1) * width/shareX,
                             originPoint->getY() - top);
            painter.drawLine(originPoint->getX() + (i + 1) * width/shareX,
                             originPoint->getY(),
                             originPoint->getX() + (i + 1) * width/shareX,
                             originPoint->getY() + bottom);

            painter.drawLine(originPoint->getX() - (i + 1) * width/shareX,
                             originPoint->getY(),
                             originPoint->getX() - (i + 1) * width/shareX,
                             originPoint->getY() + bottom);
        }
    }
}

