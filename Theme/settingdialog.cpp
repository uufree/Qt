#include "settingdialog.h"
#include "ui_settingdialog.h"

struct SettingData settingData;

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);

    settingData.acquireStyle = "手动";
    settingData.testCount = 3;
    settingData.waterColor = "Green";
    settingData.flowColor = "White";
    settingData.pressColor = "Yellow";
    settingData.waterLineStyle = "SolidLine";
    settingData.pressLineStyle = "SolidLine";
    settingData.flowLineStyle = "SolidLine";
    settingData.baudRate = "9600";
    settingData.timeMin = 0;
    settingData.timeMax = 100;
    settingData.valueMin = 0;
    settingData.valueMax = 100;

    setSettingData();

    connect(ui->confirmButton,SIGNAL(clicked()),this,SLOT(clickConfirmButton()));
    connect(ui->defaultButton,SIGNAL(clicked()),this,SLOT(clickDefaultButton()));
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(clickSaveButton()));
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::clickSaveButton()
{
    settingData.acquireStyle = ui->acquireStyle->currentText();
    settingData.testCount = ui->testCount->value();
    settingData.waterColor = ui->waterColor->currentText();
    settingData.flowColor = ui->flowColor->currentText();
    settingData.pressColor = ui->pressColor->currentText();
    settingData.waterLineStyle = ui->waterLinestyle->currentText();
    settingData.pressLineStyle = ui->pressLineStyle->currentText();
    settingData.flowLineStyle = ui->flowLineStyle->currentText();
    settingData.timeMin = ui->timeMin->value();
    settingData.timeMax = ui->timeMax->value();
    settingData.valueMin = ui->valueMin->value();
    settingData.valueMax = ui->valueMax->value();
    settingData.baudRate = ui->baudRate->currentText();
    settingData.serialPort = ui->serialPort->currentText();
}

void SettingDialog::setSettingData()
{
    ui->acquireStyle->setCurrentText(settingData.acquireStyle);
    ui->testCount->setValue(settingData.testCount);
    ui->waterColor->setCurrentText(settingData.waterColor);
    ui->flowColor->setCurrentText(settingData.flowColor);
    ui->pressColor->setCurrentText(settingData.pressColor);
    ui->waterLinestyle->setCurrentText(settingData.waterLineStyle);
    ui->pressLineStyle->setCurrentText(settingData.pressLineStyle);
    ui->flowLineStyle->setCurrentText(settingData.flowLineStyle);
    ui->timeMin->setValue(settingData.timeMin);
    ui->timeMax->setValue(settingData.timeMax);
    ui->valueMin->setValue(settingData.valueMin);
    ui->valueMax->setValue(settingData.valueMax);
    ui->baudRate->setCurrentText(settingData.baudRate);
}

void SettingDialog::clickDefaultButton()
{
    settingData.acquireStyle = "手动";
    settingData.testCount = 3;
    settingData.waterColor = "Green";
    settingData.flowColor = "Red";
    settingData.pressColor = "Yellow";
    settingData.waterLineStyle = "SolidLine";
    settingData.pressLineStyle = "SolidLine";
    settingData.flowLineStyle = "SolidLine";
    settingData.timeMin = 0;
    settingData.timeMax = 100;
    settingData.valueMin = 0;
    settingData.valueMax = 100;
    settingData.baudRate = "9600";

    setSettingData();
}

void SettingDialog::clickConfirmButton()
{
    this->close();
    clickSaveButton();
    if(callBack)
        callBack(settingData);
}

void SettingDialog::updateSerialPortInfo(const QVector<QString> &serialPortList)
{
    ui->serialPort->clear();
    for(int i = 0;i < serialPortList.size();i++)
        ui->serialPort->addItem(serialPortList[i]);
}
