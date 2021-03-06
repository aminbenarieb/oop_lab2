QT += core
QT -= gui

CONFIG += c++11

TARGET = lab2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    list.h \
    iterator.h \
    base_list.h \
    node.h \
    iterator_const.h \
    error_iterator.h \
    error_list.h \
    _list.h \
    _iterator.h \
    _iterator_const.h \
    base_error.h
