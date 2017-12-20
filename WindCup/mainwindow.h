#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QPushButton>
#include<QTableWidget>
#include<QLineEdit>
#include<QTableWidget>
#include<QComboBox>

#include<QDate>
#include<QTime>
#include<QTimer>
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QVector>
#include<QMap>
#include<QString>
#include<QDebug>
#include<QEvent>
#include<QPainter>
#include<QColor>
#include<QPaintEvent>
#include<QFile>
#include<QFile>
#include<QDataStream>

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

protected:
    void paintEvent(QPaintEvent* event);

private:
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
    static const int systemSize = 100;//Y方向的单位长度
    int currentCups;//当前风杯数量
    int currentCupIndex;
    QString currentFile;

    SettingData settingData;//设置区信息
    QSerialPort* currentSerialPort;//当前的串口
    QTimer* serialTimer;//串口时间定时器
    QTimer* timeTimer;//1s响应一次
    QDate* date;//日期
    QTime* time;//时间
    int year,mouth,day;
    QString dateStr,timeStr;//日期与实践
    QMap<uint8_t,QPushButton*> cupList;//
    QMap<uint8_t,CUP_STATE> addrList;//每个风杯的地址
    QMap<uint8_t,QString> nameList;//使用地址索引大气压与风杯的名称信息，修改后的cupNameList
    QMap<uint8_t,double> speedList;//使用地址索引大气压与风杯的数据，修改后的currentSpeedList
    QVector<QString> tableGroupList;//数据列表显示时需要的信息,‘第一组：’
    QVector<double> electricalData;

//坐标系的三点图
    QPoint Point1,Point2,Point3;
    int SizeX,SizeY;
    QVector<double> lineChartMessage;//画折线图需要的信息，像队列一样使用

    double averageSpeed,currentVolume,negPressure,atmPressure;

    QVector<double> exportDataList;//每一次加载/展示的数据
    QTableWidget* widget;//展示数据信息需要的表格
};

#endif // MAINWINDOW_H
