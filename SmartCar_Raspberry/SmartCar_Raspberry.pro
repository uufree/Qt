#-------------------------------------------------
#
# Project created by QtCreator 2017-10-16T20:59:39
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartCar_Raspberry
TEMPLATE = app


SOURCES += main.cpp \
    tcpserver.cpp

HEADERS  += \
    tcpserver.h
