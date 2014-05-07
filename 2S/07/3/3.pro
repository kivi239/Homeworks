QT       += core gui
QT       += testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3
TEMPLATE = app


SOURCES += main.cpp\
        ticTacToe.cpp \
    ticTacToeFunc.cpp

HEADERS  += ticTacToe.h \
    ticTacToeFunc.h \
    ticTacToeTest.h

FORMS    += ticTacToe.ui
