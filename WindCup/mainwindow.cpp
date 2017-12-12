#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QLineEdit>
#include<QPushButton>
#include<QTableWidget>
#include<QComboBox>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentCups(9),
    currentSerialPort(new QSerialPort),
    serialTimer(new QTimer),
    timeTimer(new QTimer),
    dateTime(new QTime)
{
    ui->setupUi(this);

    char ch = 0xe0;
    for(int i=0;i<32;++i)
    {
        addrList.append(ch);
        ++ch;
    }
    serialPortList = {"com1","com2","com3","com4","com5","com6","com7","com8","com9","com10","com11","com12","com13","com14","com15"};

    initAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startClicked()
{
    if(ui->startBtton->text() == tr("开始"))
    {
        clearAll();//清理掉已有的信息
        collectSettingMessage();//收集设置区的信息
        start();//根据设置区的信息建立串口，启动定时器
        ui->startBtton->setText(tr("停止"));
        ui->flushButton->setEnabled(false);
        ui->saveDataButton->setEnabled(false);
    }
    else
    {
        serialTimer->stop();
        ui->startBtton->setText(tr("开始"));
        ui->flushButton->setEnabled(true);
        ui->saveDataButton->setEnabled(true);
    }
}

void MainWindow::flushClicked()
{
    clearAll();//清理数据区的所有信息
}

void MainWindow::exportDataClicked()//保存数据信息
{

}

void MainWindow::handleTimeout()
{
    QByteArray byte8;
    for(int i=0;i<currentCups;i++)
    {
        currentSerialPort->write(&addrList[i],1);
        byte8 = currentSerialPort->readAll();
        //这块没有计算，只显示
        cupList[i]->setText(QString::number(byte8.toInt(),16).toUpper());
    }
}

void MainWindow::updateTime()
{
    dateTimeStr = dateTime->currentTime().toString();
    ui->currentTime->setText(dateTimeStr);
}

void MainWindow::cupButtonClicked0()
{
    ui->currentCup->setText(QString::number(0));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[0]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[0]));
    ui->currentSpeed->setText(QString::number(currentSpeed[0]));
    ui->currentVolume->setText(QString::number(currentVolume[0]));
}
void MainWindow::cupButtonClicked1()
{
    ui->currentCup->setText(QString::number(1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[1]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[1]));
    ui->currentSpeed->setText(QString::number(currentSpeed[1]));
    ui->currentVolume->setText(QString::number(currentVolume[1]));
}
void MainWindow::cupButtonClicked2()
{
    ui->currentCup->setText(QString::number(2));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[2]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[2]));
    ui->currentSpeed->setText(QString::number(currentSpeed[2]));
    ui->currentVolume->setText(QString::number(currentVolume[2]));
}
void MainWindow::cupButtonClicked3()
{
    ui->currentCup->setText(QString::number(3));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[3]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[3]));
    ui->currentSpeed->setText(QString::number(currentSpeed[3]));
    ui->currentVolume->setText(QString::number(currentVolume[3]));
}
void MainWindow::cupButtonClicked4()
{
    ui->currentCup->setText(QString::number(4));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[4]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[4]));
    ui->currentSpeed->setText(QString::number(currentSpeed[4]));
    ui->currentVolume->setText(QString::number(currentVolume[4]));
}
void MainWindow::cupButtonClicked5()
{
    ui->currentCup->setText(QString::number(5));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[5]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[5]));
    ui->currentSpeed->setText(QString::number(currentSpeed[5]));
    ui->currentVolume->setText(QString::number(currentVolume[5]));
}
void MainWindow::cupButtonClicked6()
{
    ui->currentCup->setText(QString::number(6));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[6]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[6]));
    ui->currentSpeed->setText(QString::number(currentSpeed[6]));
    ui->currentVolume->setText(QString::number(currentVolume[6]));
}
void MainWindow::cupButtonClicked7()
{
    ui->currentCup->setText(QString::number(7));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[7]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[7]));
    ui->currentSpeed->setText(QString::number(currentSpeed[7]));
    ui->currentVolume->setText(QString::number(currentVolume[7]));
}

void MainWindow::cupButtonClicked8()
{
    ui->currentCup->setText(QString::number(8));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[8]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[8]));
    ui->currentSpeed->setText(QString::number(currentSpeed[8]));
    ui->currentVolume->setText(QString::number(currentVolume[8]));
}
void MainWindow::cupButtonClicked9()
{
    ui->currentCup->setText(QString::number(9));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[9]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[9]));
    ui->currentSpeed->setText(QString::number(currentSpeed[9]));
    ui->currentVolume->setText(QString::number(currentVolume[9]));
}
void MainWindow::cupButtonClicked10()
{
    ui->currentCup->setText(QString::number(10));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[10]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[10]));
    ui->currentSpeed->setText(QString::number(currentSpeed[10]));
    ui->currentVolume->setText(QString::number(currentVolume[10]));
}
void MainWindow::cupButtonClicked11()
{
    ui->currentCup->setText(QString::number(11));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[11]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[11]));
    ui->currentSpeed->setText(QString::number(currentSpeed[11]));
    ui->currentVolume->setText(QString::number(currentVolume[11]));
}

void MainWindow::cupButtonClicked12()
{
    ui->currentCup->setText(QString::number(12));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[12]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[12]));
    ui->currentSpeed->setText(QString::number(currentSpeed[12]));
    ui->currentVolume->setText(QString::number(currentVolume[12]));
}
void MainWindow::cupButtonClicked13()
{
    ui->currentCup->setText(QString::number(13));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[13]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[13]));
    ui->currentSpeed->setText(QString::number(currentSpeed[13]));
    ui->currentVolume->setText(QString::number(currentVolume[13]));
}
void MainWindow::cupButtonClicked14()
{
    ui->currentCup->setText(QString::number(14));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[14]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[14]));
    ui->currentSpeed->setText(QString::number(currentSpeed[14]));
    ui->currentVolume->setText(QString::number(currentVolume[14]));
}
void MainWindow::cupButtonClicked15()
{
    ui->currentCup->setText(QString::number(15));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[15]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[15]));
    ui->currentSpeed->setText(QString::number(currentSpeed[15]));
    ui->currentVolume->setText(QString::number(currentVolume[15]));
}

void MainWindow::cupButtonClicked16()
{
    ui->currentCup->setText(QString::number(16));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[16]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[16]));
    ui->currentSpeed->setText(QString::number(currentSpeed[16]));
    ui->currentVolume->setText(QString::number(currentVolume[16]));
}
void MainWindow::cupButtonClicked17()
{
    ui->currentCup->setText(QString::number(17));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[17]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[17]));
    ui->currentSpeed->setText(QString::number(currentSpeed[17]));
    ui->currentVolume->setText(QString::number(currentVolume[17]));
}
void MainWindow::cupButtonClicked18()
{
    ui->currentCup->setText(QString::number(18));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[18]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[18]));
    ui->currentSpeed->setText(QString::number(currentSpeed[18]));
    ui->currentVolume->setText(QString::number(currentVolume[18]));
}
void MainWindow::cupButtonClicked19()
{
    ui->currentCup->setText(QString::number(19));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[19]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[19]));
    ui->currentSpeed->setText(QString::number(currentSpeed[19]));
    ui->currentVolume->setText(QString::number(currentVolume[19]));
}

void MainWindow::cupButtonClicked20()
{
    ui->currentCup->setText(QString::number(20));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[20]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[20]));
    ui->currentSpeed->setText(QString::number(currentSpeed[20]));
    ui->currentVolume->setText(QString::number(currentVolume[20]));
}
void MainWindow::cupButtonClicked21()
{
    ui->currentCup->setText(QString::number(21));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[21]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[21]));
    ui->currentSpeed->setText(QString::number(currentSpeed[21]));
    ui->currentVolume->setText(QString::number(currentVolume[21]));
}
void MainWindow::cupButtonClicked22()
{
    ui->currentCup->setText(QString::number(22));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[22]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[22]));
    ui->currentSpeed->setText(QString::number(currentSpeed[22]));
    ui->currentVolume->setText(QString::number(currentVolume[22]));
}
void MainWindow::cupButtonClicked23()
{
    ui->currentCup->setText(QString::number(23));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[23]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[23]));
    ui->currentSpeed->setText(QString::number(currentSpeed[23]));
    ui->currentVolume->setText(QString::number(currentVolume[23]));
}

void MainWindow::cupButtonClicked24()
{
    ui->currentCup->setText(QString::number(24));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[24]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[24]));
    ui->currentSpeed->setText(QString::number(currentSpeed[24]));
    ui->currentVolume->setText(QString::number(currentVolume[24]));
}
void MainWindow::cupButtonClicked25()
{
    ui->currentCup->setText(QString::number(25));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[25]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[25]));
    ui->currentSpeed->setText(QString::number(currentSpeed[25]));
    ui->currentVolume->setText(QString::number(currentVolume[25]));
}
void MainWindow::cupButtonClicked26()
{
    ui->currentCup->setText(QString::number(26));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[26]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[26]));
    ui->currentSpeed->setText(QString::number(currentSpeed[26]));
    ui->currentVolume->setText(QString::number(currentVolume[26]));
}
void MainWindow::cupButtonClicked27()
{
    ui->currentCup->setText(QString::number(27));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[27]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[27]));
    ui->currentSpeed->setText(QString::number(currentSpeed[27]));
    ui->currentVolume->setText(QString::number(currentVolume[27]));
}

void MainWindow::cupButtonClicked28()
{
    ui->currentCup->setText(QString::number(28));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[28]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[28]));
    ui->currentSpeed->setText(QString::number(currentSpeed[28]));
    ui->currentVolume->setText(QString::number(currentVolume[28]));
}
void MainWindow::cupButtonClicked29()
{
    ui->currentCup->setText(QString::number(29));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[29]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[29]));
    ui->currentSpeed->setText(QString::number(currentSpeed[29]));
    ui->currentVolume->setText(QString::number(currentVolume[29]));
}
void MainWindow::cupButtonClicked30()
{
    ui->currentCup->setText(QString::number(30));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[30]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[30]));
    ui->currentSpeed->setText(QString::number(currentSpeed[30]));
    ui->currentVolume->setText(QString::number(currentVolume[30]));
}
void MainWindow::cupButtonClicked31()
{
    ui->currentCup->setText(QString::number(31));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[31]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[31]));
    ui->currentSpeed->setText(QString::number(currentSpeed[31]));
    ui->currentVolume->setText(QString::number(currentVolume[31]));
}

void MainWindow::initSettingArea()
{
//init settingSerialPortBox
    for(int i=0;i<serialPortList.size();i++)
        ui->settingPort->addItem(serialPortList[i]);

    ui->settingPort->setCurrentIndex(0);
    settingData.portName = ui->settingPort->currentText();

//init settingSpeed
    ui->settingSpeed->setText("1");
    settingData.cupSpeed = "1";

//init baud
    ui->settingBaudBox->setCurrentText("9600");
    settingData.baud = "9600";

//init testArea
    ui->settingTestArea->setText("1");
    settingData.testArea = "1";

//init pollTime
    ui->settingPoll->setCurrentIndex(2);
    settingData.pollTime = ui->settingPoll->currentText();

//init cups
    ui->settingCups->setCurrentText("9");
    settingData.cupCount = "9";

    QObject::connect(ui->startBtton,SIGNAL(clicked()),this,SLOT(startClicked()));
    QObject::connect(ui->flushButton,SIGNAL(clicked()),this,SLOT(flushClicked()));
    QObject::connect(ui->saveDataButton,SIGNAL(clicked()),this,SLOT(exportDataClicked()));
}

//初始化左下的时间显示模块
//稍后处理计算能力之后加上其他的模块
void MainWindow::initCurrentDisplayArea()
{
    dateTimeStr = dateTime->currentTime().toString();
    ui->currentTime->setText(dateTimeStr);
    QObject::connect(timeTimer,SIGNAL(timeout()),this,SLOT(updateTime()));
    timeTimer->start(1000);
}

//初始化折线图信息
void MainWindow::initLineChart()
{

}

void MainWindow::initSpeed()
{
    QObject::connect(ui->E0,SIGNAL(clicked()),this,SLOT(cupButtonClicked0()));
    cupList.append(ui->E0);
    QObject::connect(ui->E1,SIGNAL(clicked()),this,SLOT(cupButtonClicked1()));
    cupList.append(ui->E1);
    QObject::connect(ui->E2,SIGNAL(clicked()),this,SLOT(cupButtonClicked2()));
    cupList.append(ui->E2);
    QObject::connect(ui->E3,SIGNAL(clicked()),this,SLOT(cupButtonClicked3()));
    cupList.append(ui->E3);
    QObject::connect(ui->E4,SIGNAL(clicked()),this,SLOT(cupButtonClicked4()));
    cupList.append(ui->E4);
    QObject::connect(ui->E5,SIGNAL(clicked()),this,SLOT(cupButtonClicked5()));
    cupList.append(ui->E5);
    QObject::connect(ui->E6,SIGNAL(clicked()),this,SLOT(cupButtonClicked6()));
    cupList.append(ui->E6);
    QObject::connect(ui->E7,SIGNAL(clicked()),this,SLOT(cupButtonClicked7()));
    cupList.append(ui->E7);
    QObject::connect(ui->E8,SIGNAL(clicked()),this,SLOT(cupButtonClicked8()));
    cupList.append(ui->E8);
    QObject::connect(ui->E9,SIGNAL(clicked()),this,SLOT(cupButtonClicked9()));
    cupList.append(ui->E9);
    QObject::connect(ui->EA,SIGNAL(clicked()),this,SLOT(cupButtonClicked10()));
    cupList.append(ui->EA);
    QObject::connect(ui->EB,SIGNAL(clicked()),this,SLOT(cupButtonClicked11()));
    cupList.append(ui->EB);
    QObject::connect(ui->EC,SIGNAL(clicked()),this,SLOT(cupButtonClicked12()));
    cupList.append(ui->EC);
    QObject::connect(ui->ED,SIGNAL(clicked()),this,SLOT(cupButtonClicked13()));
    cupList.append(ui->ED);
    QObject::connect(ui->EE,SIGNAL(clicked()),this,SLOT(cupButtonClicked14()));
    cupList.append(ui->EE);
    QObject::connect(ui->EF,SIGNAL(clicked()),this,SLOT(cupButtonClicked15()));
    cupList.append(ui->EF);
    QObject::connect(ui->F0,SIGNAL(clicked()),this,SLOT(cupButtonClicked16()));
    cupList.append(ui->F0);
    QObject::connect(ui->F1,SIGNAL(clicked()),this,SLOT(cupButtonClicked17()));
    cupList.append(ui->F1);
    QObject::connect(ui->F2,SIGNAL(clicked()),this,SLOT(cupButtonClicked18()));
    cupList.append(ui->F2);
    QObject::connect(ui->F3,SIGNAL(clicked()),this,SLOT(cupButtonClicked19()));
    cupList.append(ui->F3);
    QObject::connect(ui->F4,SIGNAL(clicked()),this,SLOT(cupButtonClicked20()));
    cupList.append(ui->F4);
    QObject::connect(ui->F5,SIGNAL(clicked()),this,SLOT(cupButtonClicked21()));
    cupList.append(ui->F5);
    QObject::connect(ui->F6,SIGNAL(clicked()),this,SLOT(cupButtonClicked22()));
    cupList.append(ui->F6);
    QObject::connect(ui->F7,SIGNAL(clicked()),this,SLOT(cupButtonClicked23()));
    cupList.append(ui->F7);
    QObject::connect(ui->F8,SIGNAL(clicked()),this,SLOT(cupButtonClicked24()));
    cupList.append(ui->F8);
    QObject::connect(ui->F9,SIGNAL(clicked()),this,SLOT(cupButtonClicked25()));
    cupList.append(ui->F9);
    QObject::connect(ui->FA,SIGNAL(clicked()),this,SLOT(cupButtonClicked26()));
    cupList.append(ui->FA);
    QObject::connect(ui->FB,SIGNAL(clicked()),this,SLOT(cupButtonClicked27()));
    cupList.append(ui->FB);
    QObject::connect(ui->FC,SIGNAL(clicked()),this,SLOT(cupButtonClicked28()));
    cupList.append(ui->FC);
    QObject::connect(ui->FD,SIGNAL(clicked()),this,SLOT(cupButtonClicked29()));
    cupList.append(ui->FD);
    QObject::connect(ui->FE,SIGNAL(clicked()),this,SLOT(cupButtonClicked30()));
    cupList.append(ui->FE);
    QObject::connect(ui->FF,SIGNAL(clicked()),this,SLOT(cupButtonClicked31()));
    cupList.append(ui->FF);

    QObject::connect(serialTimer,SIGNAL(timeout()),this,SLOT(handleTimeout()));
}

void MainWindow::initAll()
{
    initSettingArea();
    initCurrentDisplayArea();
    initLineChart();
    initSpeed();
}

void MainWindow::clearCurrentMessage()
{
    ui->currentCup->clear();
    ui->currentAverageSpeed->clear();
    ui->currentAverageVolume->clear();
    ui->currentSpeed->clear();
    ui->currentVolume->clear();
}

//清理折线图信息
void MainWindow::clearLineChart()
{

}

void MainWindow::clearSpeed()
{
    for(int i=0;i<currentCups;++i)
        cupList[i]->setText(cupList[i]->objectName());
}

void MainWindow::clearAll()
{
    clearCurrentMessage();
    clearLineChart();
    clearSpeed();
}

void MainWindow::collectSettingMessage()
{
    settingData.baud = ui->settingBaudBox->currentText();
    settingData.cupCount = ui->settingCups->currentText();
    settingData.cupSpeed = ui->settingSpeed->text();
    settingData.pollTime = ui->settingPoll->currentText();
    settingData.portName = ui->settingPort->currentText();
    settingData.testArea = ui->settingTestArea->text();
}

void MainWindow::start()
{
    currentCups = settingData.cupCount.toInt();
    for(int i=0;i<maxCups;++i)
    {
        if(i < currentCups)
            cupList[i]->setEnabled(true);
        else
            cupList[i]->setEnabled(false);
    }

    if(currentSerialPort != NULL)
        delete currentSerialPort;

    //这块没有按照设置的方式来设置端口信息
    currentSerialPort = new QSerialPort;
    currentSerialPort->setPortName(ui->settingPort->currentText());
    currentSerialPort->open(QIODevice::ReadWrite);
    currentSerialPort->setBaudRate(QSerialPort::Baud9600);
    currentSerialPort->setDataBits(QSerialPort::Data8);
    currentSerialPort->setParity(QSerialPort::NoParity);
    currentSerialPort->setStopBits(QSerialPort::OneStop);
    currentSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    serialTimer->start(settingData.pollTime.toInt());
}
