#-------------------------------------------------
#
# The Qt project file for the utilities.
# This file must be added to the main Qt project file.
#
#-------------------------------------------------

QT       += core

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    utility/cfunction.cpp

HEADERS += \
    utility/cfunction.hpp
