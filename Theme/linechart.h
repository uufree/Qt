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

    void resizeView(int x, int y);

    void setting(const struct SettingData& settingData);
    void startPressLine();
    void stopPressLine();
    void startWaterLine();
    void stopWaterLine();
    void startFlowLine();
    void stopFlowLine();
    void startAll();
    void stopAll();
    void clearAll();
    void updatePressData(const QVector<double>& pressDataList);
    void updateWaterData(const QVector<double>& waterDataList);
    void updateFlowData(QVector<double>& flowDataList);

private:
    QChart* chart;
    QLineSeries* pressLine;
    QLineSeries* flowLine;
    QLineSeries* waterLine;
    QValueAxis* axisX;
    QValueAxis* axisY;
    QChartView* view;
};

#endif // LINECHART_H
