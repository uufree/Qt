#ifndef GLOBAL_H
#define GLOBAL_H

#include<QString>
#include<functional>
#include<memory>

struct SettingData
{
    QString  acquireStyle;
    int testCount;
    QString waterColor;
    QString flowColor;
    QString pressColor;
    QString waterLineStyle;
    QString flowLineStyle;
    QString pressLineStyle;
    QString baudRate;
    QString serialPort;
    double timeMin;
    double timeMax;
    double valueMin;
    double valueMax;
};

typedef std::function<void()> FixCurrentMessageCallBack;
typedef std::function<void(const struct SettingData& data)> HandleSettingMessageCallBack;
typedef std::function<void(short)> WaterCallBack;
typedef std::function<void(short)> PressCallBack;
typedef std::function<void(float)> FlowCallBack;

#endif
