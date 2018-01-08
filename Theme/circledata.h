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

    void updatePress(double value);
    void updateWater(double value);
    void updateFlow(double value);

    void pressAlarm();
    void waterAlarm();
    void flowAlarm();

    void setWaterRange(int low,int hight)
    {water->setRange(low,hight);}

    void setFlowRange(int low,int hight)
    {flow->setRange(low,hight);}

    void setPressRange(int low,int hight)
    {press->setRange(low,hight);}

    void setWaterValue(double data)
    {water->setValue(data);}

    void setPressValue(double data)
    {press->setValue(data);}

    void setFlowValue(double data)
    {flow->setValue(data);}

private:
    Dial* createDial(double stepSize,double scale);
    QPalette colorTheme(const QColor&);

private:
    Dial* press;
    Dial* water;
    Dial* flow;
};

#endif // CIRCLEDATA_H
