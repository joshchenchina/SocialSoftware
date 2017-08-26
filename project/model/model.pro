QT += core
QT += sql

QT -= gui

CONFIG += c++11

TARGET = model
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app



HEADERS += \
    User.h \
    Admin.h \
    GroupHistory.h \
    Group.h \
    Upload.h \
    Configuration.h \
    Command.h \
    Website.h

SOURCES += \
    User.cpp \
    Admin.cpp \
    GroupHistory.cpp \
    Group.cpp \
    main.cpp \
    Upload.cpp \
    Configuration.cpp \
    Command.cpp \
    Website.cpp

