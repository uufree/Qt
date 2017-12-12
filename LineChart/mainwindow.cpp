#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image = QImage(X,Y,QImage::Format_RGB32);
    QColor color = qRgb(255,255,255);
    image.fill(color);
    initPainter();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initPainter()
{
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing,true);
    int xStart = 35;
    int yStart = 280;
    painter.drawRect(5,5,X-10,Y-10);
    painter.drawLine(xStart,yStart,X-30,yStart);
    painter.drawLine(xStart,yStart,xStart,30);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);

    for(int i=0;i<10;++i)
    {

    }
}
