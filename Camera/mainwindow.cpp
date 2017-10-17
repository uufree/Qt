#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    camera = new QCamera(this);
    viewfinder = new QCameraViewfinder(this);
    imageCapture = new QCameraImageCapture(camera);

    ui->ImageView->addWidget(viewfinder);
    ui->ImageCapture->setScaledContents(true);

    connect(imageCapture,SIGNAL(imageCaptured(int,QImage)),this,SLOT(displayImage(int,QImage)));
    connect(ui->captureButton,SIGNAL(clicked()),this,SLOT(captureImage()));
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(saveImage()));
    connect(ui->quitButton,SIGNAL(clicked()),this,SLOT(quit()));

    camera->setViewfinder(viewfinder);
    camera->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::captureImage()
{
    imageCapture->capture();
}

void MainWindow::displayImage(int,QImage image)
{
    ui->ImageCapture->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::saveImage()
{
    QString imageName = QFileDialog::getSaveFileName(this,tr("save file"),".",tr("*.jpg"));
    if(imageName.isEmpty())
    {
       qDebug() << "save error!" << endl;
       return;
    }

    const QPixmap* pixMap = ui->ImageCapture->pixmap();
    if(pixMap)
        pixMap->save(imageName);
}
