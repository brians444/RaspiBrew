#-------------------------------------------------
#
# Project created by QtCreator 2017-05-07T16:22:39
#
#-------------------------------------------------
QT       += core gui xml svg serialport sql
CONFIG += c++11

#include(3rdparty/qtxlsx/src/xlsx/qtxlsx.pri)
#include(3rdparty/analogwidgets/Flags.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = RaspiBrew
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    helpwindow.cpp \
    mainplot.cpp \
    maincontrols.cpp \
    main_registro.cpp \
    nrftask.cpp \
    database.cpp

HEADERS  += mainwindow.hpp \
            qcustomplot.h \
            helpwindow.hpp \
            nrftask.h \
            database.h \
            definitions.h


FORMS    += mainwindow.ui \
    helpwindow.ui

RC_FILE = myapp.rc

RESOURCES += \
    resources/resources.qrc


INCLUDEPATH += 3rdparty/analogwidgets/analogwidgets/analogwidgets
INCLUDEPATH += 3rdparty/analogwidgets/analogwidgets/code

win32: LIBS += -L"C:\Users\Vegueta\Dropbox\Proyectos\RaspiBrew\3rdparty\lib" -lanalogwidgets -lqcustomplot -lqtxlsx

unix: LIBS += -lrf24 -lanalogwidgets -lqcustomplot -lQt0Xlsx
