QT += core
QT += sql

QT -= gui

CONFIG += c++11

TARGET = unittest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += googletest                       \
               googletest/src                   \
               googletest/src/gtest             \
               googletest/include               \
               googletest/include/gtest         \
               googletest/include/gtest/internal

SOURCES += main.cpp \
           ../model/User.cpp    \
           ../model/Group.cpp   \
           ../model/GroupHistory.cpp \
           ../model/Command.cpp    \
    TestUser.cpp \
    TestLoginVerification.cpp \
    TestGroup.cpp

HEADERS += ../model/User.h    \
           ../model/Group.h   \
           ../model/GroupHistory.h \
           ../model/Command.h

LIBS +=  -L/usr/lib -Wall -Wextra -pthread

SOURCES += "googletest/src/gtest.cc"            \
           "googletest/src/gtest-death-test.cc" \
           "googletest/src/gtest-filepath.cc"   \
           "googletest/src/gtest-port.cc"       \
           "googletest/src/gtest-printers.cc"   \
           "googletest/src/gtest-test-part.cc"  \
           "googletest/src/gtest-typed-test.cc"

