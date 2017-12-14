#include<QApplication>
#include<QDebug>
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QFile>
#include<QDataStream>
#include<QVector>
#include<QTableWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("/home/uuchen/ui");
    if(file.exists())
        file.remove();
/*
    //假设目前有8组数s
    for(int i=0;i<288;i++)
        vec1.append(i);

    QFile currentFile("/home/uuchen/WindCup.dat");
    if(!currentFile.open(QIODevice::ReadWrite))
        qDebug() << "open file error!";
    QDataStream out(&currentFile);
    out << vec1;
    currentFile.close();

    QFile openFile("/home/uuchen/WindCup.dat");
    if(!openFile.open(QIODevice::ReadWrite))
        qDebug() << "open file error!";
    QVector<double> vec2;
    QDataStream in(&openFile);
    in >> vec2;
    if(vec2.size() <= 0)
        return 0;
    openFile.close();

    int row = (9 + 1) * 8;
    QTableWidget widget;
    widget.setColumnCount(4);//列
    widget.setRowCount(row);//行

    QTableWidgetItem* item1 = new QTableWidgetItem;
    item1->setText("当前风速");
    widget.setHorizontalHeaderItem(0,item1);
    QTableWidgetItem* item2 = new QTableWidgetItem;
    item2->setText("平均风速");
    widget.setHorizontalHeaderItem(1,item2);
    QTableWidgetItem* item3 = new QTableWidgetItem;
    item3->setText("当前风量");
    widget.setHorizontalHeaderItem(2,item3);
    QTableWidgetItem* item4 = new QTableWidgetItem;
    item4->setText("平均风量");
    widget.setHorizontalHeaderItem(3,item4);

//初始化表格
    for(int i=0;i<row / 10;i++)
    {
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText("第一组:");
        widget.setVerticalHeaderItem(i * 10,item);
        for(int j = 1;j<10;j++)
        {
            QTableWidgetItem* item = new QTableWidgetItem;
            if(j < 10)
                item->setText(QString::number(j));
            else
                item->setText("");
            widget.setVerticalHeaderItem(i * 10 + j,item);
        }
    }

    for(int i=0;i<row/10;i++)
    {
        for(int j = 1;j < 10;j++)
        {
            for(int k = 0;k<4;k++)
            {
                widget.setItem(i * 10 + j,k,new QTableWidgetItem(QString::number(vec2.front())));
                vec2.pop_front();
            }
        }
    }

    widget.show();
*/
    return a.exec();
}
