#include "mainwindow.h"
#include<QApplication>
#include"circledata.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    QWidget* widget = new CircleData;
    widget->show();

    return a.exec();
}
