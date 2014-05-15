
QT       += core gui
QT       += testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3
TEMPLATE = app


SOURCES += main.cpp\
        calculator.cpp \
    calculatorFunc.cpp

HEADERS  += calculator.h \
    calculatorFunc.h \
    calculatorTest.h

FORMS    += calculator.ui
