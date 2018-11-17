#ifndef ACCESS_POINT_H
#define ACCESS_POINT_H
#define FLT_DIG 6

#include <QString>
/**
 * @brief The AccessPoint class
 * 获取的点
 */

class AccessPoint
{
public:
    AccessPoint();
    void setTemperature(int);
    void setVoltage(int);
    void setSec(qreal);
    QString toString();
    int getTemperature();
    int getVoltage();
    qreal getSec();
private:
    int temperature, // 温度
    voltage;         // 电压
    qreal sec;       // 时间（秒）
};

#endif // ACCESS_POINT_H
