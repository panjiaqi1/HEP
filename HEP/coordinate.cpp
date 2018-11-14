#include "coordinate.h"
/*
 *温度、电压坐标轴
 * */
Coordinate::Coordinate(QWidget *parent) : QWidget(parent)
{
    //画布的初始化大小设为800*500
    image = QImage(800, 500, QImage::Format_RGB32);
    //画布初始化背景色使用白色
    QColor backColor = qRgb(255, 255, 255);
    //对画布进行填充
    image.fill(backColor);


    Paint();
}

<<<<<<< HEAD
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
=======
//绘制坐标轴
void Coordinate::Paint(){
    QPainter painter(&image);
>>>>>>> parent of 0db38bc... 代码重构

    // 设置反锯齿模式
    painter.setRenderHint(QPainter::Antialiasing, true);

<<<<<<< HEAD
    // 确定坐标轴宽度跟高度
    int width = this->width - originPoint->getX();
=======
    //确定坐标轴起点坐标
    int pointx=40, pointy=180;

    //确定坐标轴宽度跟高度
    int width=640 - pointx, height=140;
>>>>>>> parent of 0db38bc... 代码重构

    // 画x，y轴
    QPen penBlack, penBlue;
    penBlack.setWidth(3);
    painter.setPen(penBlack);

<<<<<<< HEAD
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
=======
    //x轴
    painter.drawLine(pointx, pointy, width + pointx + 20, pointy);
    painter.drawLine(width + pointx + 20, pointy, width + pointx + 12, pointy - 8);
    painter.drawLine(width + pointx + 20, pointy, width + pointx + 12, pointy + 8);

    //y轴
    painter.drawLine(pointx, pointy - height - 20, pointx, pointy + height + 20);
    painter.drawLine(pointx, pointy - height - 20, pointx + 8, pointy - height - 12);
    painter.drawLine(pointx, pointy - height - 20, pointx - 8, pointy - height - 12);

    // y轴，刻度
    for(int i=-6; i<-1; i++)
    {
        painter.drawText(pointx - 30, pointy - (i + 1) * height/5, QString::number((30 * (i + 1))));
    }
    for(int i=0; i<5; i++)
    {
        painter.drawText(pointx - 30, pointy - (i + 1) * height/5, QString::number((30 * (i + 1))));
    }
    painter.drawText(pointx - 40, pointy - height - 20, QString("V/mv"));

    //x轴，刻度
    for(int i=-1; i<20; i++)
    {
        painter.drawText((pointx + 3) + (i + 1) * width/20, pointy + 20, QString::number((5 * (i + 1))));
    }
    painter.drawText(pointx + width + 25, pointy + 10, QString("T/℃"));
>>>>>>> parent of 0db38bc... 代码重构


    // 画网格线
    penBlue.setStyle(Qt::DotLine);
    penBlue.setWidth(2);
    penBlue.setColor(Qt::blue);
    painter.setPen(penBlue);

<<<<<<< HEAD
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

=======
    //x轴线方向，网格线
    for(int i=-6; i<5; i++)
    {
        painter.drawLine(pointx, pointy - (i + 1) * height/5, pointx + width + 20, pointy - (i + 1) * height/5);
>>>>>>> parent of 0db38bc... 代码重构

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

<<<<<<< HEAD
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
=======
    // y轴线方向，网格线
    for(int i=0; i<20; i++)
    {
        painter.drawLine(pointx + (i + 1) * width/20, pointy, pointx + (i + 1) * width/20, pointy + height + 20);
        painter.drawLine(pointx + (i + 1) * width/20, pointy, pointx + (i + 1) * width/20, pointy - height - 20);
>>>>>>> parent of 0db38bc... 代码重构
    }

}
