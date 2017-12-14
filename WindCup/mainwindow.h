#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QDateTime>
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QTimer>
#include<QVector>
#include<QString>
#include<QPushButton>
#include<QByteArray>
#include<QTime>
#include<QDebug>
#include<QEvent>
#include<QPainter>
#include<QColor>
#include<QPaintEvent>
#include<QFile>

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
    void startClicked();//finish
    void flushClicked();//finish
    void exportDataClicked();//no
    void handleTimeout();//ok
    void updateTime();//ok

    void cupButtonClicked0();
    void cupButtonClicked1();
    void cupButtonClicked2();
    void cupButtonClicked3();
    void cupButtonClicked4();
    void cupButtonClicked5();
    void cupButtonClicked6();
    void cupButtonClicked7();
    void cupButtonClicked8();
    void cupButtonClicked9();
    void cupButtonClicked10();
    void cupButtonClicked11();
    void cupButtonClicked12();
    void cupButtonClicked13();
    void cupButtonClicked14();
    void cupButtonClicked15();
    void cupButtonClicked16();
    void cupButtonClicked17();
    void cupButtonClicked18();
    void cupButtonClicked19();
    void cupButtonClicked20();
    void cupButtonClicked21();
    void cupButtonClicked22();
    void cupButtonClicked23();
    void cupButtonClicked24();
    void cupButtonClicked25();
    void cupButtonClicked26();
    void cupButtonClicked27();
    void cupButtonClicked28();
    void cupButtonClicked29();
    void cupButtonClicked30();
    void cupButtonClicked31();

protected:
    void paintEvent(QPaintEvent* event);

private:
//初始化信息与清理信息
    void initSettingArea();//ok
    void initCurrentDisplayArea();//ok
    void initLineChart();//no
    void initSpeed();//ok
    void initAll();//ok

    void clearCurrentMessage();//ok
    void clearLineChart();//ok
    void clearSpeed();//ok
    void clearAll();//ok

//作为公有槽的内部函数使用
    void collectSettingMessage();//ok
    void start();//ok
    void writeDataInFile();//将exportDataList中的数据写入文件中
    void readDataInFile();//从文件中读取数据
//绘制折现图的函数
    void paintSystem();
    void paintLineChart();

private:
    Ui::MainWindow *ui;
    static const int maxCups = 32;
    static const int defaultCups = 9;
    static const int systemSize = 10;
    int currentCups;
    uint32_t seconds;

    SettingData settingData;
    QSerialPort* currentSerialPort;
    QTimer* serialTimer;
    QTimer* timeTimer;
    QTime* dateTime;
    QString dateTimeStr;
    QVector<QPushButton*> cupList;
    QVector<char> addrList;//在
    QVector<QString> cupNameList;

//坐标系的三点图
    QPoint Point1,Point2,Point3;
    int SizeX,SizeY;

    double currentSpeed[32];
    double currentVolume[32];
    double averageSpeed[32];
    double averageVolume[32];

    QVector<double> lineChartMessage;
    QVector<double> exportDataList;
};

#endif // MAINWINDOW_H
