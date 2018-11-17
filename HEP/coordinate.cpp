#include "coordinate.h"

/**
 * @brief Coordinate::Coordinate
 * 二维坐标系
 */

Coordinate::Coordinate()
{
    Coordinate QPoint;
}

Coordinate::Coordinate(QPoint point, int top) {
    Coordinate(point, top, top, top, top);
}

Coordinate::Coordinate(QPoint point, int top, int right) {
    Coordinate(point, top, right, top, right);
}

Coordinate::Coordinate(QPoint point, int top, int right, int bottom) {
    Coordinate(point, top, right, bottom, right);
}

Coordinate::Coordinate(QPoint point, int top, int right, int bottom, int left) {
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

void Coordinate::addpoint(QPointF *addPoint) {

    // x轴比例系数
    qreal ratioX = addPoint->x() * (width - originPoint.x())/shareX/positiveX;

    // y轴比例系数
    qreal ratioY = addPoint->y() * height/shareY/positiveY;

    addPoint->setX(originPoint.x() + ratioX);
    addPoint->setY(originPoint.y() - ratioY);

    pointPen.setColor(Qt::green);
    pointPen.setWidth(3);
    this->painter->setPen(pointPen);
    // 画点
    painter->drawPoint(*addPoint);
}

// 建立坐标系
void Coordinate::render(QImage *qImage) {

    int lengthX = 12, lengthY = 8, distanceX = 30, distanceY = 3;

    this->painter = new QPainter(qImage);

    // 设置反锯齿模式
    painter->setRenderHint(QPainter::Antialiasing, true);

    // 确定坐标轴宽度跟高度
    int width = this->width - originPoint.x();

    // 画x，y轴

    penBlack.setWidth(3);
    painter->setPen(penBlack);

    // x轴,正半轴
    painter->drawLine(originPoint.x(),
                      originPoint.y(),
                      originPoint.x() + right,
                      originPoint.y());

    // x轴箭头
    painter->drawLine( originPoint.x() + right,
                       originPoint.y(),
                       originPoint.x() + right - lengthX,
                       originPoint.y() - lengthY);
    painter->drawLine(originPoint.x() + right,
                      originPoint.y(),
                      originPoint.x() + right - lengthX,
                      originPoint.y() + lengthY);

    // x轴，负半轴
    painter->drawLine(originPoint.x(),
                      originPoint.y(),
                      originPoint.x() - left,
                      originPoint.y());

    // y轴,正半轴
    painter->drawLine(originPoint.x(),
                      originPoint.y(),
                      originPoint.x(),
                      originPoint.y() - top);
    // y轴箭头
    painter->drawLine(originPoint.x(),
                      originPoint.y() - top,
                      originPoint.x() + lengthY,
                      originPoint.y() - top + lengthX);

    painter->drawLine(originPoint.x(),
                      originPoint.y() - top,
                      originPoint.x() - lengthY,
                      originPoint.y() - top + lengthX);

    // y轴，负半轴
    painter->drawLine(originPoint.x(),
                      originPoint.y(),
                      originPoint.x(),
                      originPoint.y() + bottom);


    // y轴, 正半轴刻度
    for (int i=0; i<shareY; i++) {
        painter->drawText(originPoint.x() - distanceX,
                          originPoint.y() - (i + 1) * height/shareY,
                          QString::number((positiveY * (i + 1))));
    }

    // y轴标题
    painter->drawText(originPoint.x() - distanceX,
                      originPoint.y() - top,
                      QString(coordinateY));

    // y轴, 负半轴刻度
    if (bottom != 0) {
        for (int i=0; i<shareY; i++) {
            painter->drawText(originPoint.x() - distanceX,
                              originPoint.y() + (i + 1) * height/shareY,
                              QString::number((negativeY * (i + 1))));
        }
    }


    // x轴，正半轴刻度
    for (int i=-1; i<shareX; i++) {
        painter->drawText((originPoint.x() + distanceY) + (i + 1) * width/shareX,
                          originPoint.y() + lengthX,
                          QString::number((positiveX * (i + 1))));
    }

    // x轴标题
    painter->drawText(originPoint.x() + right + lengthY,
                      originPoint.y() + lengthX,
                      QString(coordinateX));


    // x轴，负半轴刻度
    if (left != 0) {
        for(int i=-1; i<shareX; i++) {
            painter->drawText((originPoint.x() + distanceY) - (i + 1) * width/shareX,
                              originPoint.y() + lengthX,
                              QString::number((negativeX * (i + 1))));
        }
    }


    // 画网格线
    penBlue.setStyle(Qt::DotLine);
    penBlue.setWidth(2);
    penBlue.setColor(Qt::blue);
    painter->setPen(penBlue);

    // 一象限网格线
    if (left == 0 && bottom == 0) {
        for (int i=0; i<shareY; i++) {
            painter->drawLine(originPoint.x(),
                              originPoint.y() - (i + 1) * height/shareY,
                              originPoint.x() + right,
                              originPoint.y() - (i + 1) * height/shareY);
        }
        for (int i=0; i<shareX; i++){
            painter->drawLine(originPoint.x() + (i + 1) * width/shareX,
                              originPoint.y(),
                              originPoint.x() + (i + 1) * width/shareX,
                              originPoint.y() - top);
        }
    }

    // 一、 二象限网格线
    if (left != 0 && bottom == 0) {
        for (int i = 0; i<shareY; i++) {
            painter->drawLine(originPoint.x(),
                              originPoint.y() - (i + 1) * height/shareY,
                              originPoint.x() + right,
                              originPoint.y() - (i + 1) * height/shareY);

            painter->drawLine(originPoint.x(),
                              originPoint.y() - (i + 1) * height/shareY,
                              originPoint.x() - left,
                              originPoint.y() - (i + 1) * height/shareY);


        }
        for (int i=0; i<shareX; i++) {
            painter->drawLine(originPoint.x() + (i + 1) * width/shareX,
                              originPoint.y(),
                              originPoint.x() + (i + 1) * width/shareX,
                              originPoint.y() - top);

            painter->drawLine(originPoint.x() - (i + 1) * width/shareX,
                              originPoint.y(),
                              originPoint.x() - (i + 1) * width/shareX,
                              originPoint.y() - top);
        }
    }

    // 一、四象限网格线
    if (left == 0 && bottom != 0) {
        for (int i = 0; i<shareY; i++) {
            painter->drawLine(originPoint.x(),
                              originPoint.y() - (i + 1) * height/shareY,
                              originPoint.x() + right,
                              originPoint.y() - (i + 1) * height/shareY);

            painter->drawLine(originPoint.x(),
                              originPoint.y() + (i + 1) * height/shareY,
                              originPoint.x() + right,
                              originPoint.y() + (i + 1) * height/shareY);


        }
        for (int i=0; i<shareX; i++) {
            painter->drawLine(originPoint.x() + (i + 1) * width/shareX,
                              originPoint.y(),
                              originPoint.x() + (i + 1) * width/shareX,
                              originPoint.y() - top);

            painter->drawLine(originPoint.x() + (i + 1) * width/shareX,
                              originPoint.y(),
                              originPoint.x() + (i + 1) * width/shareX,
                              originPoint.y() + bottom);
        }
    }

    // 一、二、三、四象限网格线
    if (left !=0 && bottom != 0) {
        for (int i = 0; i<shareY; i++) {
            painter->drawLine(originPoint.x(),
                              originPoint.y() - (i + 1) * height/shareY,
                              originPoint.x() + right,
                              originPoint.y() - (i + 1) * height/shareY);

            painter->drawLine(originPoint.x(),
                              originPoint.y() + (i + 1) * height/shareY,
                              originPoint.x() + right,
                              originPoint.y() + (i + 1) * height/shareY);

            painter->drawLine(originPoint.x(),
                              originPoint.y() - (i + 1) * height/shareY,
                              originPoint.x() - left,
                              originPoint.y() - (i + 1) * height/shareY);

            painter->drawLine(originPoint.x(),
                              originPoint.y() + (i + 1) * height/shareY,
                              originPoint.x() - left,
                              originPoint.y() + (i + 1) * height/shareY);
        }
        for (int i=0; i<shareX; i++) {
            painter->drawLine(originPoint.x() + (i + 1) * width/shareX,
                              originPoint.y(),
                              originPoint.x() + (i + 1) * width/shareX,
                              originPoint.y() - top);

            painter->drawLine(originPoint.x() - (i + 1) * width/shareX,
                              originPoint.y(),
                              originPoint.x() - (i + 1) * width/shareX,
                              originPoint.y() - top);
            painter->drawLine(originPoint.x() + (i + 1) * width/shareX,
                              originPoint.y(),
                              originPoint.x() + (i + 1) * width/shareX,
                              originPoint.y() + bottom);

            painter->drawLine(originPoint.x() - (i + 1) * width/shareX,
                              originPoint.y(),
                              originPoint.x() - (i + 1) * width/shareX,
                              originPoint.y() + bottom);
        }
    }
}

