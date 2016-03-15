#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T22:13:28
#
#-------------------------------------------------

QT       += widgets opengl xml

TARGET = Bengine
TEMPLATE = lib

DEFINES += BENGINE_LIBRARY

INCLUDEPATH += src

SOURCES += src/bengine.cpp \
    src/core/bclock.cpp \
    src/core/bgamecomponent.cpp \
    src/core/bgameobject.cpp \
    src/core/bobject.cpp

HEADERS += src/bengine.h\
        src/bengine_global.h \
    src/core/bobject.h \
    src/core/bclock.h \
    src/core/bgamecomponent.h \
    src/core/bgameobject.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    doc/Bengine.qdocconfig \
    doc/cpp-classes.qdoc \
    doc/landing-page.qdoc \
    doc/modules.qdoc \
    src/core/core.qdoc

QMAKE_DOCS = doc/Bengine.qdocconfig
