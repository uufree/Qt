#include "tcpserver.h"

TcpServer::TcpServer(QObject* parent) :
    QTcpServer(parent)
{
    connect(this,SIGNAL(newConnection),this,SLOT(handleNewTcpConnection));
}

void TcpServer::handleNewTcpConnection()
{
    qDebug() << "a new connection is come in!" << endl;
}
