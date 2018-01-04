#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display()
{
    ui->circleData->resize(800,400);
    ui->lineChart->start();
    update();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->lineChart->resize(ui->circleData->width(),ui->circleData->height());
}
