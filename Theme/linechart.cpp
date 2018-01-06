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

    view->setAutoFillBackground(true);
    view->show();
}

void LineChart::setting(const SettingData &settingData)
{
    QString lineColorList[3] = {settingData.waterColor,settingData.flowColor,settingData.pressColor};
    QString lineStyleList[3] = {settingData.waterLineStyle,settingData.flowLineStyle,settingData.pressLineStyle};
    QVector<QLineSeries*> lineList = {waterLine,flowLine,pressLine};

    for(int i=0;i<3;i++)
    {
        QString color = lineColorList[i];
        QString style = lineStyleList[i];
        QPen pen;
        switch(color)
        {
            case "White":
                pen.setColor(Qt::white);
            case "Black":
                pen.setColor(Qt::black);
            case "Cyan":
                pen.setColor(Qt::cyan);
            case "DarkCyan":
                pen.setColor(Qt::darkCyan);
            case "Red":
                pen.setColor(Qt::red);
            case "DarkRed":
                pen.setColor(Qt::darkRed);
            case "Magenta":
                pen.setColor(Qt::magenta);
            case "DarkMagenta":
                pen.setColor(Qt::darkMagenta);
            case "Green":
                pen.setColor(Qt::green);
            case "DarkGreen":
                pen.setColor(Qt::darkGreen);
            case "Yellow":
                pen.setColor(Qt::yellow);
            case "DarkYellow":
                pen.setColor(Qt::darkYellow);
            case "Blue":
                pen.setColor(Qt::blue);
            case "DarkBlue":
                pen.setColor(Qt::darkBlue);
            case "Gray":
                pen.setColor(Qt::gray);
            case "DarkGray":
                pen.setColor(Qt::darkGray);
            case "LightGray":
                pen.setColor(Qt::lightGray);
        }

        switch(style)
        {
            case "SolidLine":
                pen.setStyle(Qt::SolidLine);
            case "DashLine":
                pen.setStyle(Qt::DashLine);
            case "DotLine":
                pen.setStyle(Qt::DotLine);
            case "DashDotLine":
                pen.setStyle(Qt::DashDotLine);
            case "DashDotDotLine":
                pen.setStyle(Qt::DashDotDotLine);
        }

        lineList[i]->setPen(pen);
    }
}

void LineChart::startPressLine()
{}

void LineChart::startFlowLine()
{}

void LineChart::startWaterLine()
{}

void LineChart::stopFlowLine()
{}

void LineChart::stopPressLine()
{}

void LineChart::stopWaterLine()
{}

void LineChart::startAll()
{}

void LineChart::stopAll()
{}

void LineChart::clearAll()
{}

void LineChart::updateFlowData(QVector<double> &flowDataList)
{}

void LineChart::updateWaterData(const QVector<double> &waterDataList)
{}

void LineChart::updatePressData(const QVector<double> &pressDataList)
{}

void LineChart::resizeView(int x,int y)
{
    view->resize(x,y);
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
}


