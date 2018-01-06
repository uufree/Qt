#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include"global.h"

namespace Ui {
class SettingDialog;
}


class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

public slots:
    void clickSaveButton();
    void clickDefaultButton();
    void clickconfirmButton();

private:
    void setSettingData();

private:
    Ui::SettingDialog *ui;
};

#endif // SETTINGDIALOG_H
