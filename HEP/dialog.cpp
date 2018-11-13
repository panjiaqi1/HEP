#include "dialog.h"
#include "ui_dialog.h"
/**
 * @brief Dialog::Dialog
 * @param parent
 * 参数设置窗口
 */

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //设置标题
    setWindowTitle("参数设置");
}

Dialog::~Dialog()
{
    delete ui;
}
