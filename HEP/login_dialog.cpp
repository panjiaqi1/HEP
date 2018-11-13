#include "login_dialog.h"
#include "ui_login_dialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    //设置标题
    setWindowTitle("自发极化性能测试系统");

    //隐藏textEdit变边框
    ui->textEdit->setStyleSheet("background:transparent; border-width:0; border-style:outset");

    //发送信号显示子窗口
    connect(ui->StartButton, &QPushButton::released, this, &LoginDialog::showImageWindow);
}

//点击触发showImageWindow函数
void LoginDialog::showImageWindow()
{
    //显示子窗口
    imageWindow.start();
    //隐藏主窗口
    this->hide();
}


LoginDialog::~LoginDialog()
{
    delete ui;
}
