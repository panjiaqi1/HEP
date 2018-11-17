#ifndef LOGIN_DIALOG_H
#define LOGIN_DIALOG_H

#include <QDialog>
#include "image_window.h"

// 引入LoginDialog界面
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    void showImageWindow();
    ~LoginDialog();

private:
    // LoginDialog界面
    Ui::LoginDialog *ui;
    // imagewindow模块
    ImageWindow imageWindow;
};

#endif // LOGIN_DIALOG_H
