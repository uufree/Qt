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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_42;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *E0;
    QPushButton *E1;
    QPushButton *E2;
    QPushButton *E3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *E4;
    QPushButton *E5;
    QPushButton *E6;
    QPushButton *E7;
    QHBoxLayout *horizontalLayout;
    QPushButton *E8;
    QPushButton *E9;
    QPushButton *EA;
    QPushButton *EB;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *EC;
    QPushButton *ED;
    QPushButton *EE;
    QPushButton *EF;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *F0;
    QPushButton *F1;
    QPushButton *F2;
    QPushButton *F3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *F4;
    QPushButton *F5;
    QPushButton *F6;
    QPushButton *F7;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *F8;
    QPushButton *F9;
    QPushButton *FA;
    QPushButton *FB;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *FC;
    QPushButton *FD;
    QPushButton *FE;
    QPushButton *FF;
    QHBoxLayout *horizontalLayout_41;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QLineEdit *UA;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_8;
    QLineEdit *UB;
    QHBoxLayout *horizontalLayout_35;
    QLabel *label_14;
    QLineEdit *UC;
    QHBoxLayout *horizontalLayout_43;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_9;
    QLineEdit *IA;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_10;
    QLineEdit *IB;
    QHBoxLayout *horizontalLayout_36;
    QLabel *label_20;
    QLineEdit *IC;
    QHBoxLayout *horizontalLayout_29;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_11;
    QLineEdit *PA;
    QHBoxLayout *horizontalLayout_34;
    QLabel *label_12;
    QLineEdit *PB;
    QHBoxLayout *horizontalLayout_37;
    QLabel *label_21;
    QLineEdit *PC;
    QHBoxLayout *horizontalLayout_23;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_18;
    QLineEdit *currentDate;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_19;
    QLineEdit *currentTime;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_13;
    QLineEdit *currentVolume;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_17;
    QLineEdit *currentNegPressure;
    QHBoxLayout *horizontalLayout_26;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_15;
    QLineEdit *currentAverageSpeed;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_16;
    QLineEdit *currentAtmPressure;
    QVBoxLayout *verticalLayout_4;
    QWidget *lineChartWidget;
    QHBoxLayout *horizontalLayout_40;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_28;
    QHBoxLayout *horizontalLayout_38;
    QLabel *label_22;
    QLineEdit *settingElectric;
    QHBoxLayout *horizontalLayout_39;
    QLabel *label_23;
    QLineEdit *settingVoltage;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_7;
    QComboBox *settingPort;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_3;
    QLineEdit *settingSpeed;
    QHBoxLayout *horizontalLayout_25;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label;
    QComboBox *settingBaudBox;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_4;
    QLineEdit *settingTestArea;
    QHBoxLayout *horizontalLayout_27;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_2;
    QComboBox *settingPoll;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_6;
    QComboBox *settingCups;
    QVBoxLayout *verticalLayout_2;
    QPushButton *startBtton;
    QPushButton *flushButton;
    QPushButton *saveDataButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(839, 552);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../\346\241\214\351\235\242/WineCup.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setSpacing(6);
        horizontalLayout_42->setObjectName(QStringLiteral("horizontalLayout_42"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        E0 = new QPushButton(centralWidget);
        E0->setObjectName(QStringLiteral("E0"));

        horizontalLayout_6->addWidget(E0);

        E1 = new QPushButton(centralWidget);
        E1->setObjectName(QStringLiteral("E1"));

        horizontalLayout_6->addWidget(E1);

        E2 = new QPushButton(centralWidget);
        E2->setObjectName(QStringLiteral("E2"));

        horizontalLayout_6->addWidget(E2);

        E3 = new QPushButton(centralWidget);
        E3->setObjectName(QStringLiteral("E3"));

        horizontalLayout_6->addWidget(E3);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        E4 = new QPushButton(centralWidget);
        E4->setObjectName(QStringLiteral("E4"));

        horizontalLayout_5->addWidget(E4);

        E5 = new QPushButton(centralWidget);
        E5->setObjectName(QStringLiteral("E5"));

        horizontalLayout_5->addWidget(E5);

        E6 = new QPushButton(centralWidget);
        E6->setObjectName(QStringLiteral("E6"));

        horizontalLayout_5->addWidget(E6);

        E7 = new QPushButton(centralWidget);
        E7->setObjectName(QStringLiteral("E7"));

        horizontalLayout_5->addWidget(E7);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        E8 = new QPushButton(centralWidget);
        E8->setObjectName(QStringLiteral("E8"));

        horizontalLayout->addWidget(E8);

        E9 = new QPushButton(centralWidget);
        E9->setObjectName(QStringLiteral("E9"));
        E9->setEnabled(false);

        horizontalLayout->addWidget(E9);

        EA = new QPushButton(centralWidget);
        EA->setObjectName(QStringLiteral("EA"));
        EA->setEnabled(false);

        horizontalLayout->addWidget(EA);

        EB = new QPushButton(centralWidget);
        EB->setObjectName(QStringLiteral("EB"));
        EB->setEnabled(false);

        horizontalLayout->addWidget(EB);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        EC = new QPushButton(centralWidget);
        EC->setObjectName(QStringLiteral("EC"));
        EC->setEnabled(false);

        horizontalLayout_4->addWidget(EC);

        ED = new QPushButton(centralWidget);
        ED->setObjectName(QStringLiteral("ED"));
        ED->setEnabled(false);

        horizontalLayout_4->addWidget(ED);

        EE = new QPushButton(centralWidget);
        EE->setObjectName(QStringLiteral("EE"));
        EE->setEnabled(false);

        horizontalLayout_4->addWidget(EE);

        EF = new QPushButton(centralWidget);
        EF->setObjectName(QStringLiteral("EF"));
        EF->setEnabled(false);

        horizontalLayout_4->addWidget(EF);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        F0 = new QPushButton(centralWidget);
        F0->setObjectName(QStringLiteral("F0"));
        F0->setEnabled(false);

        horizontalLayout_2->addWidget(F0);

        F1 = new QPushButton(centralWidget);
        F1->setObjectName(QStringLiteral("F1"));
        F1->setEnabled(false);

        horizontalLayout_2->addWidget(F1);

        F2 = new QPushButton(centralWidget);
        F2->setObjectName(QStringLiteral("F2"));
        F2->setEnabled(false);

        horizontalLayout_2->addWidget(F2);

        F3 = new QPushButton(centralWidget);
        F3->setObjectName(QStringLiteral("F3"));
        F3->setEnabled(false);

        horizontalLayout_2->addWidget(F3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        F4 = new QPushButton(centralWidget);
        F4->setObjectName(QStringLiteral("F4"));
        F4->setEnabled(false);

        horizontalLayout_3->addWidget(F4);

        F5 = new QPushButton(centralWidget);
        F5->setObjectName(QStringLiteral("F5"));
        F5->setEnabled(false);

        horizontalLayout_3->addWidget(F5);

        F6 = new QPushButton(centralWidget);
        F6->setObjectName(QStringLiteral("F6"));
        F6->setEnabled(false);

        horizontalLayout_3->addWidget(F6);

        F7 = new QPushButton(centralWidget);
        F7->setObjectName(QStringLiteral("F7"));
        F7->setEnabled(false);

        horizontalLayout_3->addWidget(F7);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        F8 = new QPushButton(centralWidget);
        F8->setObjectName(QStringLiteral("F8"));
        F8->setEnabled(false);

        horizontalLayout_7->addWidget(F8);

        F9 = new QPushButton(centralWidget);
        F9->setObjectName(QStringLiteral("F9"));
        F9->setEnabled(false);

        horizontalLayout_7->addWidget(F9);

        FA = new QPushButton(centralWidget);
        FA->setObjectName(QStringLiteral("FA"));
        FA->setEnabled(false);

        horizontalLayout_7->addWidget(FA);

        FB = new QPushButton(centralWidget);
        FB->setObjectName(QStringLiteral("FB"));
        FB->setEnabled(false);

        horizontalLayout_7->addWidget(FB);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        FC = new QPushButton(centralWidget);
        FC->setObjectName(QStringLiteral("FC"));
        FC->setEnabled(false);

        horizontalLayout_8->addWidget(FC);

        FD = new QPushButton(centralWidget);
        FD->setObjectName(QStringLiteral("FD"));
        FD->setEnabled(false);

        horizontalLayout_8->addWidget(FD);

        FE = new QPushButton(centralWidget);
        FE->setObjectName(QStringLiteral("FE"));
        FE->setEnabled(false);

        horizontalLayout_8->addWidget(FE);

        FF = new QPushButton(centralWidget);
        FF->setObjectName(QStringLiteral("FF"));
        FF->setEnabled(false);

        horizontalLayout_8->addWidget(FF);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setSpacing(6);
        horizontalLayout_41->setObjectName(QStringLiteral("horizontalLayout_41"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_9->addWidget(label_5);

        UA = new QLineEdit(centralWidget);
        UA->setObjectName(QStringLiteral("UA"));

        horizontalLayout_9->addWidget(UA);


        horizontalLayout_41->addLayout(horizontalLayout_9);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_30->addWidget(label_8);

        UB = new QLineEdit(centralWidget);
        UB->setObjectName(QStringLiteral("UB"));

        horizontalLayout_30->addWidget(UB);


        horizontalLayout_41->addLayout(horizontalLayout_30);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_35->addWidget(label_14);

        UC = new QLineEdit(centralWidget);
        UC->setObjectName(QStringLiteral("UC"));

        horizontalLayout_35->addWidget(UC);


        horizontalLayout_41->addLayout(horizontalLayout_35);


        verticalLayout->addLayout(horizontalLayout_41);

        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setSpacing(6);
        horizontalLayout_43->setObjectName(QStringLiteral("horizontalLayout_43"));
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_31->addWidget(label_9);

        IA = new QLineEdit(centralWidget);
        IA->setObjectName(QStringLiteral("IA"));

        horizontalLayout_31->addWidget(IA);


        horizontalLayout_43->addLayout(horizontalLayout_31);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_32->addWidget(label_10);

        IB = new QLineEdit(centralWidget);
        IB->setObjectName(QStringLiteral("IB"));

        horizontalLayout_32->addWidget(IB);


        horizontalLayout_43->addLayout(horizontalLayout_32);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setObjectName(QStringLiteral("horizontalLayout_36"));
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_36->addWidget(label_20);

        IC = new QLineEdit(centralWidget);
        IC->setObjectName(QStringLiteral("IC"));

        horizontalLayout_36->addWidget(IC);


        horizontalLayout_43->addLayout(horizontalLayout_36);


        verticalLayout->addLayout(horizontalLayout_43);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_33->addWidget(label_11);

        PA = new QLineEdit(centralWidget);
        PA->setObjectName(QStringLiteral("PA"));

        horizontalLayout_33->addWidget(PA);


        horizontalLayout_29->addLayout(horizontalLayout_33);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_34->addWidget(label_12);

        PB = new QLineEdit(centralWidget);
        PB->setObjectName(QStringLiteral("PB"));

        horizontalLayout_34->addWidget(PB);


        horizontalLayout_29->addLayout(horizontalLayout_34);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setSpacing(6);
        horizontalLayout_37->setObjectName(QStringLiteral("horizontalLayout_37"));
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_37->addWidget(label_21);

        PC = new QLineEdit(centralWidget);
        PC->setObjectName(QStringLiteral("PC"));

        horizontalLayout_37->addWidget(PC);


        horizontalLayout_29->addLayout(horizontalLayout_37);


        verticalLayout->addLayout(horizontalLayout_29);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_21->addWidget(label_18);

        currentDate = new QLineEdit(centralWidget);
        currentDate->setObjectName(QStringLiteral("currentDate"));

        horizontalLayout_21->addWidget(currentDate);

        horizontalLayout_21->setStretch(1, 1);

        horizontalLayout_23->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_22->addWidget(label_19);

        currentTime = new QLineEdit(centralWidget);
        currentTime->setObjectName(QStringLiteral("currentTime"));

        horizontalLayout_22->addWidget(currentTime);


        horizontalLayout_23->addLayout(horizontalLayout_22);

        horizontalLayout_23->setStretch(0, 5);
        horizontalLayout_23->setStretch(1, 4);

        verticalLayout->addLayout(horizontalLayout_23);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_18->addWidget(label_13);

        currentVolume = new QLineEdit(centralWidget);
        currentVolume->setObjectName(QStringLiteral("currentVolume"));

        horizontalLayout_18->addWidget(currentVolume);


        horizontalLayout_14->addLayout(horizontalLayout_18);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_24->addWidget(label_17);

        currentNegPressure = new QLineEdit(centralWidget);
        currentNegPressure->setObjectName(QStringLiteral("currentNegPressure"));

        horizontalLayout_24->addWidget(currentNegPressure);


        horizontalLayout_14->addLayout(horizontalLayout_24);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_19->addWidget(label_15);

        currentAverageSpeed = new QLineEdit(centralWidget);
        currentAverageSpeed->setObjectName(QStringLiteral("currentAverageSpeed"));

        horizontalLayout_19->addWidget(currentAverageSpeed);


        horizontalLayout_26->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_20->addWidget(label_16);

        currentAtmPressure = new QLineEdit(centralWidget);
        currentAtmPressure->setObjectName(QStringLiteral("currentAtmPressure"));

        horizontalLayout_20->addWidget(currentAtmPressure);


        horizontalLayout_26->addLayout(horizontalLayout_20);


        verticalLayout->addLayout(horizontalLayout_26);


        horizontalLayout_42->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lineChartWidget = new QWidget(centralWidget);
        lineChartWidget->setObjectName(QStringLiteral("lineChartWidget"));
        lineChartWidget->setMaximumSize(QSize(1200, 900));

        verticalLayout_4->addWidget(lineChartWidget);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setSpacing(6);
        horizontalLayout_40->setObjectName(QStringLiteral("horizontalLayout_40"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setSpacing(6);
        horizontalLayout_38->setObjectName(QStringLiteral("horizontalLayout_38"));
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_38->addWidget(label_22);

        settingElectric = new QLineEdit(centralWidget);
        settingElectric->setObjectName(QStringLiteral("settingElectric"));

        horizontalLayout_38->addWidget(settingElectric);


        horizontalLayout_28->addLayout(horizontalLayout_38);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setSpacing(6);
        horizontalLayout_39->setObjectName(QStringLiteral("horizontalLayout_39"));
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_39->addWidget(label_23);

        settingVoltage = new QLineEdit(centralWidget);
        settingVoltage->setObjectName(QStringLiteral("settingVoltage"));

        horizontalLayout_39->addWidget(settingVoltage);


        horizontalLayout_28->addLayout(horizontalLayout_39);


        verticalLayout_3->addLayout(horizontalLayout_28);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_16->addWidget(label_7);

        settingPort = new QComboBox(centralWidget);
        settingPort->setObjectName(QStringLiteral("settingPort"));

        horizontalLayout_16->addWidget(settingPort);

        horizontalLayout_16->setStretch(1, 1);

        horizontalLayout_13->addLayout(horizontalLayout_16);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_10->addWidget(label_3);

        settingSpeed = new QLineEdit(centralWidget);
        settingSpeed->setObjectName(QStringLiteral("settingSpeed"));

        horizontalLayout_10->addWidget(settingSpeed);


        horizontalLayout_13->addLayout(horizontalLayout_10);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_15->addWidget(label);

        settingBaudBox = new QComboBox(centralWidget);
        settingBaudBox->setObjectName(QStringLiteral("settingBaudBox"));

        horizontalLayout_15->addWidget(settingBaudBox);

        horizontalLayout_15->setStretch(1, 1);

        horizontalLayout_25->addLayout(horizontalLayout_15);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_11->addWidget(label_4);

        settingTestArea = new QLineEdit(centralWidget);
        settingTestArea->setObjectName(QStringLiteral("settingTestArea"));

        horizontalLayout_11->addWidget(settingTestArea);

        horizontalLayout_11->setStretch(1, 15);

        horizontalLayout_25->addLayout(horizontalLayout_11);


        verticalLayout_3->addLayout(horizontalLayout_25);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_17->addWidget(label_2);

        settingPoll = new QComboBox(centralWidget);
        settingPoll->setObjectName(QStringLiteral("settingPoll"));

        horizontalLayout_17->addWidget(settingPoll);

        horizontalLayout_17->setStretch(1, 1);

        horizontalLayout_27->addLayout(horizontalLayout_17);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_12->addWidget(label_6);

        settingCups = new QComboBox(centralWidget);
        settingCups->setObjectName(QStringLiteral("settingCups"));

        horizontalLayout_12->addWidget(settingCups);

        horizontalLayout_12->setStretch(1, 1);

        horizontalLayout_27->addLayout(horizontalLayout_12);


        verticalLayout_3->addLayout(horizontalLayout_27);


        horizontalLayout_40->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        startBtton = new QPushButton(centralWidget);
        startBtton->setObjectName(QStringLiteral("startBtton"));

        verticalLayout_2->addWidget(startBtton);

        flushButton = new QPushButton(centralWidget);
        flushButton->setObjectName(QStringLiteral("flushButton"));

        verticalLayout_2->addWidget(flushButton);

        saveDataButton = new QPushButton(centralWidget);
        saveDataButton->setObjectName(QStringLiteral("saveDataButton"));

        verticalLayout_2->addWidget(saveDataButton);


        horizontalLayout_40->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_40);

        verticalLayout_4->setStretch(0, 20);
        verticalLayout_4->setStretch(1, 1);

        horizontalLayout_42->addLayout(verticalLayout_4);


        gridLayout->addLayout(horizontalLayout_42, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        E0->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\231\272\350\203\275\351\243\216\351\200\237\346\265\213\351\207\217\347\263\273\347\273\237", Q_NULLPTR));
        E0->setText(QApplication::translate("MainWindow", "\350\241\2501\357\274\232", Q_NULLPTR));
        E1->setText(QApplication::translate("MainWindow", "\350\241\2502\357\274\232", Q_NULLPTR));
        E2->setText(QApplication::translate("MainWindow", "\350\241\2503\357\274\232", Q_NULLPTR));
        E3->setText(QApplication::translate("MainWindow", "\350\241\2504\357\274\232", Q_NULLPTR));
        E4->setText(QApplication::translate("MainWindow", "\350\241\2505\357\274\232", Q_NULLPTR));
        E5->setText(QApplication::translate("MainWindow", "\350\241\2506\357\274\232", Q_NULLPTR));
        E6->setText(QApplication::translate("MainWindow", "\350\241\2507\357\274\232", Q_NULLPTR));
        E7->setText(QApplication::translate("MainWindow", "\350\241\2508\357\274\232", Q_NULLPTR));
        E8->setText(QApplication::translate("MainWindow", "\350\241\2509\357\274\232", Q_NULLPTR));
        E9->setText(QApplication::translate("MainWindow", "\350\241\25010\357\274\232", Q_NULLPTR));
        EA->setText(QApplication::translate("MainWindow", "\350\241\25011\357\274\232", Q_NULLPTR));
        EB->setText(QApplication::translate("MainWindow", "\350\241\25012\357\274\232", Q_NULLPTR));
        EC->setText(QApplication::translate("MainWindow", "\350\241\25013\357\274\232", Q_NULLPTR));
        ED->setText(QApplication::translate("MainWindow", "\350\241\25014\357\274\232", Q_NULLPTR));
        EE->setText(QApplication::translate("MainWindow", "\350\241\25015\357\274\232", Q_NULLPTR));
        EF->setText(QApplication::translate("MainWindow", "\350\241\25016\357\274\232", Q_NULLPTR));
        F0->setText(QApplication::translate("MainWindow", "\350\241\25017\357\274\232", Q_NULLPTR));
        F1->setText(QApplication::translate("MainWindow", "\350\241\25018\357\274\232", Q_NULLPTR));
        F2->setText(QApplication::translate("MainWindow", "\350\241\25019\357\274\232", Q_NULLPTR));
        F3->setText(QApplication::translate("MainWindow", "\350\241\25020\357\274\232", Q_NULLPTR));
        F4->setText(QApplication::translate("MainWindow", "\350\241\25021\357\274\232", Q_NULLPTR));
        F5->setText(QApplication::translate("MainWindow", "\350\241\25022\357\274\232", Q_NULLPTR));
        F6->setText(QApplication::translate("MainWindow", "\350\241\25023\357\274\232", Q_NULLPTR));
        F7->setText(QApplication::translate("MainWindow", "\350\241\25024\357\274\232", Q_NULLPTR));
        F8->setText(QApplication::translate("MainWindow", "\350\241\25025\357\274\232", Q_NULLPTR));
        F9->setText(QApplication::translate("MainWindow", "\350\241\25026\357\274\232", Q_NULLPTR));
        FA->setText(QApplication::translate("MainWindow", "\350\241\25027\357\274\232", Q_NULLPTR));
        FB->setText(QApplication::translate("MainWindow", "\350\241\25028\357\274\232", Q_NULLPTR));
        FC->setText(QApplication::translate("MainWindow", "\350\241\25029\357\274\232", Q_NULLPTR));
        FD->setText(QApplication::translate("MainWindow", "\350\241\25030\357\274\232", Q_NULLPTR));
        FE->setText(QApplication::translate("MainWindow", "\350\241\25031\357\274\232", Q_NULLPTR));
        FF->setText(QApplication::translate("MainWindow", "\350\241\25032\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Ua:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Ub:", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Uc:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Ia:", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Ib:", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Ic:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "P:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Q:", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "cos\317\206:", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", " \345\275\223\345\211\215\346\227\245\346\234\237:", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\351\243\216\351\207\217:", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "\350\264\237\345\216\213:", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "\345\271\263\345\235\207\351\243\216\351\200\237:", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "\345\244\247\346\260\224\345\216\213:", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213\345\217\230\346\257\224:", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "\347\224\265\346\265\201\345\217\230\346\257\224:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\351\243\216\346\235\257\351\200\237\345\272\246:", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207:", Q_NULLPTR));
        settingBaudBox->clear();
        settingBaudBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "9600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4800", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "38400", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("MainWindow", "\346\265\213\346\226\255\351\235\242\351\235\242\347\247\257:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\350\275\256\350\257\242\351\227\264\351\232\224: ", Q_NULLPTR));
        settingPoll->clear();
        settingPoll->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "10", Q_NULLPTR)
         << QApplication::translate("MainWindow", "20", Q_NULLPTR)
         << QApplication::translate("MainWindow", "30", Q_NULLPTR)
         << QApplication::translate("MainWindow", "40", Q_NULLPTR)
         << QApplication::translate("MainWindow", "50", Q_NULLPTR)
         << QApplication::translate("MainWindow", "60", Q_NULLPTR)
         << QApplication::translate("MainWindow", "70", Q_NULLPTR)
         << QApplication::translate("MainWindow", "80", Q_NULLPTR)
         << QApplication::translate("MainWindow", "90", Q_NULLPTR)
         << QApplication::translate("MainWindow", "100", Q_NULLPTR)
         << QApplication::translate("MainWindow", "150", Q_NULLPTR)
         << QApplication::translate("MainWindow", "200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "300", Q_NULLPTR)
         << QApplication::translate("MainWindow", "350", Q_NULLPTR)
         << QApplication::translate("MainWindow", "400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "450", Q_NULLPTR)
         << QApplication::translate("MainWindow", "500", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4000", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("MainWindow", "\351\243\216\346\235\257\346\225\260:", Q_NULLPTR));
        settingCups->clear();
        settingCups->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "9", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8", Q_NULLPTR)
         << QApplication::translate("MainWindow", "10", Q_NULLPTR)
         << QApplication::translate("MainWindow", "11", Q_NULLPTR)
         << QApplication::translate("MainWindow", "12", Q_NULLPTR)
         << QApplication::translate("MainWindow", "13", Q_NULLPTR)
         << QApplication::translate("MainWindow", "14", Q_NULLPTR)
         << QApplication::translate("MainWindow", "15", Q_NULLPTR)
         << QApplication::translate("MainWindow", "16", Q_NULLPTR)
         << QApplication::translate("MainWindow", "17", Q_NULLPTR)
         << QApplication::translate("MainWindow", "18", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19", Q_NULLPTR)
         << QApplication::translate("MainWindow", "20", Q_NULLPTR)
         << QApplication::translate("MainWindow", "21", Q_NULLPTR)
         << QApplication::translate("MainWindow", "22", Q_NULLPTR)
         << QApplication::translate("MainWindow", "23", Q_NULLPTR)
         << QApplication::translate("MainWindow", "24", Q_NULLPTR)
         << QApplication::translate("MainWindow", "25", Q_NULLPTR)
         << QApplication::translate("MainWindow", "26", Q_NULLPTR)
         << QApplication::translate("MainWindow", "27", Q_NULLPTR)
         << QApplication::translate("MainWindow", "28", Q_NULLPTR)
         << QApplication::translate("MainWindow", "29", Q_NULLPTR)
         << QApplication::translate("MainWindow", "30", Q_NULLPTR)
         << QApplication::translate("MainWindow", "31", Q_NULLPTR)
         << QApplication::translate("MainWindow", "32", Q_NULLPTR)
        );
        startBtton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        flushButton->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", Q_NULLPTR));
        saveDataButton->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
