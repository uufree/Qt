#ifndef NEWSPAPER_H
#define NEWSPAPER_H
#include <QObject>
#include<QString>
#include<QDebug>

class NewsPaper : public QObject
{
    Q_OBJECT
public:
    NewsPaper(QString name_) : name(name_)	{}

    void send()
    {
        emit newPaper(name);
    }
signals:
    void newPaper(const QString& name_);

private:
    QString name;
};

class Reader : public QObject
{
    Q_OBJECT
public:
    Reader(){}
public slots:
    void readNewsPaper(const QString& name_)
    {
        qDebug() << "Receive a new message: " << name_ << endl;
    }
};

#endif // NEWSPAPER_H
