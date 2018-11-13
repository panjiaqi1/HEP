#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTimer> //定时器
#include <QQueue> //队列
#include "parameter_dialog.h"

namespace Ui {
class ImageWindow;
}

class ImageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageWindow(QWidget *parent = nullptr);
    void start();
    ~ImageWindow();


private:
    Ui::ImageWindow *ui;
    ParameterDialog parameterDialog;       //参数设置（模态框对话框）
    QTimer *Timer;                         //定时器
    QQueue<int> queue;                     // 队列
};


#endif // WINDOW_H
