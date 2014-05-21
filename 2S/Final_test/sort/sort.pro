
QT       += core
QT       += testlib
QT       -= gui

TARGET = sort
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    intComparator.cpp \
    stringComparator.cpp \
    intDecComparator.cpp

HEADERS += \
    comparator.h \
    intComparator.h \
    stringComparator.h \
    intDecComparator.h \
    sortTest.h \
    bubbleSort.h
