#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QByteArray>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    foreach(const QSerialPortInfo& info,QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->portBox->addItem(serial.portName());
            serial.close();
        }
    }

    ui->baudBox->setCurrentIndex(6);
    ui->sendButton->setEnabled(false);
    qDebug() << "初始化完毕!" << endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearButtonClicked()
{
    ui->recvEdit->clear();
}

void MainWindow::sendButtonClicked()
{
    serialPort->write(ui->sendEdit->toPlainText().toLatin1());
}

void MainWindow::openButtonCliked()
{
    if(ui->openButton->text() == tr("打开串口"))
    {
        serialPort = new QSerialPort;
        serialPort->setPortName(ui->portBox->currentText());
        serialPort->open(QIODevice::ReadWrite);//读写模式
        serialPort->setBaudRate(QSerialPort::Baud9600);//波特率
        serialPort->setDataBits(QSerialPort::Data8);//数据位
        serialPort->setStopBits(QSerialPort::OneStop);//停止位
        serialPort->setFlowControl(QSerialPort::NoFlowControl);
        ui->openButton->setText(tr("关闭串口"));
        ui->sendButton->setEnabled(true);
        QObject::connect(serialPort,SIGNAL(readyRead()),this,SLOT(readData()));
    }
    else
    {
        serialPort->clear();
        serialPort->close();
        serialPort->deleteLater();
        ui->openButton->setText(tr("打开串口"));
        ui->sendButton->setEnabled(false);
    }
}

void MainWindow::readData()
{
    QByteArray buf = serialPort->readAll();
    if(buf.count() > 0)
    {
        QString str = ui->recvEdit->toPlainText();
        str += tr(buf);
        ui->recvEdit->clear();
        ui->recvEdit->append(str);
    }
    buf.clear();
}
