#include"clientsocket.h"
#include<QDataStream>

void ClientSocket::readInSocket()
{
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_5_7);

    QString str;
    in >> str;
    qDebug() << "readInSocket: " << str << endl;
}
