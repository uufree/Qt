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
    clientSocket->connectToHost(QHostAddress("127.0.0.1"),6666);
//    QDataStream out(clientSocket);
//    out.setVersion(QDataStream::Qt_5_7);

    qDebug() << "client will send message~" << endl;
    clientSocket->write("hello,Qt!");
    clientSocket->write("hello,Qt!");
    clientSocket->write("hello,Qt!");
    qDebug() << "client is already send message!" << endl;

    a.exit();
    return a.exec();
}
