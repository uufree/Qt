#include "mainwindow.h"
#include<QApplication>
#include"circledata.h"
#include<QtCharts/QChart>
#include<QtCharts/QLineSeries>
#include<QtCharts/QChartView>

#include"linechart.h"

using namespace QtCharts;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w;
    w.display();
    w.show();

    return a.exec();
}
