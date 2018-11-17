#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "parameter_dialog.h"
#include "coordinate_service.h"
#include "voltage_temperature_coordinate.h"
#include "voltage_coordinate.h"
#include "temperature_coordinate.h"

/**
 * @brief The ImageWindow class
 * 绘图坐标窗口
 */

namespace Ui {
class ImageWindow;
}

class ImageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageWindow(QWidget *parent = nullptr);
    void start();
    ~ImageWindow();

private:
    Ui::ImageWindow *ui;
    ParameterDialog parameterDialog;       // 参数设置（模态框对话框）
    QTimer *Timer;                         // 定时器
    QList<AccessPoint> list;               // 创建链表
};


#endif // WINDOW_H
