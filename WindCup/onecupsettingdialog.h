#ifndef ONECUPSETTINGDIALOG_H
#define ONECUPSETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class OneCupSettingDialog;
}

class OneCupSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OneCupSettingDialog(QWidget *parent = 0);
    ~OneCupSettingDialog();

private:
    Ui::OneCupSettingDialog *ui;
};

#endif // ONECUPSETTINGDIALOG_H
