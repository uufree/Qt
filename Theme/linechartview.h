#ifndef LINECHARTVIEW_H
#define LINECHARTVIEW_H

#include"linechart.h"

class LineChartView : public QChartView
{
    Q_OBJECT
public:
    LineChartView();

protected:
    void show();

private:
    LineChart* chart;
};

#endif // LINECHARTVIEW_H
