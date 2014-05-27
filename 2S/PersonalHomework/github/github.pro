QT       += core gui webkitwidgets xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = github
TEMPLATE = app

CONFIG  += c++11

SOURCES += main.cpp\
        github.cpp

HEADERS  += github.h

FORMS    += github.ui
