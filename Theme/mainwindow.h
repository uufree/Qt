#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QVector>
#include<QString>

#include"settingdialog.h"
#include"circledata.h"
#include"global.h"
#include"linechart.h"
#include"communication.h"

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
    void clickStartButton();
    void clickSaveButton();
    void clickSettingButton();
    void clickSwitchButton();
    void handleLineChartSize();
    void handlePressLine(int type);
    void handleWaterLine(int type);
    void handleFlow1Line(int type);
    void handleFlow2Line(int type);
    void testMakeData();
    void handleCurrentNote();
    void updateTime();//响应time定时器

protected:
    void resizeEvent(QResizeEvent* event);

private:
    void setting();//根据settingData设置展示信息
    void start();
    void stop();

    void waterCallBack();
    void flow1CallBack();
    void flow2CallBack();
    void pressCallBack();
    void updateCurrentMessage();
    void updateInformMessage(const QString& str);//更新通知信息
    void handleSetting(const struct SettingData& data);

//Communication CallBack
    void comWaterCallBack(short);
    void comPressCallBack(short);
    void comFlow1CallBack(float);
    void comFlow2CallBack(float);

private:
    Ui::MainWindow *ui;
    SettingDialog* settingDialog;
    QVector<double> pressDataList;
    QVector<double> waterDataList;
    QVector<double> flow1DataList;
    QVector<double> flow2DataList;
    QTimer* timer;
    QTimer* time;

    QString waterNote;
    QString flow1Note;
    QString flow2Note;
    QString pressNote;
    QString styleSheet;

    double waterCollection,waterProject;
    double pressCollection,pressProject;
    double flow1Collection,flow1Project;
    double flow2Collection,flow2Project;

    int axisXStart = 100;
    Communication* com;
};

#endif // MAINWINDOW_H
