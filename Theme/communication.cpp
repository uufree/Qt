#include "communication.h"
#include<QSerialPortInfo>
#include"settingdialog.h"

Communication::Communication() :
    socket(new QTcpSocket(this)),
    port(new QSerialPort(this)),
    index(1)
{
    uint8_t press_[8] = {0x02,0x03,0x00,0x04,0x00,0x01,0xc5,0xf8};
    uint8_t water_[8] = {0x01,0x03,0x00,0x04,0x00,0x01,0xc5,0xcb};
    uint8_t flow1_[8] = {0x03,0x03,0x00,0x00,0x00,0x02,0xc5,0xe9};
    uint8_t flow2_[8] = {0x04,0x03,0x00,0x00,0x00,0x02,0xc4,0x5e};

    for(int i=0;i<8;i++)
    {
        press[i] = press_[i];
        water[i] = water_[i];
        flow1[i] = flow1_[i];
        flow2[i] = flow2_[i];
    }

    updateSerialPortInfo();
}

void Communication::updateSerialPortInfo()
{
    foreach (const QSerialPortInfo& info, QSerialPortInfo::availablePorts())
        serialPortNameList.append(info.portName());
}

void Communication::openSerialPort(const QString &portName)
{
    if(port)
        delete port;

    port = new QSerialPort(this);
    port->setPortName(portName);
    port->open(QIODevice::ReadWrite);
    port->setBaudRate(QSerialPort::Baud9600);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);

    connect(port,SIGNAL(readyRead()),this,SLOT(handleSerialPort()));
}

void Communication::openTcpSocket()
{
    if(socket)
        delete socket;

    socket = new QTcpSocket(this);
    socket->connectToHost("192.168.1.20",4001);

    connect(socket,SIGNAL(readyRead()),this,SLOT(handleTcpSocket()));
}

void Communication::closeSerialPort()
{
    port->close();
}

void Communication::closeTcpSocket()
{
    socket->close();
}

void Communication::sendMessage()
{
    switch(index)
    {
        case 1:
        {
            QByteArray array(press);
            socket->write(array);
            break;
        }
        case 2:
        {
            QByteArray array(water);
            port->write(array);
            break;
        }
        case 3:
        {
            QByteArray array(flow1);
            socket->write(array);
            break;
        }
        case 4:
        {
            QByteArray array(flow2);
            socket->write(array);
            break;
        }
    }

    ++index;
    if(index > 4)
        index = 1;
}

void Communication::handleSerialPort()
{
    QByteArray array = port->readAll();
    if(array.size() != 7)
        return;

    short number = (int16_t)((array[3] << 8) + array[4]);
    if(waterCallBack)
        waterCallBack(number);
}

void Communication::handleTcpSocket()
{
    QByteArray array = socket->readAll();
    tcpBuffer.append(array);

    if(tcpBuffer.size() < 9)
        return;

    char ch = tcpBuffer[0];
    if(ch == 0x02)//press
    {
        array.clear();
        for(int i=0;i<7;i++)
        {
            array.append(tcpBuffer[0]);
            tcpBuffer.remove(0,1);
        }

        short number = (int16_t)((array[3] << 8) + array[4]);
        if(pressCallBack)
            pressCallBack(number);
    }

    if(ch == 0x03)//flow1
    {
        array.clear();
        for(int i=0;i<9;i++)
        {
            array.append(tcpBuffer[0]);
            tcpBuffer.remove(0,1);
        }
        QString str;
        str.append((char)array[3]);
        str.append((char)array[4]);
        str.append((char)array[5]);
        str.append((char)array[6]);
        float number = str.toFloat();
        if(flow1CallBack)
            flow1CallBack(number);
    }

    if(ch == 0x04)//flow2
    {
        array.clear();
        for(int i=0;i<9;i++)
        {
            array.append(tcpBuffer[0]);
            tcpBuffer.remove(0,1);
        }
        QString str;
        str.append((char)array[3]);
        str.append((char)array[4]);
        str.append((char)array[5]);
        str.append((char)array[6]);
        float number = str.toFloat();
        if(flow2CallBack)
            flow2CallBack(number);
    }
}
