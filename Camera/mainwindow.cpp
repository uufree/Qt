#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cap = cv::VideoCapture(0);
    if(!cap.isOpened())
    {
        qDebug() << "camera is error!" << endl;
    }
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(handleCameraData()));
    connect(ui->captureButton,SIGNAL(clicked()),this,SLOT(captureImage()));
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(saveImage()));
    connect(ui->quitButton,SIGNAL(clicked()),this,SLOT(handleQuit()));

    timer->start(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::captureImage()
{
    cv::Mat img;
    cap >> img;
    QImage image = matToQImage(img);
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

void MainWindow::handleCameraData()
{
    cv::Mat img;
    cap >> img;
    QImage image = matToQImage(img);
    ui->ImageViewer->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::handleQuit()
{
    timer->stop();
    QMainWindow::close();
}

QImage MainWindow::matToQImage(cv::Mat& cvImg)
{
    QImage qImg;

    if(cvImg.channels()==3)
    {
        cv::cvtColor(cvImg,cvImg,CV_BGR2RGB);
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols, cvImg.rows,
                    cvImg.cols*cvImg.channels(),
                    QImage::Format_RGB888);
    }
    else if(cvImg.channels()==1)
    {
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols,cvImg.rows,
                    cvImg.cols*cvImg.channels(),
                    QImage::Format_Indexed8);
    }
    else
    {
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols,cvImg.rows,
                    cvImg.cols*cvImg.channels(),
                    QImage::Format_RGB888);
    }

    return qImg;
}

