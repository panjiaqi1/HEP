#include "coordinate_service.h"

/**
 * @brief CoordinateService::CoordinateService
 * 获取点的服务
 */

CoordinateService::CoordinateService()
{
    // 创建点保存到链表
    int n=1000;
    for(int i=0; i<n; i++)
    {
        accessPoint = new AccessPoint();
        accessPoint->setTemperature(10+i/10);
        accessPoint->setVoltage(5+0.3*i);
        accessPoint->setSec((0.3 + 0.3*i));
        list.push_back(*accessPoint);
    }
}


QList<AccessPoint> CoordinateService::getList()
{
    return list;
}

