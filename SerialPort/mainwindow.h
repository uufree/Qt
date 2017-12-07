#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void clearButtonClicked();
    void sendButtonClicked();
    void openButtonCliked();
    void readData();

private:
    Ui::MainWindow *ui;
    QSerialPort* serialPort;
};

#endif // MAINWINDOW_H
