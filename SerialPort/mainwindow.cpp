#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    foreach(const QSerialPortInfo& info,QSerial::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
