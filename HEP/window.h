#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTimer> //定时器
#include <QQueue> //队列
#include "dialog.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private:
    Ui::Window *ui;
    Dialog Dialog;       //参数设置（模态框对话框）
    QTimer *Timer;       //定时器
    QQueue<int> queue;   // 队列
};


#endif // WINDOW_H
