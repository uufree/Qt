/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *recvEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextEdit *sendEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *clearButton;
    QPushButton *sendButton;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *portBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *baudBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *dataBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *checkBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QComboBox *stopBox;
    QSpacerItem *verticalSpacer;
    QPushButton *openButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(636, 496);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 30, 591, 441));
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        recvEdit = new QTextEdit(widget);
        recvEdit->setObjectName(QStringLiteral("recvEdit"));

        verticalLayout->addWidget(recvEdit);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        sendEdit = new QTextEdit(widget);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));

        verticalLayout_2->addWidget(sendEdit);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        clearButton = new QPushButton(widget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout->addWidget(clearButton);

        sendButton = new QPushButton(widget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout->addWidget(sendButton);


        verticalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_7->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, 25, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        portBox = new QComboBox(widget);
        portBox->setObjectName(QStringLiteral("portBox"));

        horizontalLayout_2->addWidget(portBox);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        baudBox = new QComboBox(widget);
        baudBox->setObjectName(QStringLiteral("baudBox"));

        horizontalLayout_3->addWidget(baudBox);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        dataBox = new QComboBox(widget);
        dataBox->setObjectName(QStringLiteral("dataBox"));

        horizontalLayout_4->addWidget(dataBox);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        checkBox = new QComboBox(widget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_5->addWidget(checkBox);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        stopBox = new QComboBox(widget);
        stopBox->setObjectName(QStringLiteral("stopBox"));

        horizontalLayout_6->addWidget(stopBox);


        verticalLayout_5->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        openButton = new QPushButton(widget);
        openButton->setObjectName(QStringLiteral("openButton"));

        verticalLayout_5->addWidget(openButton);


        horizontalLayout_7->addLayout(verticalLayout_5);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\347\252\227\345\217\243", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\347\252\227\345\217\243", 0));
        clearButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266", 0));
        sendButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", 0));
        label_3->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267:", 0));
        portBox->clear();
        portBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "01", 0)
         << QApplication::translate("MainWindow", "02", 0)
         << QApplication::translate("MainWindow", "03", 0)
         << QApplication::translate("MainWindow", "04", 0)
         << QApplication::translate("MainWindow", "05", 0)
         << QApplication::translate("MainWindow", "05", 0)
         << QApplication::translate("MainWindow", "07", 0)
         << QApplication::translate("MainWindow", "08", 0)
         << QApplication::translate("MainWindow", "09", 0)
         << QApplication::translate("MainWindow", "10", 0)
         << QApplication::translate("MainWindow", "11", 0)
         << QApplication::translate("MainWindow", "12", 0)
         << QString()
         << QString()
         << QString()
         << QString()
        );
        label_4->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207:", 0));
        baudBox->clear();
        baudBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "300", 0)
         << QApplication::translate("MainWindow", "600", 0)
         << QApplication::translate("MainWindow", "1200", 0)
         << QApplication::translate("MainWindow", "2400", 0)
         << QApplication::translate("MainWindow", "4800", 0)
         << QApplication::translate("MainWindow", "9600", 0)
         << QApplication::translate("MainWindow", "19200", 0)
         << QApplication::translate("MainWindow", "38400", 0)
         << QApplication::translate("MainWindow", "43000", 0)
         << QApplication::translate("MainWindow", "56000", 0)
         << QApplication::translate("MainWindow", "57600", 0)
         << QApplication::translate("MainWindow", "115200", 0)
        );
        label_5->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215:", 0));
        dataBox->clear();
        dataBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "5", 0)
         << QApplication::translate("MainWindow", "6", 0)
         << QApplication::translate("MainWindow", "7", 0)
         << QApplication::translate("MainWindow", "8", 0)
        );
        label_6->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215:", 0));
        checkBox->clear();
        checkBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", 0)
        );
        label_7->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215:", 0));
        stopBox->clear();
        stopBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "1.5", 0)
         << QApplication::translate("MainWindow", "2", 0)
        );
        openButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
