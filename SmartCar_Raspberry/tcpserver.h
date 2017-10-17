#ifndef TCPSERVER_H
#define TCPSERVER_H

#include<QTcpServer>
#include<QTcpSocket>
#include<QString>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    TcpServer();
    ~TcpServer();

    int listen();

private slots:
    void handleNewConnection();
    void readInSocket();
private:
    QTcpServer* server;
    QTcpSocket* client;
};

#endif // TCPSERVER_H
