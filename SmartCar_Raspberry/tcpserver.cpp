#include "tcpserver.h"

TcpServer::TcpServer() :
    server(new QTcpServer)
{
    connect(server,SIGNAL(newConnection()),this,SLOT(handleNewConnection()));
}

int TcpServer::listen()
{
    if(!server->listen(QHostAddress::Any,6666))
    {
        qDebug() << "Failed to bind the port!" << endl;
        return -1;
    }
    return 0;
}


TcpServer::~TcpServer()
{
    if(client)
        delete client;
}

void TcpServer::handleNewConnection()
{
    client = server->nextPendingConnection();
    connect(client,SIGNAL(readyRead()),this,SLOT(readInSocket()));
}

void TcpServer::readInSocket()
{
    QString str = client->readAll();
    qDebug() << str << endl;
}
