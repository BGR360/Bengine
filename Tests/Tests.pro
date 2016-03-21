QT += core
QT -= gui

TEMPLATE = subdirs

SUBDIRS += \
    src/TestCore \
    src/TestAssets

HEADERS += \
    src/tests_global.h \
    src/btestcollection.h

SOURCES += \
    src/btestcollection.cpp


DISTFILES += Tests_common.pri
