#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include<QTcpSocket>
#include<QTcpServer>
#include<QSerialPort>
#include<QSerialPortInfo>
#include<QByteArray>
#include<QVector>
#include<QString>
#include"global.h"

class Communication : public QObject
{
    Q_OBJECT
public:
    Communication();

    const QVector<QString>& getSerialPortNameList() const
    {return serialPortNameList;}

    void setWaterCallBack(const WaterCallBack& callBack)
    {waterCallBack = callBack;}

    void setPressCallBack(const PressCallBack& callBack)
    {pressCallBack = callBack;}

    void setFlow1CallBack(const FlowCallBack& callBack)
    {flow1CallBack = callBack;}

    void setFlow2CallBack(const FlowCallBack& callBack)
    {flow2CallBack = callBack;}

    void openTcpSocket();
    void openSerialPort(const QString& portName);
    void closeTcpSocket();
    void closeSerialPort();
    void updateSerialPortInfo();

public slots:
    void handleSerialPort();
    void handleTcpSocket();
    void sendMessage();

private:
    QTcpSocket* socket;//485控制的三个信息
    QSerialPort* port;//地表的水位

    PressCallBack pressCallBack;
    WaterCallBack waterCallBack;
    FlowCallBack flow1CallBack,flow2CallBack;

    char press[8];
    char water[8];
    char flow1[8];
    char flow2[8];

    QVector<QString> serialPortNameList;
    QByteArray tcpBuffer;

    int index;
};

#endif // COMMUNICATION_H
