/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *addressLabel;
    QLineEdit *addressLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *portlabel;
    QLineEdit *portLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelButton;
    QPushButton *connectButton;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QStringLiteral("loginDialog"));
        loginDialog->resize(412, 204);
        widget = new QWidget(loginDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 20, 311, 141));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addressLabel = new QLabel(widget);
        addressLabel->setObjectName(QStringLiteral("addressLabel"));

        horizontalLayout->addWidget(addressLabel);

        addressLineEdit = new QLineEdit(widget);
        addressLineEdit->setObjectName(QStringLiteral("addressLineEdit"));

        horizontalLayout->addWidget(addressLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        portlabel = new QLabel(widget);
        portlabel->setObjectName(QStringLiteral("portlabel"));

        horizontalLayout_2->addWidget(portlabel);

        portLineEdit = new QLineEdit(widget);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));

        horizontalLayout_2->addWidget(portLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);

        connectButton = new QPushButton(widget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setEnabled(false);

        horizontalLayout_3->addWidget(connectButton);


        verticalLayout->addLayout(horizontalLayout_3);

#ifndef QT_NO_SHORTCUT
        portlabel->setBuddy(portLineEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(addressLineEdit, portLineEdit);
        QWidget::setTabOrder(portLineEdit, connectButton);
        QWidget::setTabOrder(connectButton, cancelButton);

        retranslateUi(loginDialog);

        connectButton->setDefault(true);


        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "Login", 0));
        addressLabel->setText(QApplication::translate("loginDialog", "IP\345\234\260\345\235\200\357\274\232", 0));
        portlabel->setText(QApplication::translate("loginDialog", "\347\253\257\345\217\243\345\217\267\357\274\232", 0));
        cancelButton->setText(QApplication::translate("loginDialog", "\345\217\226\346\266\210", 0));
        connectButton->setText(QApplication::translate("loginDialog", "\350\277\236\346\216\245", 0));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
