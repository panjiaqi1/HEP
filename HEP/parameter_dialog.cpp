#include "parameter_dialog.h"
#include "ui_parameter_dialog.h"
/**
 * @brief Dialog::Dialog
 * @param parent
 * 参数设置窗口
 */

ParameterDialog::ParameterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParameterDialog)
{
    ui->setupUi(this);

    //设置标题
    setWindowTitle("参数设置");
}

ParameterDialog::~ParameterDialog()
{
    delete ui;
}
