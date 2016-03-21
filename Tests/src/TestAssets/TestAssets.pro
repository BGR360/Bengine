include(../../Tests_common.pri)

QT += core
QT -= gui

CONFIG += c++11

TARGET = TestAssets
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    bassetmanagertest.cpp

HEADERS += \
    bassetmanagertest.h
