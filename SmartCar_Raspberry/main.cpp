#include<QApplication>
#include<QCoreApplication>
#include<QTcpServer>
#include<QTcpSocket>
#include<QDataStream>

class ClientSocket;

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpServer(QObject* parent) : QTcpServer(parent)
    {};

private:
    void incomingConnection();
}

class ClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    ClientSocket(QObject* parent) : QTcpSocket(parent);
private slots:
    void readInSocket();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTcpServer server;


    return a.exec();
}
