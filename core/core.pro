#-------------------------------------------------
#
# The Qt project file of the Core part of the Distribution project.
# This file must be added to the main Qt project file.
#
#-------------------------------------------------

QT       += core

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    core/cfunction.cpp \
    core/application.cpp \
    core/module.cpp

HEADERS += \
    core/cfunction.h \
    core/application.h \
    core/module.h
