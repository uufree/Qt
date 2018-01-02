#ifndef CIRCLEDATA_H
#define CIRCLEDATA_H

#include<QFrame>
#include<QPalette>
#include<QGridLayout>

#include"dial.h"

class CircleData : public QFrame
{
    Q_OBJECT
public:
    CircleData(QWidget* parent = NULL);

public slots:
    void changePress(double value);
    void changeWaterLevel(double value);
    void changeFlow(double value);

private:
    Dial* createDial(double stepSize,double scale);
    QPalette colorTheme(const QColor&);
private:
    Dial* press;
    Dial* waterLevel;
    Dial* flow;
};

#endif // CIRCLEDATA_H
