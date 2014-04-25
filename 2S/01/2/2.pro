#-------------------------------------------------
#
# Project created by QtCreator 2014-04-25T14:49:41
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = 2
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    stack.cpp \
    arrayStack.cpp \
    pointerStack.cpp

HEADERS += \
    stack.h \
    stackTest.h \
    arrayStack.h \
    pointerStack.h
