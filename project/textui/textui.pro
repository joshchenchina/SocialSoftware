#TEMPLATE = app
#CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt

QT += core
QT += sql

QT -= gui

CONFIG += c++11

TARGET = textui
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

LIBS    += -lncurses

#LIBS    += -ltinfo

SOURCES += main.cpp \
    MainMenu.cpp \
    Login.cpp \
    Messaging.cpp \
    PostCreator.cpp \
    Screen.cpp \
    HelpScreen.cpp \
    PostViewer.cpp \
    CommentViewer.cpp \

HEADERS += \
    MainMenu.h \
    Login.h \
    Messaging.h \
    PostCreator.h \
    Screen.h \
    HelpScreen.h \
    PostViewer.h \
    CommentViewer.h

HEADERS += ../model/Group.h         \
           ../model/Command.h       \
           ../model/User.h          \
           ../model/Admin.h         \
           ../model/GroupHistory.h  \
           ../model/Website.h \

SOURCES += ../model/Group.cpp           \
           ../model/Command.cpp         \
           ../model/User.cpp            \
           ../model/Admin.cpp           \
           ../model/GroupHistory.cpp    \
           ../model/Website.cpp \
