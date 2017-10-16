#include<QApplication>
#include<QCoreApplication>
#include"clientsocket.h"
#include"tcpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TcpServer server;
    if(!server.listen(QHostAddress::AnyIPv4,6666))
    {
        qDebug() << "Failed to bind the port!" << endl;
        return -1;
    }

    qDebug() << "listen is ok~" << endl;

    return a.exec();
}
