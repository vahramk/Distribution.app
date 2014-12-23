#-------------------------------------------------
#
# The Qt project file of the chart project.
# This file mast be added to the main Qt project file.
#
#-------------------------------------------------

QT       += core
QT	 += gui
QT	 += widgets

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    chart/cboxchart.cpp \
    chart/cchart.cpp \
    chart/cchartgallery.cpp \
    chart/cdataarea.cpp \
    chart/chistogramchart.cpp \
    chart/chistoxrange.cpp \
    chart/cprobabilitychart.cpp \
    chart/cseries.cpp \
    chart/chistoseries.cpp \
    chart/chistoyrange.cpp \
    chart/cprobxrange.cpp \
    chart/cprobyrange.cpp \
    chart/cprobseries.cpp

HEADERS += \
    chart/cboxchart.h \
    chart/cchart.h \
    chart/cchartgallery.h \
    chart/cdataarea.h \
    chart/chistogramchart.h \
    chart/chistoxrange.h \
    chart/cprobabilitychart.h \
    chart/ichart.h \
    chart/idatarange.h \
    chart/cseries.h \
    chart/chistoseries.h \
    chart/chistoyrange.h \
    chart/cprobxrange.h \
    chart/cprobyrange.h \
    chart/cprobseries.h
