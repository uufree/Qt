#include<QApplication>
#include<QFileDialog>
#include<QString>
#include<QDebug>
#include<QInputDialog>
#include"textticker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextTicker ticker;
    ticker.show();

    return a.exec();
}
