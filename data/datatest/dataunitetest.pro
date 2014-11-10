#-------------------------------------------------
#
# The Qt project file for the unite test of data project.
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = qt_data_unitetest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main_unite_test.cpp \
    ../ccsvdataparser.cpp \
    ../cdatacolumn.cpp \
    ../cdataparser.cpp \
    ../cdatatable.cpp \
    ../datautility.cpp \

HEADERS += \
    ../ccsvdataparser.h \
    ../cdatacolumn.h \
    ../cdataparser.h \
    ../cdatatable.h \
    ../datautility.h \
    ../idatacolumn.h \
    ../idatalayer.h \
    ../idataparsermodule.h \
    ../idatatable.h
