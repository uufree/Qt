#include "mainwindow.h"
#include "ui_mainwindow.h"

extern struct SettingData settingData;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    settingDialog = new SettingDialog(this);

    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(clickStartButton()));
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(clickSaveButton()));
    connect(ui->settingButton,SIGNAL(clicked()),this,SLOT(clickSettingButton()));
    connect(ui->switchButton,SIGNAL(clicked()),this,SLOT(clickSwitchButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display()
{
    ui->circleData->resize(800,400);
    ui->lineChart->start();
    update();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->lineChart->resize(ui->circleData->width(),ui->circleData->height());
}

void MainWindow::setting()
{
    ui->circleData->setting(settingData);
    ui->lineChart->setting(settingData);
}

//切换下一组数据，暂时不写
void MainWindow::clickSwitchButton()
{
}

//保存一组数据
void MainWindow::clickSaveButton()
{
}

//弹出SettingDialog对话框
void MainWindow::clickSettingButton()
{
    settingDialog->show();
}

//开始启动
void MainWindow::clickStartButton()
{
    if(ui->startButton->text() == "开始")
    {//启动
        ui->startButton->setText("停止");
        ui->saveButton->setText("保存数据");
        if(settingData.acquireStyle == "手动")
            ui->saveButton->setEnabled(true);
        else
        {
            ui->saveButton->setEnabled(false);
            ui->saveButton->setText(settingData.acquireStyle + "/次");
        }
        ui->switchButton->setEnabled(true);
        ui->settingButton->setEnabled(false);

        start();
    }
    else
    {//停止
        ui->startButton->setText("开始");
        ui->saveButton->setText("历史数据");
        ui->saveButton->setEnabled(true);
        ui->switchButton->setEnabled(false);
        ui->settingButton->setEnabled(true);

        stop();
    }
}

void MainWindow::start()
{
    ui->lineChart->startAll();
    ui->lineChart->startAll();
}

void MainWindow::stop()
{
    ui->lineChart->stopAll();
    ui->circleData->stopAll();
}

void MainWindow::clearAll()
{
    ui->lineChart->clearAll();//清理图中的数据信息
    ui->circleData->clearAll();//清理图中的数据信息
}
