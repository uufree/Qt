#-------------------------------------------------
#
# Project created by QtCreator 2017-12-07T23:58:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WindCup
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settingdialog.cpp \
    onecupsettingdialog.cpp

HEADERS  += mainwindow.h \
    global.h \
    settingdialog.h \
    onecupsettingdialog.h

FORMS    += mainwindow.ui \
    settingdialog.ui \
    onecupsettingdialog.ui
