#include "linechart.h"
#include<QtGlobal>
#include<QDebug>
#include<QGridLayout>

LineChart::LineChart(QWidget* widget):
    QWidget(widget),
    chart(new QChart),
    pressLine(new QLineSeries),
    waterLine(new QLineSeries),
    flowLine(new QLineSeries),
    axisX(new QValueAxis),
    axisY(new QValueAxis),
    timer(new QTimer)
{
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(updateLineChart()));

    pressLine->setName("压力");
    waterLine->setName("液位");
    flowLine->setName("流量");

    chart->addSeries(pressLine);
    chart->addSeries(waterLine);
    chart->addSeries(flowLine);

    axisX->setRange(0,100);
    axisX->setLabelFormat("%u");
    axisX->setGridLineVisible(true);
    axisX->setTickCount(11);
    axisX->setMinorTickCount(1);

    axisY->setRange(0,100);
    axisY->setLabelFormat("%u");
    axisY->setGridLineVisible(true);
    axisY->setTickCount(11);
    axisY->setMinorTickCount(1);

    chart->setAxisX(axisX,pressLine);
    chart->setAxisX(axisX,waterLine);
    chart->setAxisX(axisX,flowLine);
    chart->setAxisY(axisY,waterLine);
    chart->setAxisY(axisY,flowLine);
    chart->setAxisY(axisY,pressLine);

    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setTitle("折线图");
    chart->setTheme(QChart::ChartThemeBlueCerulean);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    view = new QChartView(chart,this);
    view->setRenderHint(QPainter::Antialiasing);//抗锯齿

    QPalette palette;
    palette.setColor(QPalette::Window,Qt::red);
    setPalette(palette);
}

void LineChart::updateLineChart()
{
    if(pressDataList.size() == 100)
        pressDataList.pop_front();
    pressDataList.append(qrand() % 100);

    if(flowDataList.size() == 100)
        flowDataList.pop_front();
    flowDataList.append(qrand() % 100);

    if(waterDataList.size() == 100)
        waterDataList.pop_front();
    waterDataList.append(qrand() % 100);

    pressLine->clear();
    flowLine->clear();
    waterLine->clear();

    int pressSize = pressDataList.size();
    int flowSize = flowDataList.size();
    int waterSize = waterDataList.size();

    if(pressSize == flowSize  && flowSize == waterSize)
    {
        for(int i=0;i<pressSize;i++)
        {
            pressLine->append(QPointF(100-i,pressDataList[pressSize - 1 - i]));
            waterLine->append(QPointF(100-i,waterDataList[pressSize - 1 - i]));
            flowLine->append(QPointF(100-i,flowDataList[pressSize - 1 - i]));
        }
    }
    else
    {
        for(int i=0;i<pressSize;i++)
            pressLine->append(QPointF(100-i,pressDataList[pressSize - 1 - i]));
        for(int i=0;i<waterSize;i++)
            waterLine->append(QPointF(100-i,waterDataList[waterSize - 1 - i]));
        for(int i=0;i<flowSize;i++)
            flowLine->append(QPointF(100-i,flowDataList[flowSize - 1 - i]));
    }

    chart->update();
    qDebug() << "emmmm";
}

void LineChart::start()
{
    timer->start(300);
    view->setAutoFillBackground(true);
    view->show();
}

