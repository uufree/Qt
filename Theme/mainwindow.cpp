#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<functional>
#include<QFile>
#include<QString>
#include<QTextStream>
#include<QTime>
#include<QDate>

extern struct SettingData settingData;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer(new QTimer(this)),
    time(new QTimer(this)),
    com(new Communication)
{
    ui->setupUi(this);

    QFile qss(":/qss/uuchen.qss");
    if(!qss.open(QIODevice::ReadOnly))
        qDebug() << "qss: open file error!";
    QTextStream in(&qss);
    styleSheet = in.readAll();
    this->setStyleSheet(styleSheet);

    settingDialog = new SettingDialog(this);
    settingDialog->setWindowTitle("设置");
    settingDialog->setStyleSheet(styleSheet);

    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(clickStartButton()));
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(clickSaveButton()));
    connect(ui->settingButton,SIGNAL(clicked()),this,SLOT(clickSettingButton()));
    connect(ui->switchButton,SIGNAL(clicked()),this,SLOT(clickSwitchButton()));
    connect(timer,SIGNAL(timeout()),this,SLOT(handleLineChartSize()));

    timer->start(1);

    ui->waterCheck->setChecked(true);
    ui->pressCheck->setChecked(true);
    ui->flow1Check->setChecked(true);
    ui->flow2Check->setChecked(true);
    connect(ui->waterCheck,SIGNAL(stateChanged(int)),this,SLOT(handleWaterLine(int)));
    connect(ui->pressCheck,SIGNAL(stateChanged(int)),this,SLOT(handlePressLine(int)));
    connect(ui->flow1Check,SIGNAL(stateChanged(int)),this,SLOT(handleFlow1Line(int)));
    connect(ui->flow2Check,SIGNAL(stateChanged(int)),this,SLOT(handleFlow2Line(int)));

    ui->circleData->setWaterRange(0,120);
    ui->circleData->setFlow1Range(0,120);
    ui->circleData->setFlow2Range(0,120);
    ui->circleData->setPressRange(0,120);

    ui->circleData->setWaterCallBack(std::bind(&MainWindow::waterCallBack,this));
    ui->circleData->setPressCallBack(std::bind(&MainWindow::pressCallBack,this));
    ui->circleData->setFlow1CallBack(std::bind(&MainWindow::flow1CallBack,this));
    ui->circleData->setFlow2CallBack(std::bind(&MainWindow::flow2CallBack,this));

    ui->currentTestPoint->setText("");
    ui->currentCollection->setText("");
    ui->currentNote->setText("");
    ui->currentProject->setText("");
    ui->currentUnit->setText("");
    ui->currentCollection->setReadOnly(true);
    ui->currentProject->setReadOnly(true);
    ui->currentTestPoint->setReadOnly(true);
    ui->currentUnit->setReadOnly(true);

    connect(ui->currentNote,SIGNAL(textChanged()),this,SLOT(handleCurrentNote()));

    waterNote = "我是水位";
    flow1Note = "我是流量1";
    flow2Note = "我是流量2";
    pressNote = "我是压力";

    connect(time,SIGNAL(timeout()),this,SLOT(updateTime()));
    time->start(1000);
    updateInformMessage("准备启动");

    settingDialog->setHandleSettingCallback(std::bind(&MainWindow::handleSetting,this,std::placeholders::_1));

    com->setWaterCallBack(std::bind(&MainWindow::comWaterCallBack,this,std::placeholders::_1));
    com->setPressCallBack(std::bind(&MainWindow::comPressCallBack,this,std::placeholders::_1));
    com->setFlow1CallBack(std::bind(&MainWindow::comFlow1CallBack,this,std::placeholders::_1));
    com->setFlow2CallBack(std::bind(&MainWindow::comFlow2CallBack,this,std::placeholders::_1));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//切换下一组数据，暂时不写
void MainWindow::clickSwitchButton()
{
    updateInformMessage("切换下一组测点");
}

//保存一组数据
void MainWindow::clickSaveButton()
{
    updateInformMessage("保存数据");
}

//弹出SettingDialog对话框
void MainWindow::clickSettingButton()
{
    settingDialog->show();
    settingDialog->setModal(true);
    updateInformMessage("进入设置界面");
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
        com->openSerialPort(settingData.serialPort);
        com->openTcpSocket();
        start();
        updateInformMessage("开始监测数据");
    }
    else
    {//停止
        ui->startButton->setText("开始");
        ui->saveButton->setText("历史数据");
        ui->saveButton->setEnabled(true);
        ui->switchButton->setEnabled(false);
        ui->settingButton->setEnabled(true);
        com->closeSerialPort();
        com->closeTcpSocket();
        stop();
        com->updateSerialPortInfo();
        const QVector<QString>& serialPortNameList = com->getSerialPortNameList();
        settingDialog->updateSerialPortInfo(serialPortNameList);
        updateInformMessage("运行停止");
    }
}

void MainWindow::handleFlow1Line(int type)
{
    if(type && ui->startButton->text() == "停止")
        ui->lineChart->startFlow1Line();
    else
        ui->lineChart->stopFlow1Line();
}

void MainWindow::handleFlow2Line(int type)
{
    if(type && ui->startButton->text() == "停止")
        ui->lineChart->startFlow2Line();
    else
        ui->lineChart->stopFlow2Line();
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

void MainWindow::handleLineChartSize()
{
    ui->lineChart->resizeView(ui->circleData->width(),ui->circleData->height());
    if(ui->lineChart->size() == ui->circleData->size())
        timer->stop();
    disconnect(timer,SIGNAL(timeout()),this,SLOT(handleLineChartSize()));
}

void MainWindow::handleCurrentNote()
{
    if(ui->currentTestPoint->text() == "流量1")
        flow1Note = ui->currentNote->toPlainText();
    else if(ui->currentTestPoint->text() == "压力")
        pressNote = ui->currentNote->toPlainText();
    else if(ui->currentTestPoint->text() == "水位")
        waterNote = ui->currentNote->toPlainText();
    else if(ui->currentTestPoint->text() == "流量2")
        flow2Note = ui->currentNote->toPlainText();
    else
    {};
}

void MainWindow::updateTime()
{
    QString time = QTime::currentTime().toString();
    int year,mouth,day;
    QDate::currentDate().getDate(&year,&mouth,&day);
    QString date = QString::number(year) + "年" + QString::number(mouth) + "月" + QString::number(day) + "日";
    ui->timeLabel->setText(date + "  " + time);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->lineChart->resizeView(ui->circleData->width(),ui->circleData->height());
    updateInformMessage("窗口大小改变");
}

void MainWindow::setting()
{
    ui->lineChart->setting(settingData);
}

void MainWindow::start()
{
    if(ui->waterCheck->isChecked())
        ui->lineChart->startWaterLine();
    if(ui->pressCheck->isChecked())
        ui->lineChart->startPressLine();
    if(ui->flow1Check->isChecked())
        ui->lineChart->startFlow1Line();
    if(ui->flow2Check->isChecked())
        ui->lineChart->startFlow2Line();

/*
    connect(timer,SIGNAL(timeout()),this,SLOT(testMakeData()));
    timer->start(300);
*/

    connect(timer,SIGNAL(timeout()),com,SLOT(sendMessage()));
    timer->start(1000);

    ui->currentTestPoint->setText("流量1");
    ui->currentCollection->setText("");
    ui->currentNote->setText(flow1Note);
    ui->currentProject->setText("");
    ui->currentUnit->setText("");
}

void MainWindow::stop()
{
    ui->lineChart->stopAll();
    timer->stop();
    ui->circleData->setWaterValue(0);
    ui->circleData->setFlow1Value(0);
    ui->circleData->setFlow2Value(0);
    ui->circleData->setPressValue(0);

    ui->currentTestPoint->setText("");
    ui->currentCollection->setText("");
    ui->currentNote->setText("");
    ui->currentProject->setText("");
    ui->currentUnit->setText("");
}

//事件处理+回调果然无敌，跨组件的处理机制啊，比单纯的信号与槽强多了
void MainWindow::waterCallBack()
{
    ui->currentTestPoint->setText("水位");
    ui->currentNote->setText(waterNote);
    ui->currentUnit->setText("m");
    updateInformMessage("监测水位信息");
}

void MainWindow::flow1CallBack()
{
    ui->currentTestPoint->setText("流量1");
    ui->currentNote->setText(flow1Note);
    ui->currentUnit->setText("m³/s");
    updateInformMessage("监测流量信息");
}

void MainWindow::flow2CallBack()
{
    ui->currentTestPoint->setText("流量2");
    ui->currentNote->setText(flow2Note);
    ui->currentUnit->setText("m³/s");
    updateInformMessage("监测流量1信息");
}

void MainWindow::pressCallBack()
{
    ui->currentTestPoint->setText("压力");
    ui->currentNote->setText(pressNote);
    ui->currentUnit->setText("KPa");
    updateInformMessage("监测压力信息");
}

void MainWindow::updateCurrentMessage()
{
    if(ui->currentTestPoint->text() == "压力")
    {
        ui->currentCollection->setText(QString::number(pressCollection,10,2));
        ui->currentProject->setText(QString::number(pressProject,10,2));
        ui->currentUnit->setText("KPa");
    }
    else if(ui->currentTestPoint->text() == "流量1")
    {
        ui->currentCollection->setText(QString::number(flow1Collection,10,2));
        ui->currentProject->setText(QString::number(flow1Project,10,2));
        ui->currentUnit->setText("m³/s");
    }
    else if(ui->currentTestPoint->text() == "水位")
    {
        ui->currentCollection->setText(QString::number(waterCollection,10,2));
        ui->currentProject->setText(QString::number(waterProject,10,2));
        ui->currentUnit->setText("m");
    }
    else
    {
        ui->currentCollection->setText(QString::number(flow2Collection,10,2));
        ui->currentProject->setText(QString::number(flow2Project,10,2));
        ui->currentUnit->setText("m³/s");
    }
}

void MainWindow::updateInformMessage(const QString& str)
{
    ui->thingLabel->setText(str);
}

void MainWindow::handleSetting(const struct SettingData &data)
{
    ui->lineChart->setting(data);
    axisXStart = (int)data.timeMax;
}

void MainWindow::comWaterCallBack(short water)
{
    if(waterDataList.size() < axisXStart)
        waterDataList.append(water);
    else
    {
        waterDataList.pop_front();
        waterDataList.append(water);
    }
    waterCollection = water;
    waterProject = waterCollection;

    ui->lineChart->updateWaterData(waterDataList);
    ui->circleData->setWaterValue(waterCollection);

    updateCurrentMessage();
    updateInformMessage("目前工作测点数量：4个");
}

void MainWindow::comPressCallBack(short press)
{
    if(pressDataList.size() < axisXStart)
        pressDataList.append(press);
    else
    {
        pressDataList.pop_front();
        pressDataList.append(press);
    }
    pressCollection = press;
    pressProject = pressCollection;

    ui->lineChart->updatePressData(pressDataList);
    ui->circleData->setPressValue(pressCollection);

    updateCurrentMessage();
    updateInformMessage("目前工作测点数量：4个");
}

void MainWindow::comFlow1CallBack(float flow1)
{
    if(flow1DataList.size() < axisXStart)
        flow1DataList.append(flow1);
    else
    {
        flow1DataList.pop_front();
        flow1DataList.append(flow1);
    }
    flow1Collection = flow1;
    flow1Project = flow1Collection;

    ui->lineChart->updateFlow1Data(flow1DataList);
    ui->circleData->setFlow1Value(flow1Collection);

    updateCurrentMessage();
    updateInformMessage("目前工作测点数量：4个");
}

void MainWindow::comFlow2CallBack(float flow2)
{
    if(flow2DataList.size() < axisXStart)
        flow2DataList.append(flow2);
    else
    {
        flow2DataList.pop_front();
        flow2DataList.append(flow2);
    }
    flow2Collection = flow2;
    flow2Project = flow2Collection;

    ui->lineChart->updateFlow2Data(flow2DataList);
    ui->circleData->setFlow2Value(flow2Project);

    updateCurrentMessage();
    updateInformMessage("目前工作测点数量：4个");
}

void MainWindow::testMakeData()
{
    double ran1 = qrand() % 100;
    double ran2  =qrand() % 100;
    double ran3 = qrand() % 100;
    double ran4 = qrand() % 100;

    if(pressDataList.size() < axisXStart)
        pressDataList.append(ran1);
    else
    {
        pressDataList.pop_front();
        pressDataList.append(ran1);
    }
    pressCollection = ran1;
    pressProject = pressCollection;

    if(waterDataList.size() < axisXStart)
        waterDataList.append(ran2);
    else
    {
        waterDataList.pop_front();
        waterDataList.append(ran2);
    }
    waterCollection = ran2;
    waterProject = waterCollection;

    if(flow1DataList.size() < axisXStart)
        flow1DataList.append(ran3);
    else
    {
        flow1DataList.pop_front();
        flow1DataList.append(ran3);
    }
    flow1Collection = ran3;
    flow1Project = flow1Collection;

    if(flow2DataList.size() < axisXStart)
        flow2DataList.append(ran4);
    else
    {
        flow2DataList.pop_front();
        flow2DataList.append(ran4);
    }
    flow2Collection = ran4;
    flow2Project = flow2Collection;

    ui->lineChart->updateFlow1Data(flow1DataList);
    ui->lineChart->updateFlow2Data(flow2DataList);
    ui->lineChart->updatePressData(pressDataList);
    ui->lineChart->updateWaterData(waterDataList);

    ui->circleData->setPressValue(pressCollection);
    ui->circleData->setWaterValue(waterCollection);
    ui->circleData->setFlow1Value(flow1Collection);
    ui->circleData->setFlow2Value(flow2Collection);

    updateCurrentMessage();
    updateInformMessage("目前工作测点数量：4个");
}

