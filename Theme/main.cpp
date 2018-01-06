#include "mainwindow.h"
#include<QApplication>
#include"circledata.h"
#include<QtCharts/QChart>
#include<QtCharts/QLineSeries>
#include<QtCharts/QChartView>

#include"linechart.h"
#include"settingdialog.h"

using namespace QtCharts;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
