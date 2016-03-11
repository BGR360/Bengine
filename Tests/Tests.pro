QT += core
QT -= gui

CONFIG += c++11

TARGET = Tests
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

VPATH += src

SOURCES += main.cpp

LIBS += -L../Bengine -lbengine

INCLUDEPATH += ../Bengine/src
