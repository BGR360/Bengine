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
    src/core/bobject.cpp \
    src/core/bcomponent.cpp \
    doc/landing-page.qdoc \
    doc/cpp-classes.qdoc \
    src/core/core.qdoc \
    doc/modules.qdoc \
    src/core/bclock.cpp

HEADERS += src/bengine.h\
        src/bengine_global.h \
    src/core/bobject.h \
    src/core/bcomponent.h \
    src/core/bclock.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    Bengine.qdocconfig \
    doc/Bengine.qdocconfig

QMAKE_DOCS = doc/Bengine.qdocconfig
