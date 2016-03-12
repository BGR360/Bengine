#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T22:13:28
#
#-------------------------------------------------

QT       += widgets opengl xml

TARGET = Bengine
TEMPLATE = lib

DEFINES += BENGINE_LIBRARY

VPATH += src

SOURCES += bengine.cpp \
    src/core/bobject.cpp \
    src/core/bcomponent.cpp \
    doc/landing-page.qdoc \
    doc/cpp-classes.qdoc

HEADERS += bengine.h\
        bengine_global.h \
    src/core/bobject.h \
    src/core/bcomponent.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    Bengine.qdocconfig \
    doc/Bengine.qdocconfig

QMAKE_DOCS = doc/Bengine.qdocconfig
