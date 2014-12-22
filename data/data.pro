#-------------------------------------------------
#
# The Qt project file of the Data project.
# This file must be added to the main Qt project file.
#
#-------------------------------------------------

QT       += core

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    data/ccsvdataparser.cpp \
    data/cdatacolumn.cpp \
    data/cdataparser.cpp \
    data/cdatatable.cpp \
    data/datautility.cpp \

HEADERS += \
    data/ccsvdataparser.h \
    data/cdatacolumn.h \
    data/cdataparser.h \
    data/cdatatable.h \
    data/datautility.h \
    data/idatacolumn.h \
    data/idatalayer.h \
    data/idataparsermodule.h \
    data/idatatable.h
