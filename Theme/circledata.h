#ifndef CIRCLEDATA_H
#define CIRCLEDATA_H

#include<QFrame>
#include<QPalette>
#include<QGridLayout>

#include"dial.h"
#include"global.h"

class CircleData : public QFrame
{
    Q_OBJECT
public:
    CircleData(QWidget* parent = NULL);

    void updatePress(double value)
    {press->setValue(value);}

    void updateWater(double value)
    {water->setValue(value);}

    void updateFlow1(double value)
    {flow1->setValue(value);}

    void updateFlow2(double value)
    {flow2->setValue(value);}

    void pressAlarm()
    {press->alarm();}

    void waterAlarm()
    {water->alarm();}

    void flow1Alarm()
    {flow1->alarm();}

    void flow2Alarm()
    {flow2->alarm();}

    void setWaterRange(int low,int hight)
    {water->setRange(low,hight);}

    void setFlow1Range(int low,int hight)
    {flow1->setRange(low,hight);}

    void setPressRange(int low,int hight)
    {press->setRange(low,hight);}

    void setFlow2Range(int low,int hight)
    {flow2->setRange(low,hight);}

    void setWaterValue(double data)
    {water->setValue(data);}

    void setPressValue(double data)
    {press->setValue(data);}

    void setFlow1Value(double data)
    {flow1->setValue(data);}

    void setFlow2Value(double data)
    {flow2->setValue(data);}

    void setWaterCallBack(const FixCurrentMessageCallBack& callBack_)
    {water->setFixCurrentMessageCallBack(callBack_);}

    void setFlow1CallBack(const FixCurrentMessageCallBack& callBack_)
    {flow1->setFixCurrentMessageCallBack(callBack_);}

    void setFlow2CallBack(const FixCurrentMessageCallBack& callBack_)
    {flow2->setFixCurrentMessageCallBack(callBack_);}

    void setPressCallBack(const FixCurrentMessageCallBack& callBack_)
    {press->setFixCurrentMessageCallBack(callBack_);}

private:
    Dial* createDial(double stepSize,double scale);
    QPalette colorTheme(const QColor&);

private:
    Dial* press;
    Dial* water;
    Dial* flow1;
    Dial* flow2;
};

#endif // CIRCLEDATA_H
