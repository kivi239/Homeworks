QT       += core
QT       -= gui
QT       += testlib

TARGET = 3
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app

HEADERS += sharedPointer.h
HEADERS += sharedPointerTest.h

SOURCES += main.cpp

