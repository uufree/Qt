#include "settingdialog.h"
#include "ui_settingdialog.h"

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    QObject::connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(saveAndUsedClicked()));
    QObject::connect(ui->closeButton,SIGNAL(clicked()),this,SLOT(close()));
}

void SettingDialog::saveAndUsedClicked()
{
    data->baud = ui->baudBox->currentText();
    data->data = ui->dataBox->currentText();
    data->check = ui->checkBox->currentText();
    data->stop = ui->stopBox->currentText();
    data->testArea = ui->testArea->text();
    data->testCups = ui->testCups->currentText();

    emit start(data);
}

SettingDialog::~SettingDialog()
{
    delete ui;
}
