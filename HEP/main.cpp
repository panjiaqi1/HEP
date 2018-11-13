#include "login_dialog.h"
#include <QApplication>

/**
 * @brief qMain
 * @param argc
 * @param argv
 * @return
 * 主函数
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog LoginDialog;
    LoginDialog.show();

    return a.exec();
}
