#ifndef GLOBAL_H
#define GLOBAL_H

#include<QString>

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
    int timeMin;
    int timeMax;
    int valueMin;
    int valueMax;
};

#endif
