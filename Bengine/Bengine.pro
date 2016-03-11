#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T22:13:28
#
#-------------------------------------------------

QT       += widgets opengl xml

TARGET = Bengine
TEMPLATE = lib

DEFINES += BENGINE_LIBRARY

SOURCES += bengine.cpp

HEADERS += bengine.h\
        bengine_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
