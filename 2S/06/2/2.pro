
QT       += core
QT       -= gui
QT       += testlib

TARGET = 2
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    list.cpp \
    exception.cpp \
    excAddElement.cpp \
    excDeleteElement.cpp \
    listtest.cpp \
    uniqueList.cpp

HEADERS += \
    list.h \
    exception.h \
    excAddElement.h \
    excDeleteElement.h \
    listtest.h \
    uniqueList.h
