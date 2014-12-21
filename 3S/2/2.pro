#-------------------------------------------------
#
# Project created by QtCreator 2014-12-21T18:24:13
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = 2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    computer.cpp \
    network.cpp \
    test.cpp \
    generator.cpp \
    randomgenerator.cpp \
    notrandomgenerator.cpp

HEADERS += \
    computer.h \
    network.h \
    test.h \
    generator.h \
    randomgenerator.h \
    notrandomgenerator.h
