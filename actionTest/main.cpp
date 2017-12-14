#include<QApplication>
#include<QDebug>
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    foreach(const QSerialPortInfo& info,QSerialPortInfo::availablePorts())
    {
        qDebug() << info.portName();
    }

    return a.exec();
}
