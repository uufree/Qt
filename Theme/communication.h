#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include<QTcpSocket>
#include<QTcpServer>
#include<QSerialPort>
#include<QSerialPortInfo>
#include<QByteArray>

class Communication
{
public:
    Communication();

public slots:
    void handleSerialPort();
    void handleTcpServer();

private:
    void initTcpServer();
    void initSerialPort();
    void closeTcpServer();
    void closeSerialPort();

private:
    QTcpServer* server;//485控制的三个信息
    QSerialPort* port;//地表的水位
};

#endif // COMMUNICATION_H
