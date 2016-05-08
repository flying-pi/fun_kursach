#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T12:06:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fun_kursach
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    util.cpp \
    neuralCore/neuron.cpp \
    neuralCore/sigmodneuron.cpp \
    neuralCore/layer.cpp

HEADERS  += mainwindow.h \
    util.h \
    neuralCore/neuron.h \
    neuralCore/sigmodneuron.h \
    neuralCore/layer.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

