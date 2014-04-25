#-------------------------------------------------
#
# Project created by QtCreator 2014-04-24T08:33:34
#
#-------------------------------------------------

QT += core
QT += testlib
QT -= gui


TARGET = 1
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app


SOURCES += main.cpp \
    simple_hash.cpp \
    polynomial_hash.cpp \
    hash_function.cpp \
    list.cpp \
    hash_table.cpp

HEADERS += \
    simple_hash.h \
    polynomial_hash.h \
    hash_table.h \
    list.h \
    hash_function.h \
    list_test.h \
    hash_table_test.h
