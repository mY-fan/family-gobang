#-------------------------------------------------
#
# Project created by QtCreator 2017-03-16T18:58:56
#
#-------------------------------------------------

QT       += core ui sql network

QT       -= gui

TARGET = Gobang_server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    database.cpp \
    house.cpp

HEADERS += \
    database.h \
    house.h
