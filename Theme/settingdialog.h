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

    void setHandleSettingCallback(const HandleSettingMessageCallBack& callBack_)
    {callBack = callBack_;}

    void updateSerialPortInfo(const QVector<QString>& serialPortList);

public slots:
    void clickSaveButton();
    void clickDefaultButton();
    void clickConfirmButton();

private:
    void setSettingData();

private:
    Ui::SettingDialog *ui;
    HandleSettingMessageCallBack callBack;
};

#endif // SETTINGDIALOG_H
