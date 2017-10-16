#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include<QTcpSocket>

class ClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    ClientSocket(QObject* parent) : QTcpSocket(parent)
    {
        connect(this,SIGNAL(readyRead),this,SLOT(readInSocket));
        connect(this,SIGNAL(disconnected),this,SLOT(deleteLater));
    }

private slots:
    void readInSocket();
};

#endif // CLIENTSOCKET_H
