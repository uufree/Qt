#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include<QObject>

class Newspaper : public QObject
{
    Q_OBJECT

public:
    Newspaper(const QString& str) : name(str)
    {}

    void send()
    {
        emit newsPaper(name);
    }

signals:
    void newsPaper(const QString& str);

private:
    QString name;

};


#endif // NEWSPAPER_H
