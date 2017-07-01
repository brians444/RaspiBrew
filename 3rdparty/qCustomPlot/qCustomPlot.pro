#-------------------------------------------------
#
# Project created by QtCreator 2017-06-24T20:45:45
#
#-------------------------------------------------

QT       += core gui printsupport widgets

linux-g++ {
QMAKE_CXXFLAGS_RELEASE = -g3 -Wall -pg

INSTALL_INCLUDEDIR = /usr/include
INSTALL_LIBDIR = /usr/lib
}

INCLUDEPATH += ..

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qcustomplot
TEMPLATE = lib

CONFIG += release \
staticlib \
warn_on

TEMPLATE = lib

DEST_DIR = ../

SOURCES += \
    qcustomplot.cpp

HEADERS  += \
    qcustomplot.h
