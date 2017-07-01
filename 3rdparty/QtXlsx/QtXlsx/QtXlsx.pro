#-------------------------------------------------
#
# Project created by QtCreator 2017-06-25T01:46:36
#
#-------------------------------------------------

load(qt_parts)

QT       += core gui gui-private

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += release \
warn_on


TARGET = QtXlsx
TEMPLATE = lib

INCLUDEPATH += inc

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

SOURCES += \
    src/xlsxabstractooxmlfile.cpp \
    src/xlsxabstractsheet.cpp \
    src/xlsxcell.cpp \
    src/xlsxcellformula.cpp \
    src/xlsxcellrange.cpp \
    src/xlsxcellreference.cpp \
    src/xlsxchart.cpp \
    src/xlsxchartsheet.cpp \
    src/xlsxcolor.cpp \
    src/xlsxconditionalformatting.cpp \
    src/xlsxcontenttypes.cpp \
    src/xlsxdatavalidation.cpp \
    src/xlsxdocpropsapp.cpp \
    src/xlsxdocpropscore.cpp \
    src/xlsxdocument.cpp \
    src/xlsxdrawing.cpp \
    src/xlsxdrawinganchor.cpp \
    src/xlsxformat.cpp \
    src/xlsxmediafile.cpp \
    src/xlsxnumformatparser.cpp \
    src/xlsxrelationships.cpp \
    src/xlsxrichstring.cpp \
    src/xlsxsharedstrings.cpp \
    src/xlsxsimpleooxmlfile.cpp \
    src/xlsxstyles.cpp \
    src/xlsxtheme.cpp \
    src/xlsxutility.cpp \
    src/xlsxworkbook.cpp \
    src/xlsxworksheet.cpp \
    src/xlsxzipreader.cpp \
    src/xlsxzipwriter.cpp

HEADERS  += \
    inc/xlsxabstractooxmlfile.h \
    inc/xlsxabstractooxmlfile_p.h \
    inc/xlsxabstractsheet.h \
    inc/xlsxabstractsheet_p.h \
    inc/xlsxcell.h \
    inc/xlsxcell_p.h \
    inc/xlsxcellformula.h \
    inc/xlsxcellformula_p.h \
    inc/xlsxcellrange.h \
    inc/xlsxcellreference.h \
    inc/xlsxchart.h \
    inc/xlsxchart_p.h \
    inc/xlsxchartsheet.h \
    inc/xlsxchartsheet_p.h \
    inc/xlsxcolor_p.h \
    inc/xlsxconditionalformatting.h \
    inc/xlsxconditionalformatting_p.h \
    inc/xlsxcontenttypes_p.h \
    inc/xlsxdatavalidation.h \
    inc/xlsxdatavalidation_p.h \
    inc/xlsxdocpropsapp_p.h \
    inc/xlsxdocpropscore_p.h \
    inc/xlsxdocument.h \
    inc/xlsxdocument_p.h \
    inc/xlsxdrawing_p.h \
    inc/xlsxdrawinganchor_p.h \
    inc/xlsxformat.h \
    inc/xlsxformat_p.h \
    inc/xlsxglobal.h \
    inc/xlsxmediafile_p.h \
    inc/xlsxnumformatparser_p.h \
    inc/xlsxrelationships_p.h \
    inc/xlsxrichstring.h \
    inc/xlsxrichstring_p.h \
    inc/xlsxsharedstrings_p.h \
    inc/xlsxsimpleooxmlfile_p.h \
    inc/xlsxstyles_p.h \
    inc/xlsxtheme_p.h \
    inc/xlsxutility_p.h \
    inc/xlsxworkbook.h \
    inc/xlsxworkbook_p.h \
    inc/xlsxworksheet.h \
    inc/xlsxworksheet_p.h \
    inc/xlsxzipreader_p.h \
    inc/xlsxzipwriter_p.h
