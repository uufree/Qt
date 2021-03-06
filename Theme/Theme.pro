#-------------------------------------------------
#
# Project created by QtCreator 2018-01-01T15:31:38
#
#-------------------------------------------------

QT       += core gui charts network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Theme
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += /usr/local/qwt-6.1.3/include
LIBS += -L"/usr/local/qwt-6.1.3/lib/" -lqwt

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    circledata.cpp \
    dial.cpp \
    linechart.cpp \
    settingdialog.cpp \
    communication.cpp

HEADERS += \
        mainwindow.h \
    circledata.h \
    dial.h \
    linechart.h \
    global.h \
    settingdialog.h \
    communication.h

FORMS += \
        mainwindow.ui \
    settingdialog.ui

RESOURCES += \
    resources.qrc
