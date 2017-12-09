#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QLineEdit>
#include<QPushButton>
#include<QTableWidget>
#include<QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::initSerialPort()
{
    QString serialNameList[15] = {"com1","com2","com3","com4","com5","com6","com7","com8","com9","com10","com11","com12","com13","com14","com15"};

    for(int i=0;i < serialNameList.size();++i)
    {
        QSerialPort* port = new QSerialPort;
        QString name = serialNameList[i];
        port->setPortName(name);
        port->open(QIODevice::ReadWrite);
        port->setBaudRate(QSerialPort::Baud9600);
        port->setDataBits(QSerialPort::Data8);
        port->setParity(QSerialPort::NoParity);
        port->setStopBits(QSerialPort::OneStop);
        port->setFlowControl(QSerialPort::NoFlowControl);

        aliveSerialPortMap.insert(serialNameList[i],port);
    }

    currentSerialPort = aliveSerialPortMap["com1"];
}

void MainWindow::initSignalsAndSlots()
{
    QObject::connect(ui->startBtton,SIGNAL(clicked()),this,SLOT(startClicked()));
    QObject::connect(ui->clearButton,SIGNAL(clicked()),this,SLOT(clearClicked()));
    QObject::connect(ui->saveDataButton,SIGNAL(clicked()),this,SLOT(exportDataClicked()));

    QObject::connect(ui->E0,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->E1,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->E2,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->E3,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->E4,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->E5,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->E6,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->E7,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->E8,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->E9,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->EA,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->EB,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->EC,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->ED,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->EE,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->EF,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->F0,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->F1,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->F2,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->F3,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->F4,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->F5,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->F6,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->F7,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->F8,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->F9,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->FA,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->FB,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->FC,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->FD,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->FE,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
    QObject::connect(ui->FF,SIGNAL(clicked()),this,SLOT(cupButtonClicked()));
}

void MainWindow::clearCurrentMessage()
{
    ui->currentCup->clear();
    ui->currentAverageSpeed->clear();
    ui->currentAverageVolume->clear();
    ui->currentSpeed->clear();
    ui->currentVolume->clear();
    ui->currentWorkTime->clear();
}

//清理折线图信息
void MainWindow::clearLineChart()
{

}

void MainWindow::clearAll()
{
    clearCurrentMessage();
    clearLineChart();
}

void MainWindow::start()
{

}

void MainWindow::stop()
{

}

void MainWindow::setDefaultSetting()
{

}

MainWindow::~MainWindow()
{
    delete ui;
}
