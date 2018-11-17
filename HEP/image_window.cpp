#include "image_window.h"
#include "ui_image_window.h"

/**
 * @brief ImageWindow::ImageWindow
 * @param parent
 * 绘图坐标窗口
 */

ImageWindow::ImageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageWindow)
{
    ui->setupUi(this);

    // 设置标题
    setWindowTitle("自发极化性能测试系统");

    // 点击菜单栏 退出
    connect(ui->Singout, &QAction::triggered, [=](){this->close();});

    // 模态对话框（参数设置）
    connect(ui->Parameter, &QAction::triggered, [=](){parameterDialog.exec();});
}


void ImageWindow::start(){

    // 从服务中获取链表
    CoordinateService *coordinateService = new CoordinateService();
    this->list = coordinateService->getList();

    // 定时器
    Timer = new QTimer(this);

    // 点击开始运行启动定时器
    connect(ui->Start, &QAction::triggered,
            [=]()
    {
        // 判断当前状态是否停止
        if(Timer->isActive() == false){
            Timer->start(300);
        }
    }
    );

    // 点击暂停运行 停止
    connect(ui->Suspend, &QAction::triggered,
            [=]()
    {
        // 判断当前状态是否启动
        if (Timer->isActive() == true){
            Timer->stop();
        }
    }
    );

    // 0.3秒显示一个数
    connect(Timer, &QTimer::timeout,
            [=]()
    {
        if(!list.empty()){
            AccessPoint accessPoint = list.front();
            list.pop_front();
            ui->textEdit->append(accessPoint.toString());
            ui->widget_3->paint(accessPoint);
            ui->widget_4->paint(accessPoint);
            ui->widget_5->paint(accessPoint);
            repaint();
        }
    }
    );

    this->show();
}

ImageWindow::~ImageWindow()
{
    delete ui;
}
