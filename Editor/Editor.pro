#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T22:15:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Editor
TEMPLATE = app

VPATH += src

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

LIBS += -L../Bengine -lbengine

INCLUDEPATH += ../Bengine/src

