#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T22:13:28
#
#-------------------------------------------------

QT       += widgets opengl xml

CONFIG += c++11

TARGET = Bengine
TEMPLATE = lib

DEFINES += BENGINE_LIBRARY

INCLUDEPATH += src

SOURCES += $$files(src/*.cpp, true)

HEADERS += $$files(src/*.h, true)

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    $$files(doc/*.qdocconfig, true) \
    $$files(doc/*.qdoc, true) \
    $$files(examples/*.h, true) \
    $$files(examples/*.cpp, true)

QMAKE_DOCS = doc/Bengine.qdocconfig
