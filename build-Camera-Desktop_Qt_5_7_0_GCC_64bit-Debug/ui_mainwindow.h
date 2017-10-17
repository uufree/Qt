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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *ImageView;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *ImageCapture;
    QPushButton *captureButton;
    QPushButton *saveButton;
    QPushButton *quitButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(803, 487);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 20, 471, 441));
        ImageView = new QHBoxLayout(horizontalLayoutWidget);
        ImageView->setSpacing(6);
        ImageView->setContentsMargins(11, 11, 11, 11);
        ImageView->setObjectName(QStringLiteral("ImageView"));
        ImageView->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(510, 20, 269, 441));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ImageCapture = new QLabel(widget);
        ImageCapture->setObjectName(QStringLiteral("ImageCapture"));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(18);
        font.setItalic(true);
        ImageCapture->setFont(font);
        ImageCapture->setTextFormat(Qt::AutoText);
        ImageCapture->setAlignment(Qt::AlignCenter);
        ImageCapture->setWordWrap(false);

        verticalLayout->addWidget(ImageCapture);

        captureButton = new QPushButton(widget);
        captureButton->setObjectName(QStringLiteral("captureButton"));

        verticalLayout->addWidget(captureButton);

        saveButton = new QPushButton(widget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        verticalLayout->addWidget(saveButton);

        quitButton = new QPushButton(widget);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        verticalLayout->addWidget(quitButton);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        ImageCapture->setText(QApplication::translate("MainWindow", "no image to display...", 0));
        captureButton->setText(QApplication::translate("MainWindow", "Capture", 0));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
