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

private:
    Dial* createDial(double stepSize,double scale);
    QPalette colorTheme(const QColor&);

private:
    Dial* press;
    Dial* water;
    Dial* flow;
};

#endif // CIRCLEDATA_H
