#-------------------------------------------------
#
# Project created by QtCreator 2015-01-15T19:30:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PhysicsFun
TEMPLATE = app


SOURCES += main.cpp\
    GUI\mainwindow.cpp \
    logic.cpp \
    Items\ball.cpp \
    GUI\fieldscene.cpp \
    GUI\previewscene.cpp \
    Items\ballreal.cpp

HEADERS  += GUI\mainwindow.h \
    logic.h \
    Items\ball.h \
    GUI\fieldscene.h \
    GUI\previewscene.h \
    Items\ballreal.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resources\resources.qrc
