#ifndef COORDINATE_H
#define COORDINATE_H

#include <QWidget>
#include <QPaintEvent> //绘画事件
#include <QPainter>
#include <QtGui>       //引入用到的控件

class Coordinate : public QWidget
{
    Q_OBJECT
public:
<<<<<<< HEAD
    Coordinate();
    Coordinate(Point*, int);
    Coordinate(Point*, int, int);
    Coordinate(Point*, int, int, int);
    Coordinate(Point*, int, int, int, int);
    void setWidth(int);               //x轴刻度长度
    void setHeight(int);              //y轴刻度长度
    void setShareX(int);              // x轴份数
    void setShareY(int);              // y轴份数
    void setPositiveX(int);           // x轴正半轴刻度系数
    void setNegativeX(int);           // x轴负半轴刻度系数
    void setPositiveY(int);           // y轴正半轴刻度系数
    void setNegativeY(int);           // y轴负半轴刻度系数
    void setCoordinateX(QString);     //x轴标题
    void setCoordinateY(QString);     //y轴标题
    void render(QImage*);
private:
    int top, right, bottom, left, width, height, shareX, shareY, positiveX, negativeX, positiveY, negativeY;
    QString coordinateX, coordinateY;
    Point *originPoint;
=======
    explicit Coordinate(QWidget *parent = nullptr);
    void Paint();

signals:

public slots:

private:
    QImage image;

protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }
>>>>>>> parent of 0db38bc... 代码重构
};

#endif // COORDINATE_H
