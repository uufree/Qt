#include "mainwindow.h"
#include<QAction>
#include<QMenuBar>
#include<QMessageBox>
#include<QStatusBar>
#include<QToolBar>
#include<QKeySequence>
#include<QDialog>
#include<QDebug>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));
    openAction = new QAction(QIcon(":/image/uuchen.jpeg"),tr("open..."),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open and exit file!"));

    connect(openAction,SIGNAL(triggered(bool)),this,SLOT(open(bool)));

    QMenu* file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar* tool = addToolBar(tr("&file"));
    tool->addAction(openAction);

    statusBar();
}

MainWindow::~MainWindow()
{
}

void MainWindow::open(bool ol)
{
    if(QMessageBox::Yes == QMessageBox::question(this,tr("Question"),tr("Are you OK?"),QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes))
        QMessageBox::information(this,tr("Hummm"),tr("I'm OK!"));
    else
        QMessageBox::information(this,tr("Hummm"),tr("I'm Sorry!"));
}
