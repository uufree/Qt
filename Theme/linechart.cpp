#include "linechart.h"
#include<QtGlobal>
#include<QDebug>
#include<QGridLayout>
#include<QColor>

LineChart::LineChart(QWidget* widget):
    QWidget(widget),
    chart(new QChart),
    pressLine(new QLineSeries),
    waterLine(new QLineSeries),
    flowLine(new QLineSeries),
    axisX(new QValueAxis),
    axisY(new QValueAxis)
{
    pressLine->setName("压力");
    waterLine->setName("水位");
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
    axisY->setLabelFormat("%.2f");
    axisY->setGridLineVisible(true);
    axisY->setTickCount(6);
    axisY->setMinorTickCount(1);

    chart->setAxisX(axisX,pressLine);
    chart->setAxisX(axisX,waterLine);
    chart->setAxisX(axisX,flowLine);
    chart->setAxisY(axisY,pressLine);
    chart->setAxisY(axisY,waterLine);
    chart->setAxisY(axisY,flowLine);

    waterLineInChart = flowLineInChart = pressLineInChart = true;

    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setTitle("折线图");
    chart->setTheme(QChart::ChartThemeBlueIcy);
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
        if(color == "White")
            pen.setColor(Qt::white);
        else if(color == "Black")
            pen.setColor(Qt::black);
        else if(color == "Cyan")
            pen.setColor(Qt::cyan);
        else if(color == "DarkCyan")
            pen.setColor(Qt::darkCyan);
        else if(color == "Red")
            pen.setColor(Qt::red);
        else if(color == "DarkRed")
            pen.setColor(Qt::darkRed);
        else if(color == "Magenta")
            pen.setColor(Qt::magenta);
        else if(color == "DarkMagenta")
            pen.setColor(Qt::darkMagenta);
        else if(color == "Green")
            pen.setColor(Qt::green);
        else if(color == "DarkGreen")
            pen.setColor(Qt::darkGreen);
        else if(color == "Yellow")
            pen.setColor(Qt::yellow);
        else if(color == "DarkYellow")
            pen.setColor(Qt::darkYellow);
        else if(color == "Blue")
            pen.setColor(Qt::blue);
        else if(color == "DarkBlue")
            pen.setColor(Qt::darkBlue);
        else if(color == "Gray")
            pen.setColor(Qt::gray);
        else if(color == "DarkGray")
            pen.setColor(Qt::darkGray);
        else if(color == "LightGray")
            pen.setColor(Qt::lightGray);

        if(style == "SolidLine")
            pen.setStyle(Qt::SolidLine);
        else if(style == "DashLine")
            pen.setStyle(Qt::DashLine);
        else if(style == "DotLine")
            pen.setStyle(Qt::DotLine);
        else if(style == "DashDotLine")
            pen.setStyle(Qt::DashDotLine);
        else if(style == "DashDotDotLine")
            pen.setStyle(Qt::DashDotDotLine);

        lineList[i]->setPen(pen);
    }

    double timeMin = settingData.timeMin;
    double timeMax = settingData.timeMax;
    double valueMin = settingData.valueMin;
    double valueMax = settingData.valueMax;

    axisX->setRange(timeMin,timeMax);
    axisX->setLabelFormat("%u");
    axisX->setGridLineVisible(true);
    axisX->setTickCount(11);
    axisX->setMinorTickCount(1);

    axisY->setRange(valueMin,valueMax);
    axisY->setLabelFormat("%f");
    axisY->setGridLineVisible(true);
    axisY->setTickCount(6);
    axisY->setMinorTickCount(1);
}

void LineChart::startPressLine()
{
    if(!pressLineInChart)
    {
        pressLine->setName("压力");
        chart->addSeries(pressLine);
        chart->setAxisX(axisX,pressLine);
        chart->setAxisY(axisY,pressLine);
        chart->update();
        pressLineInChart = true;
    }
}

void LineChart::startFlowLine()
{
    if(!flowLineInChart)
    {
        flowLine->setName("流量");
        chart->addSeries(flowLine);
        chart->setAxisX(axisX,flowLine);
        chart->setAxisY(axisY,flowLine);
        chart->update();
        flowLineInChart = true;
    }
}

void LineChart::startWaterLine()
{
    if(!waterLineInChart)
    {
        flowLine->setName("水位");
        chart->addSeries(waterLine);
        chart->setAxisX(axisX,waterLine);
        chart->setAxisY(axisY,waterLine);
        chart->update();
        waterLineInChart = true;
    }
}

void LineChart::stopFlowLine()
{
    if(flowLineInChart)
    {
        chart->removeSeries(flowLine);
        chart->update();
        flowLineInChart = false;
    }
}

void LineChart::stopPressLine()
{
    if(pressLineInChart)
    {
        chart->removeSeries(pressLine);
        chart->update();
        pressLineInChart = false;
    }
}

void LineChart::stopWaterLine()
{
    if(waterLineInChart)
    {
        chart->removeSeries(waterLine);
        chart->update();
        waterLineInChart = false;
    }
}

void LineChart::startAll()
{
    startFlowLine();
    startPressLine();
    startWaterLine();
}

void LineChart::stopAll()
{
    stopFlowLine();
    stopPressLine();
    stopWaterLine();
}

void LineChart::updateFlowData(const QVector<double>& flowDataList)
{
    flowLine->clear();
    int flowSize = flowDataList.size();
    for(int i=0;i<flowSize;i++)
        flowLine->append(QPointF(100-i,flowDataList[flowSize - 1 - i]));
    chart->update();
}

void LineChart::updateWaterData(const QVector<double> &waterDataList)
{
    waterLine->clear();
    int waterSize = waterDataList.size();
    for(int i=0;i<waterSize;i++)
        waterLine->append(QPointF(100-i,waterDataList[waterSize - 1 - i]));
    chart->update();
}

void LineChart::updatePressData(const QVector<double> &pressDataList)
{
    pressLine->clear();
    int pressSize = pressDataList.size();
    for(int i=0;i<pressSize;i++)
        pressLine->append(QPointF(100-i,pressDataList[pressSize - 1 - i]));
    chart->update();
}

void LineChart::resizeView(int x,int y)
{
    view->resize(x,y);
}
