QT       += core gui widgets

TEMPLATE = lib
CONFIG+= staticlib
OBJECTS_DIR = temp/
MOC_DIR = $$OBJECTS_DIR
RCC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR

VPATH = source
INCLUDEPATH = source


SOURCES += model/signallist.cpp \
	adapter/qstringsignallistadapter.cpp

HEADERS  +=  adapter/signallistadapter.h \
	adapter/signallistadapter.hxx \
	model/signallist.h \
        model/signallist.hxx \
	adapter/qstringsignallistadapter.h

QMAKE_CXXFLAGS += -std=c++11

OTHER_FILES += \
    README.md \
    .gitignore
