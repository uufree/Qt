#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QCamera>
#include<QCameraViewfinder>
#include<QCameraImageCapture>
#include<QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void captureImage();
    void displayImage(int,QImage);
    void saveImage();

private:
    Ui::MainWindow *ui;
    QCamera* camera;
    QCameraViewfinder* viewfinder;
    QCameraImageCapture* imageCapture;
};

#endif // MAINWINDOW_H
