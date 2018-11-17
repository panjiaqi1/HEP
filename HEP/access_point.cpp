#include "access_point.h"

/**
 * @brief AccessPoint::AccessPoint
 * 获取的点
 */


AccessPoint::AccessPoint()
{
    this->sec = 0;
    this->temperature = 0;
    this->voltage = 0;
}

void AccessPoint::setTemperature(int temperture)
{
    this->temperature = temperture;
}

void AccessPoint::setVoltage(int voltage)
{
    this->voltage = voltage;
}

void AccessPoint::setSec(qreal sec)
{
    this->sec = sec;
}

int AccessPoint::getTemperature()
{
    return temperature;
}

int AccessPoint::getVoltage()
{
    return voltage;
}

qreal AccessPoint::getSec()
{
    return sec;
}

QString AccessPoint::toString()
{
    QString string = "temperature: " + QString::number(temperature) + " " +
            "voltage: " + QString::number(voltage) + " " +
            "sec: " + QString::number(sec);
    return  string;
}

