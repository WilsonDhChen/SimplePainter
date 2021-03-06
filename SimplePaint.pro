#-------------------------------------------------
#
# Project created by QtCreator 2015-09-28T20:59:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

TARGET = SimplePaint
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    colorpickerinternal.cpp \
    selectors.cpp \
    canvas.cpp \
    clipboard.cpp \
    imagehandler.cpp \
    textdialog.cpp \
    coordinatehandler.cpp \
    toolbucket.cpp \
    undohandler.cpp \
    toolmodes.cpp

HEADERS  += mainwindow.h \
    cpconst.h \
    spconst.h \
    colorpickerinternal.h \
    colorpicker.h \
    selectors.h \
    sconst.h \
    canvas.h \
    clipboard.h \
    imagehandler.h \
    ihconst.h \
    textdialog.h \
    coordinatehandler.h \
    toolbucket.h \
    undohandler.h \
    toolmodes.h

FORMS    += mainwindow.ui \
    textdialog.ui \
    toolbucket.ui

RESOURCES += \
    icons.qrc

OTHER_FILES += \
    ToDo.txt \
    License.txt
