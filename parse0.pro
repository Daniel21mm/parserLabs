#-------------------------------------------------
#
# Project created by QtCreator 2017-05-22T10:16:59
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = parse0
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Core/tokenizer.cpp \
    Core/interpreter.cpp \
    Core/calculate.cpp \
    Core/_parser.cpp \
    Core/var.cpp

HEADERS  += mainwindow.h \
    Core/parser.h
