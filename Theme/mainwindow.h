#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>

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

protected:
    void resizeEvent(QResizeEvent* event);

private:
    void setting();//根据settingData设置展示信息
    void start();
    void stop();

private:
    Ui::MainWindow *ui;
    SettingDialog* settingDialog;

    QTimer* timer;
};

#endif // MAINWINDOW_H
