/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *acquireStyle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *testCount;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QComboBox *waterColor;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_13;
    QComboBox *flowColor;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_14;
    QComboBox *pressColor;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QComboBox *waterLinestyle;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *timeMin;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *timeMax;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDoubleSpinBox *valueMin;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDoubleSpinBox *valueMax;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QComboBox *flowLineStyle;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_12;
    QComboBox *pressLineStyle;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *defaultButton;
    QPushButton *saveButton;
    QPushButton *confirmButton;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QStringLiteral("SettingDialog"));
        SettingDialog->resize(488, 300);
        gridLayout = new QGridLayout(SettingDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SettingDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        acquireStyle = new QComboBox(SettingDialog);
        acquireStyle->setObjectName(QStringLiteral("acquireStyle"));

        horizontalLayout->addWidget(acquireStyle);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(SettingDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        testCount = new QSpinBox(SettingDialog);
        testCount->setObjectName(QStringLiteral("testCount"));
        testCount->setMaximum(10000);

        horizontalLayout_2->addWidget(testCount);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(SettingDialog);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_10->addWidget(label_9);

        waterColor = new QComboBox(SettingDialog);
        waterColor->setObjectName(QStringLiteral("waterColor"));

        horizontalLayout_10->addWidget(waterColor);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_13 = new QLabel(SettingDialog);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_14->addWidget(label_13);

        flowColor = new QComboBox(SettingDialog);
        flowColor->setObjectName(QStringLiteral("flowColor"));

        horizontalLayout_14->addWidget(flowColor);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_14 = new QLabel(SettingDialog);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_15->addWidget(label_14);

        pressColor = new QComboBox(SettingDialog);
        pressColor->setObjectName(QStringLiteral("pressColor"));

        horizontalLayout_15->addWidget(pressColor);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_10 = new QLabel(SettingDialog);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_11->addWidget(label_10);

        waterLinestyle = new QComboBox(SettingDialog);
        waterLinestyle->setObjectName(QStringLiteral("waterLinestyle"));

        horizontalLayout_11->addWidget(waterLinestyle);


        verticalLayout->addLayout(horizontalLayout_11);


        horizontalLayout_8->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(SettingDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        timeMin = new QDoubleSpinBox(SettingDialog);
        timeMin->setObjectName(QStringLiteral("timeMin"));
        timeMin->setMaximum(10000);

        horizontalLayout_3->addWidget(timeMin);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(SettingDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        timeMax = new QDoubleSpinBox(SettingDialog);
        timeMax->setObjectName(QStringLiteral("timeMax"));
        timeMax->setMaximum(10000);

        horizontalLayout_4->addWidget(timeMax);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(SettingDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        valueMin = new QDoubleSpinBox(SettingDialog);
        valueMin->setObjectName(QStringLiteral("valueMin"));
        valueMin->setMaximum(10000);

        horizontalLayout_5->addWidget(valueMin);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(SettingDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        valueMax = new QDoubleSpinBox(SettingDialog);
        valueMax->setObjectName(QStringLiteral("valueMax"));
        valueMax->setMaximum(10000);

        horizontalLayout_6->addWidget(valueMax);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_11 = new QLabel(SettingDialog);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_12->addWidget(label_11);

        flowLineStyle = new QComboBox(SettingDialog);
        flowLineStyle->setObjectName(QStringLiteral("flowLineStyle"));

        horizontalLayout_12->addWidget(flowLineStyle);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_12 = new QLabel(SettingDialog);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_13->addWidget(label_12);

        pressLineStyle = new QComboBox(SettingDialog);
        pressLineStyle->setObjectName(QStringLiteral("pressLineStyle"));

        horizontalLayout_13->addWidget(pressLineStyle);


        verticalLayout_2->addLayout(horizontalLayout_13);


        horizontalLayout_8->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        defaultButton = new QPushButton(SettingDialog);
        defaultButton->setObjectName(QStringLiteral("defaultButton"));

        horizontalLayout_7->addWidget(defaultButton);

        saveButton = new QPushButton(SettingDialog);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout_7->addWidget(saveButton);

        confirmButton = new QPushButton(SettingDialog);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));

        horizontalLayout_7->addWidget(confirmButton);


        verticalLayout_3->addLayout(horizontalLayout_7);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        QWidget::setTabOrder(acquireStyle, testCount);
        QWidget::setTabOrder(testCount, waterColor);
        QWidget::setTabOrder(waterColor, flowColor);
        QWidget::setTabOrder(flowColor, pressColor);
        QWidget::setTabOrder(pressColor, waterLinestyle);
        QWidget::setTabOrder(waterLinestyle, flowLineStyle);
        QWidget::setTabOrder(flowLineStyle, pressLineStyle);
        QWidget::setTabOrder(pressLineStyle, saveButton);
        QWidget::setTabOrder(saveButton, confirmButton);
        QWidget::setTabOrder(confirmButton, defaultButton);

        retranslateUi(SettingDialog);

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QApplication::translate("SettingDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("SettingDialog", "\351\207\207\351\233\206\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        acquireStyle->clear();
        acquireStyle->insertItems(0, QStringList()
         << QApplication::translate("SettingDialog", "\346\211\213\345\212\250", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "100ms", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "200ms", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "400ms", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "600ms", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "800ms", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "1s", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "2s", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "3s", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "5s", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "8s", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "10s", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "15s", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "30s", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "1min", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "2min", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "3min", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "4min", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "5min", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "6min", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "7min", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "8min", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "9min", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "10min", Q_NULLPTR)
         << QString()
        );
        label_2->setText(QApplication::translate("SettingDialog", "\346\265\213\347\202\271\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("SettingDialog", "\346\260\264\344\275\215\351\242\234\350\211\262\357\274\232", Q_NULLPTR));
        waterColor->clear();
        waterColor->insertItems(0, QStringList()
         << QApplication::translate("SettingDialog", "Green", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "White", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Black", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Cyan", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkCyan", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Red", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkRed", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Megenta", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkMegenta", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkGreen", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Yellow", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkYellow", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Blue", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkBlue", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Gray", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkGray", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "LightGray", Q_NULLPTR)
        );
        label_13->setText(QApplication::translate("SettingDialog", "\346\265\201\351\207\217\351\242\234\350\211\262\357\274\232", Q_NULLPTR));
        flowColor->clear();
        flowColor->insertItems(0, QStringList()
         << QApplication::translate("SettingDialog", "White", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Black", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Cyan", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkCyan", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Red", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkRed", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Megenta", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkMegenta", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Green", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkGreen", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Yellow", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkYellow", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Blue", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkBlue", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Gray", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkGray", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "LightGray", Q_NULLPTR)
        );
        label_14->setText(QApplication::translate("SettingDialog", "\345\216\213\345\212\233\351\242\234\350\211\262\357\274\232", Q_NULLPTR));
        pressColor->clear();
        pressColor->insertItems(0, QStringList()
         << QApplication::translate("SettingDialog", "Yellow", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "White", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Black", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Cyan", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkCyan", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Red", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkRed", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Megenta", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkMegenta", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Green", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkGreen", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkYellow", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Blue", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkBlue", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Gray", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DarkGray", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "LightGray", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("SettingDialog", "\346\260\264\344\275\215\347\272\277\345\236\213\357\274\232", Q_NULLPTR));
        waterLinestyle->clear();
        waterLinestyle->insertItems(0, QStringList()
         << QApplication::translate("SettingDialog", "SolidLine", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DotLine", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DashLine", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DashDotLine", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DashDotDotLine", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("SettingDialog", "\346\227\266\351\227\264\350\275\264\346\234\200\345\260\217\345\200\274\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("SettingDialog", "\346\227\266\351\227\264\350\275\264\346\234\200\345\244\247\345\200\274\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("SettingDialog", "\345\271\205\345\200\274\350\275\264\346\234\200\345\260\217\345\200\274\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("SettingDialog", "\345\271\205\345\200\274\350\275\264\346\234\200\345\244\247\345\200\274\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("SettingDialog", "\346\265\201\351\207\217\347\272\277\345\236\213\357\274\232", Q_NULLPTR));
        flowLineStyle->clear();
        flowLineStyle->insertItems(0, QStringList()
         << QApplication::translate("SettingDialog", "SolidLine", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DashLine", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DashDotLine", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DashDotDotLine", Q_NULLPTR)
        );
        label_12->setText(QApplication::translate("SettingDialog", "\345\216\213\345\212\233\347\272\277\345\236\213\357\274\232", Q_NULLPTR));
        pressLineStyle->clear();
        pressLineStyle->insertItems(0, QStringList()
         << QApplication::translate("SettingDialog", "SolidLine", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DashLine", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DashDotLine", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "DashDotDotLine", Q_NULLPTR)
        );
        defaultButton->setText(QApplication::translate("SettingDialog", "\351\273\230\350\256\244\345\200\274", Q_NULLPTR));
        saveButton->setText(QApplication::translate("SettingDialog", "\344\277\235\345\255\230", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("SettingDialog", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
