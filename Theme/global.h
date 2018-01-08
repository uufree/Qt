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
    double timeMin;
    double timeMax;
    double valueMin;
    double valueMax;
};

typedef std::function<void()> FixCurrentMessageCallBack;

#endif
