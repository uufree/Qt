#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include<QDialog>
#include<QString>
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

signals:
    void start(const SettingData& _data);

public slots:
    void saveAndUsedClicked();

private:
    Ui::SettingDialog *ui;
    SettingData data;
};

#endif // SETTINGDIALOG_H
