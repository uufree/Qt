#include "onecupsettingdialog.h"
#include "ui_onecupsettingdialog.h"

OneCupSettingDialog::OneCupSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OneCupSettingDialog)
{
    ui->setupUi(this);
}

OneCupSettingDialog::~OneCupSettingDialog()
{
    delete ui;
}
