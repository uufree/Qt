#ifndef LINECHART_H
#define LINECHART_H

#include<QtCharts/QLineSeries>
#include<QtCharts/QChart>
#include<QtCharts/QValueAxis>
#include<QtCharts/QChartView>
#include<QVector>
#include<QPointF>
#include<QTimer>

#include"global.h"

using namespace QtCharts;

class LineChart : public QWidget
{
    Q_OBJECT
public:
    LineChart(QWidget* widget = NULL);

    void resize(int x, int y)
    {
        view->resize(x,y);
    }

public slots:
//    void handleLineSetting();//处理设置信息
    void updateLineChart();
    void start();//开始

private:
    QChart* chart;
    QLineSeries* pressLine;
    QLineSeries* flowLine;
    QLineSeries* waterLine;
    QValueAxis* axisX;
    QValueAxis* axisY;
    QChartView* view;
    QVector<double> pressDataList;
    QVector<double> flowDataList;
    QVector<double> waterDataList;
    QTimer* timer;
};

#endif // LINECHART_H
