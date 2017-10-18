#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QFileDialog>
#include<QTimer>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

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
    void saveImage();
    void handleCameraData();
    void handleQuit();
private:
    QImage matToQImage(cv::Mat& cvImg);

private:
    Ui::MainWindow *ui;
    cv::VideoCapture cap;
    QTimer* timer;
};

#endif // MAINWINDOW_H
