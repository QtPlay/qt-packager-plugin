QT       += network
TEMPLATE = lib
TARGET = PackagerPlugin
CONFIG += plugin
CONFIG -= app_bundle
version = 1.0.0

ROOT = ../../../
BIN = ../../bin

INCLUDEPATH = $$ROOT/interfaces
DESTDIR = $$BIN
MOC_DIR = moc
OBJECTS_DIR = obj
SOURCES += \
    packagerplugin.cpp
HEADERS += \
    $$ROOT/interfaces/packager.h \
    packagerplugin.h
