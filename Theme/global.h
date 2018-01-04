#ifndef GLOBAL_H
#define GLOBAL_H

#include<QString>
#include<QMutex>

struct LineChartsSetting
{
    QString pressLineColor;
    QString flowLineColor;
    QString waterLevelColor;
};

struct PressData
{
    double press;
    QMutex mutex;
};

struct FlowData
{
    double flow;
    QMutex mutex;
};

struct WaterLevel
{
    double waterLevel;
    QMutex mutex;
};

#endif // GLOBAL_H
