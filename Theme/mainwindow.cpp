#include "mainwindow.h"
#include "ui_mainwindow.h"

extern struct SettingData settingData;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer(new QTimer)
{
    ui->setupUi(this);

    settingDialog = new SettingDialog(this);

    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(clickStartButton()));
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(clickSaveButton()));
    connect(ui->settingButton,SIGNAL(clicked()),this,SLOT(clickSettingButton()));
    connect(ui->switchButton,SIGNAL(clicked()),this,SLOT(clickSwitchButton()));
    connect(timer,SIGNAL(timeout()),this,SLOT(handleLineChartSize()));

    timer->start(1);

    ui->waterCheck->setChecked(true);
    ui->pressCheck->setChecked(true);
    ui->flowCheck->setChecked(true);
    connect(ui->waterCheck,SIGNAL(stateChanged(int)),this,SLOT(handleWaterLine(int)));
    connect(ui->pressCheck,SIGNAL(stateChanged(int)),this,SLOT(handlePressLine(int)));
    connect(ui->flowCheck,SIGNAL(stateChanged(int)),this,SLOT(handleFlowLine(int)));

    ui->circleData->setWaterRange(0,120);
    ui->circleData->setFlowRange(0,120);
    ui->circleData->setPressRange(0,120);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->lineChart->resizeView(ui->circleData->width(),ui->circleData->height());
}

void MainWindow::setting()
{
    ui->lineChart->setting(settingData);
}

//切换下一组数据，暂时不写
void MainWindow::clickSwitchButton()
{
}

//保存一组数据
void MainWindow::clickSaveButton()
{
}

//弹出SettingDialog对话框
void MainWindow::clickSettingButton()
{
    settingDialog->show();
}

//开始启动
void MainWindow::clickStartButton()
{
    if(ui->startButton->text() == "开始")
    {//启动
        ui->startButton->setText("停止");
        ui->saveButton->setText("保存数据");
        if(settingData.acquireStyle == "手动")
            ui->saveButton->setEnabled(true);
        else
        {
            ui->saveButton->setEnabled(false);
            ui->saveButton->setText(settingData.acquireStyle + "/次");
        }
        ui->switchButton->setEnabled(true);
        ui->settingButton->setEnabled(false);

        start();
    }
    else
    {//停止
        ui->startButton->setText("开始");
        ui->saveButton->setText("历史数据");
        ui->saveButton->setEnabled(true);
        ui->switchButton->setEnabled(false);
        ui->settingButton->setEnabled(true);

        stop();
    }
}

void MainWindow::start()
{
    if(ui->waterCheck->isChecked())
        ui->lineChart->startWaterLine();
    if(ui->pressCheck->isChecked())
        ui->lineChart->startPressLine();
    if(ui->flowCheck->isChecked())
        ui->lineChart->startFlowLine();

    connect(timer,SIGNAL(timeout()),this,SLOT(testMakeData()));
    timer->start(300);
}

void MainWindow::stop()
{
    ui->lineChart->stopAll();
    timer->stop();
    ui->circleData->setWaterValue(0);
    ui->circleData->setFlowValue(0);
    ui->circleData->setPressValue(0);
}

void MainWindow::handleLineChartSize()
{
    ui->lineChart->resizeView(ui->circleData->width(),ui->circleData->height());
    if(ui->lineChart->size() == ui->circleData->size())
        timer->stop();
    disconnect(timer,SIGNAL(timeout()),this,SLOT(handleLineChartSize()));
}

void MainWindow::handleFlowLine(int type)
{
    if(type && ui->startButton->text() == "停止")
        ui->lineChart->startFlowLine();
    else
        ui->lineChart->stopFlowLine();
}

void MainWindow::handleWaterLine(int type)
{
    if(type && ui->startButton->text() == "停止")
        ui->lineChart->startWaterLine();
    else
        ui->lineChart->stopWaterLine();
}

void MainWindow::handlePressLine(int type)
{
    if(type && ui->startButton->text() == "停止")
        ui->lineChart->startPressLine();
    else
        ui->lineChart->stopPressLine();
}

void MainWindow::testMakeData()
{
    double ran1 = qrand() % 100;
    double ran2  =qrand() % 100;
    double ran3 = qrand() % 100;

    if(pressDataList.size() < 100)
        pressDataList.append(ran1);
    else
    {
        pressDataList.pop_front();
        pressDataList.append(ran1);
    }

    if(waterDataList.size() < 100)
        waterDataList.append(ran2);
    else
    {
        waterDataList.pop_front();
        waterDataList.append(ran2);
    }

    if(flowDataList.size() < 100)
        flowDataList.append(ran3);
    else
    {
        flowDataList.pop_front();
        flowDataList.append(ran3);
    }

    ui->lineChart->updateFlowData(flowDataList);
    ui->lineChart->updatePressData(pressDataList);
    ui->lineChart->updateWaterData(waterDataList);
    ui->circleData->setPressValue(ran1);
    ui->circleData->setWaterValue(ran2);
    ui->circleData->setFlowValue(ran3);
}
