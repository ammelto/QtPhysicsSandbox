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
        mainwindow.cpp \
    logic.cpp \
    ball.cpp \
    fieldscene.cpp \
    previewscene.cpp

HEADERS  += mainwindow.h \
    logic.h \
    ball.h \
    fieldscene.h \
    previewscene.h

FORMS    += mainwindow.ui
