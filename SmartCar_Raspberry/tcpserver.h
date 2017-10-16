#ifndef TCPSERVER_H
#define TCPSERVER_H

#include<QTcpServer>
#include<QList>

class  ClientSocket;
class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpServer(QObject* parent = 0);

private:
    void handleNewTcpConnection();
private:
    QList<ClientSocket*> clientList;
};


#endif // TCPSERVER_H
