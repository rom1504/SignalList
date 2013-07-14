QT       += core gui widgets

TEMPLATE = lib
CONFIG+= staticlib
OBJECTS_DIR = temp/
MOC_DIR = $$OBJECTS_DIR
RCC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR


SOURCES += model/signallist.cpp

HEADERS  +=  adapter/signallistadapter.h \
	adapter/signallistadapter.hxx \
	model/signallist.h \
	model/signallist.hxx

QMAKE_CXXFLAGS += -std=c++11

OTHER_FILES += \
    README.md \
    .gitignore
