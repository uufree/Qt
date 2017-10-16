#include"mainwindow.h"
#include<QApplication>
#include<QCoreApplication>
#include<QMutex>
#include<QThread>
#include<QTcpSocket>
#include<QHostAddress>
#include<QDataStream>
#include<QByteArray>
#include<iostream>
#include<string>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTcpSocket* clientSocket = new QTcpSocket;
    clientSocket->connectToHost(QHostAddress("192.168.1.105"),6666);
    QDataStream out(clientSocket);
    out.setVersion(QDataStream::Qt_5_7);

    qDebug() << "client will send message~" << endl;
    out << "hello,world!";
    qDebug() << "client is already send message!" << endl;

    a.exit();
    return a.exec();
}
