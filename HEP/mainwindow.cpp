#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "window.h"
/**
 * @brief MainWindow::MainWindow
 * @param parent
 * 登录窗口
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置标题
    setWindowTitle("自发极化性能测试系统");

    //隐藏textEdit变边框
    ui->textEdit->setStyleSheet("background:transparent; border-width:0; border-style:outset");

    //发送信号显示子窗口
    connect(ui->StartButton, &QPushButton::released, this, &MainWindow::changeWindon);


}

//槽函数
void MainWindow::changeWindon()
{
    //显示子窗口
    Window.show();
    //隐藏主窗口
    this->hide();
}

MainWindow::~MainWindow()
{

    delete ui;
}
