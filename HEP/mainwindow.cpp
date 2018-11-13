#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "window.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("自发极化性能测试系统");
    ui->textEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");

    //发送信号显示子窗口
    connect(ui->StartButton, &QPushButton::released, this, &MainWindow::changeWindon);


}

void MainWindow::changeWindon()
{
    Window.show();
    this->hide();
}

MainWindow::~MainWindow()
{

    delete ui;
}
