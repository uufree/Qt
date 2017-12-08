#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PaintedWidget widget;
    widget.show();

    return a.exec();
}
