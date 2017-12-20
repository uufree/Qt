#ifndef GLOBAL_H
#define GLOBAL_H

#include<QString>

struct SettingData
{
    QString portName;
    QString baud;
    QString pollTime;
    QString cupSpeed;
    QString testArea;
    QString cupCount;
};

enum CUP_STATE
{
    RUNING,
    STOP,
    ERROR
};

#endif // GLOBAL_H
