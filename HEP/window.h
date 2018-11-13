#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTimer> //定时器
#include "dialog.h"
#include <QQueue> //队列

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();
    Ui::Window *ui;

private:
    //Ui::Window *ui;
    Dialog Dialog;
    QTimer *Timer;
    QQueue<int> queue;
};


#endif // WINDOW_H
