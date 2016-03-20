QT += core
QT -= gui

TEMPLATE = subdirs

SUBDIRS += \
    src/TestCore

HEADERS += src/tests_global.h

DISTFILES += Tests_common.pri
