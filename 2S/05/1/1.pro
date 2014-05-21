#-------------------------------------------------
#
# Project created by QtCreator 2014-05-05T16:18:26
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT       += testlib

TARGET = 1
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    exprTree.cpp \
    treeNode.cpp \
    sumNode.cpp \
    subNode.cpp \
    mulNode.cpp \
    divNode.cpp \
    leafNode.cpp

HEADERS += \
    exprTree.h \
    exprTreeTest.h \
    treeNode.h \
    sumNode.h \
    subNode.h \
    mulNode.h \
    leafNode.h \
    divNode.h
