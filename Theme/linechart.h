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
    void startFlow1Line();
    void stopFlow1Line();
    void startFlow2Line();
    void stopFlow2Line();
    void startAll();
    void stopAll();
    void updatePressData(const QVector<double>& pressDataList);
    void updateWaterData(const QVector<double>& waterDataList);
    void updateFlow1Data(const QVector<double>& flow1DataList);
    void updateFlow2Data(const QVector<double>& flow2DataList);

private:
    QChart* chart;
    QLineSeries* pressLine;
    QLineSeries* flow1Line;
    QLineSeries* flow2Line;
    QLineSeries* waterLine;
    QValueAxis* axisX;
    QValueAxis* axisY;
    QChartView* view;
    bool waterLineInChart,flow1LineInChart,pressLineInChart,flow2LineInChart;

    int axisXStart;
};

#endif // LINECHART_H
