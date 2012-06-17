#-------------------------------------------------
#
# Project created by QtCreator 2012-06-16T14:37:16
#
#-------------------------------------------------

QT       += core gui

TARGET = svod_unpacker
TEMPLATE = app

# WHY I'M NOT USING C++11 FEATURES:
# apple sucks and won't update GCC, and when I updated it it needed the -xarch_x86_64 switch, and I didn't really
# want to recompile.  so fuck you apple.
# QMAKE_CC = gcc-4.7
# QMAKE_CXX = g++-4.7
# QMAKE_CXXFLAGS += -std=c++11

DEFINES += UNICODE _UNICODE

SOURCES += main.cpp\
        mainwindow.cpp \
    Xbox/gdfxpackage.cpp \
    Xbox/stfspackage.cpp \
    Xbox/stdafx.cpp \
    Xbox/src/streambuf.cpp \
    Xbox/src/convert.cpp \
    Xbox/IO/xMultiFileStream.cpp \
    Xbox/IO/xFileStream.cpp \
    Xbox/IO/IStream.cpp

HEADERS  += mainwindow.h \
    Xbox/Structures.h \
    Xbox/gdfxpackage.h \
    Xbox/IO/xMultiFileStream.h \
    Xbox/IO/xFileStream.h \
    Xbox/IO/IStream.h \
    Xbox/xexception.h \
    Xbox/typedefs.h \
    Xbox/stfspackage.h \
    Xbox/stdafx.h \
    Xbox/nowide/streambuf.h \
    Xbox/nowide/fstream.h \
    Xbox/nowide/cstdio.h \
    Xbox/nowide/convert.h \
    Xbox/nowide/config.h

FORMS    += mainwindow.ui

