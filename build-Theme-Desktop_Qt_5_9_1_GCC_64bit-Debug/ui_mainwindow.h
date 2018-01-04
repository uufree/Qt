/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <linechart.h>
#include "circledata.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *rollingLabel;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    CircleData *circleData;
    LineChart *lineChart;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *currentTestPoint;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *currentCollection;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *currentEngineer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLabel *currentUint;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QTextEdit *currentNote;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *startButton;
    QPushButton *saveButton;
    QPushButton *settingButton;
    QPushButton *switchButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(869, 599);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        rollingLabel = new QLabel(centralWidget);
        rollingLabel->setObjectName(QStringLiteral("rollingLabel"));

        horizontalLayout_5->addWidget(rollingLabel);

        horizontalLayout_5->setStretch(0, 11);

        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        circleData = new CircleData(centralWidget);
        circleData->setObjectName(QStringLiteral("circleData"));
        circleData->setFrameShape(QFrame::StyledPanel);
        circleData->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(circleData);

        lineChart = new LineChart(centralWidget);
        lineChart->setObjectName(QStringLiteral("lineChart"));
        circleData->raise();

        verticalLayout->addWidget(lineChart);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        currentTestPoint = new QLabel(centralWidget);
        currentTestPoint->setObjectName(QStringLiteral("currentTestPoint"));

        horizontalLayout->addWidget(currentTestPoint);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);

        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        currentCollection = new QLabel(centralWidget);
        currentCollection->setObjectName(QStringLiteral("currentCollection"));

        horizontalLayout_2->addWidget(currentCollection);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 6);

        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        currentEngineer = new QLabel(centralWidget);
        currentEngineer->setObjectName(QStringLiteral("currentEngineer"));

        horizontalLayout_3->addWidget(currentEngineer);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 6);

        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        currentUint = new QLabel(centralWidget);
        currentUint->setObjectName(QStringLiteral("currentUint"));

        horizontalLayout_4->addWidget(currentUint);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 6);

        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_3->addWidget(label_7);

        currentNote = new QTextEdit(centralWidget);
        currentNote->setObjectName(QStringLiteral("currentNote"));

        verticalLayout_3->addWidget(currentNote);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 10);

        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        verticalLayout_2->addWidget(startButton);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        verticalLayout_2->addWidget(saveButton);

        settingButton = new QPushButton(centralWidget);
        settingButton->setObjectName(QStringLiteral("settingButton"));

        verticalLayout_2->addWidget(settingButton);

        switchButton = new QPushButton(centralWidget);
        switchButton->setObjectName(QStringLiteral("switchButton"));

        verticalLayout_2->addWidget(switchButton);


        verticalLayout_5->addLayout(verticalLayout_2);


        horizontalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout_6->setStretch(0, 5);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_6);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 20);

        gridLayout->addLayout(verticalLayout_6, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        rollingLabel->setText(QApplication::translate("MainWindow", "\346\273\232\345\212\250\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        currentTestPoint->setText(QApplication::translate("MainWindow", "\346\265\213\347\202\271\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "11", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\351\207\207\351\233\206\345\200\274\357\274\232", Q_NULLPTR));
        currentCollection->setText(QApplication::translate("MainWindow", "11", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\345\267\245\347\250\213\345\200\274\357\274\232", Q_NULLPTR));
        currentEngineer->setText(QApplication::translate("MainWindow", "11", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\345\215\225\344\275\215\357\274\232", Q_NULLPTR));
        currentUint->setText(QApplication::translate("MainWindow", "11", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\345\244\207\346\263\250\357\274\232", Q_NULLPTR));
        startButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        saveButton->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256", Q_NULLPTR));
        settingButton->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        switchButton->setText(QApplication::translate("MainWindow", "\345\210\207\346\215\242\346\265\213\347\202\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
