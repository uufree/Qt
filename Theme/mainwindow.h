#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QVector>
#include<QString>

#include"settingdialog.h"
#include"circledata.h"
#include"global.h"
#include"linechart.h"

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
    void handleFlowLine(int type);
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
    void flowCallBack();
    void pressCallBack();
    void updateCurrentMessage();
    void updateInformMessage(const QString& str);//更新通知信息

private:
    Ui::MainWindow *ui;
    SettingDialog* settingDialog;
    QVector<double> pressDataList;
    QVector<double> waterDataList;
    QVector<double> flowDataList;
    QTimer* timer;
    QTimer* time;

    QString waterNote;
    QString flowNote;
    QString pressNote;

    double waterCollection,waterProject;
    double pressCollection,pressProject;
    double flowCollection,flowProject;
};

#endif // MAINWINDOW_H
