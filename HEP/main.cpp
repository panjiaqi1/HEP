#include "mainwindow.h"
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
    MainWindow w;
    w.show();

    return a.exec();
}
