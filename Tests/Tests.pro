QT += core testlib

CONFIG += c++11

TARGET = Tests
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += src/main.cpp \
    src/btest.cpp \
    src/btestcollection.cpp

LIBS += -L../Bengine -lbengine

INCLUDEPATH += src ../Bengine/src

HEADERS += \
    src/btest.h \
    src/btestcollection.h
