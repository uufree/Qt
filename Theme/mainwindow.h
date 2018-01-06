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

    void display();

public slots:
    void clickStartButton();
    void clickSaveButton();
    void clickSettingButton();
    void clickSwitchButton();

protected:
    void resizeEvent(QResizeEvent* event);

private:
    void setting();//根据settingData设置展示信息
    void start();
    void stop();
    void clearAll();

private:
    Ui::MainWindow *ui;
    SettingDialog* settingDialog;

    bool showPress,showWater,showFlow,showAll;
};

#endif // MAINWINDOW_H
