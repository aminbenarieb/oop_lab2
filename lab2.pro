QT += core
QT -= gui

CONFIG += c++11

TARGET = lab2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    error.h \
    list.h \
    iterator.h \
    base_list.h \
    node.h \
    iterator_const.h
