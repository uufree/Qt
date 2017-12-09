#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QTimer>
#include<QVector>
#include<QString>
#include<QMap>

#include"global.h"

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
    void startClicked();
    void clearClicked();
    void exportDataClicked();
    void cupButtonClicked();
    void handleTimeout();

private:
    void initSerialPort();
    void initSignalsAndSlots();
    void clearCurrentMessage();
    void clearLineChart();
    void clearAll();
    void start();
    void stop();
    void setDefaultSetting();

private:
    Ui::MainWindow *ui;
    static const int maxSerialPort = 32;
    static const int defaultSerialPort = 9;

    SettingData data;
    QMap<QString,QSerialPort*> aliveSerialPortMap;
    QSerialPort* currentSerialPort;
    QTimer* timer;
};

#endif // MAINWINDOW_H
