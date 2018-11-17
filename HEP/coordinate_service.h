#ifndef SERVICE_H
#define SERVICE_H


#include <QList>
#include "access_point.h"

/**
 * @brief The CoordinateService class
 * 获取点的服务
 */

class CoordinateService
{
public:
    CoordinateService();
    QList<AccessPoint> getList();
private:
    AccessPoint *accessPoint; // 获取的点（温度 电压 时间）
    QList<AccessPoint> list;  // 创建链表
};



#endif // SERVICE_H
