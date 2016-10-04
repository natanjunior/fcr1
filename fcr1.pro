#-------------------------------------------------
#
# Project created by QtCreator 2016-09-16T22:11:00
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fcr1
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    canvas.cpp \
    roboPontual.cpp \
    robo.cpp \
    roboAckerman.cpp

HEADERS  += mainwindow.h \
    canvas.h \
    roboPontual.h \
    robo.h \
    roboAckerman.h

FORMS    += mainwindow.ui
