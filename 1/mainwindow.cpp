#include<QAction>
#include<QMenuBar>
#include<QMessageBox>
#include<QStatusBar>
#include<QToolBar>
#include<QDebug>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));
    openAction = new QAction(QIcon(":/images/uuchen.jpeg"),tr("&open..."),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction,&QAction::triggered,this,&MainWindow::open);

    QMenu* file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar* toolbar = addToolBar(tr("&File"));
    toolbar->addAction(openAction);

    statusBar();
}

MainWindow::~MainWindow()
{}

void MainWindow::open()
{
    QDialog dialog(this);
    dialog.setWindowTitle(tr("Hello,World!"));
    dialog.exec();
    qDebug() << dialog.result();
}
