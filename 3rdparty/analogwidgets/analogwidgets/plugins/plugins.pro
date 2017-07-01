# Plik utworzony przez mened?era projektów kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?ównego katalogu projektu: ./analogwidgets/plugins
# Cel to biblioteka analogwidgets_plugin


HEADERS += analogwidgets_plugin.h \
           thermometer_plugin.h


SOURCES += analogwidgets_plugin.cpp \
           thermometer_plugin.cpp


unix:{             
POST_TARGETDEPS += ../libanalogwidgets.a 
LIBS += ../libanalogwidgets.a  
}

win32-g++:{             
POST_TARGETDEPS += ../libanalogwidgets.a 
LIBS += -L"C:\Users\Vegueta\Dropbox\Proyectos\RaspiBrewControl\RaspiBrew\3rdparty\lib" -lanalogwidgets
}


win32-msvc*:{
 POST_TARGETDEPS += ../analogwidgets.lib
 LIBS += ../analogwidgets.lib
}

wince*:{
 POST_TARGETDEPS += ../analogwidgets.lib
 LIBS += ../analogwidgets.lib
}

QT += xml svg script designer

INCLUDEPATH += ../analogwidgets \
..
	       
MOC_DIR =     ..\objects
OBJECTS_DIR = ..\objects
TARGET =       analogwidgets_plugin
DESTDIR =      ../
CONFIG += release warn_on plugin qt


TEMPLATE = lib

include (../../Flags.pri )

target.path += $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target
