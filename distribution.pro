#-------------------------------------------------
#
# The Qt project file of the Distribution.app project.
# This file must include all component Qt project files.
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = Distribution.app
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

#Component Qt project files.
include(data/data.pro)
include(chart/chart.pro)
include(core/core.pro)


SOURCES += main.cpp
