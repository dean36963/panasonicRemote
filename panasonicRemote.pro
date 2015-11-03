#-------------------------------------------------
#
# Project created by QtCreator 2015-10-25T20:49:00
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = panasonicRemote
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    remotewidget.cpp \
    commandfile.cpp \
    remotebutton.cpp \
    ipsaver.cpp

HEADERS  += mainwindow.h \
    remotewidget.h \
    commandfile.h \
    remotebutton.h \
    ipsaver.h
