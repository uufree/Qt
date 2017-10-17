#include"mainwindow.h"
#include<QApplication>
#include<QCoreApplication>
#include<QMutex>
#include<QThread>
#include<QTcpSocket>
#include<QHostAddress>
#include"ui_login.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
    QTcpSocket* clientSocket = new QTcpSocket;
    clientSocket->connectToHost(QHostAddress("127.0.0.1"),6666);

    clientSocket->write("hello,Qt!");
    clientSocket->write("hello,Qt!");
    clientSocket->write("hello,Qt!");
*/
    Ui::loginDialog ui;
    QDialog* dialog = new QDialog;
    ui.setupUi(dialog);
    dialog->show();
    return a.exec();
}
