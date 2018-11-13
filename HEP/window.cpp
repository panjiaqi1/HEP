#include "window.h"
#include "ui_window.h"
#include <QDebug>
#include <QTextEdit>
/**
 * @brief Window::Window
 * @param parent
 * 绘制坐标窗口
 */

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    //创建队列
    srand( static_cast<unsigned int>(time(nullptr)));
    int n=50;
    for(int i=0; i<n; i++)
    {
        queue.enqueue(qrand()%100);
        qDebug() << queue;
    }

    ui->setupUi(this);

    //设置标题
    setWindowTitle("自发极化性能测试系统");

    //点击菜单栏 退出
    connect(ui->Singout, &QAction::triggered, [=](){this->close();});

    //模态对话框（参数设置）
    connect(ui->Parameter, &QAction::triggered, [=](){Dialog.exec();});

    //定时器
    Timer = new QTimer(this);

    //点击开始运行启动定时器
    connect(ui->Start, &QAction::triggered,
            [=]()
    {
        //判断当前状态是否停止
        if(Timer->isActive() == false){
            Timer->start(300);
        }
    }
    );

    //点击暂停运行 停止
    connect(ui->Suspend, &QAction::triggered,
            [=]()
    {
        //判断当前状态是否启动
        if (Timer->isActive() == true){
            Timer->stop();
        }
    }
    );

    //0.3秒显示一个数
    connect(Timer, &QTimer::timeout,
            [=]()
    {
        if (!queue.empty())
        {
            QString string = QString::number(queue.dequeue());
            ui->textEdit->append(string);
            qDebug() << string;
            repaint();
        }
    }
    );
}

Window::~Window()
{
    delete ui;
}
