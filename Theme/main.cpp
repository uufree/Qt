#include "mainwindow.h"
#include<QApplication>
#include"circledata.h"
#include<QtCharts/QChart>
#include<QtCharts/QLineSeries>
#include<QtCharts/QChartView>

using namespace QtCharts;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
    MainWindow w;
    w.show();
*/
    QLineSeries* series = new QLineSeries();
    QLineSeries* series1 = new QLineSeries();
    for(double i = 0.0;i < 10;i += 0.1)
    {
        series->append(i,sin(i));
        series1->append(i,cos(i));
    }
    series->setName("sin(x)");
    series1->setName("cos(x)");

    QChart chart;
    chart.addSeries(series);
    chart.addSeries(series1);
    chart.createDefaultAxes();
    chart.legend()->setAlignment(Qt::AlignRight);

    chart.setTitle("Line Chart");
    chart.setTheme(QChart::ChartThemeBlueCerulean);
    QChartView view(&chart);
    view.setRenderHint(QPainter::Antialiasing);
    view.show();
    return a.exec();
}
