#-------------------------------------------------
#
# Project created by QtCreator 2010-11-24T00:24:17
#
#-------------------------------------------------

QT       += core gui
QT += core network

CONFIG += static

TARGET = Author
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    protect.cpp

HEADERS  += mainwindow.h \
    protect.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    rsc.rc

win32:RC_FILE = rsc.rc
