#-------------------------------------------------
#
# Project created by QtCreator 2016-04-10T16:45:36
#
#-------------------------------------------------
QT += core
QT += sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = Gui

CONFIG -= console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += ../model/Group.cpp       \
           ../model/Command.cpp     \
           ../model/User.cpp        \
           ../model/Admin.cpp       \
           ../model/GroupHistory.cpp\
           ../model/Website.cpp\
           main.cpp\
           Homepage.cpp \
           mainwindow.cpp \
        Tweet.cpp \
        Messaging.cpp \
    Createnewgroup.cpp \
    AdminMainMenu.cpp \
    CreateUser.cpp \
    CreateBlogGroup.cpp \
    AddUsersToBlogs.cpp \
    Addnewusertomessagegroup.cpp \
    Thread.cpp \
    Blogeditor.cpp \
    ViewUserProfile.cpp \
    ProfileEdit.cpp \
    Blog.cpp

HEADERS  += ../model/Group.h     \
           ../model/Command.h   \
           ../model/User.h      \
           ../model/Admin.h     \
           ../model/GroupHistory.h \
           ../model/Website.h\
           Homepage.h \
           mainwindow.h \
           Tweet.h \
           Messaging.h \
    Createnewgroup.h \
    AdminMainMenu.h \
    CreateUser.h \
    CreateBlogGroup.h \
    AddUsersToBlogs.h \
    Addnewusertomessagegroup.h \
    Thread.h \
    Blogeditor.h \
    ViewUserProfile.h \
    ProfileEdit.h \
    Blog.h

FORMS    += mainwindow.ui \
            homepage.ui \
            tweet.ui \
            messaging.ui \
    createnewgroup.ui \
    AdminMainMenu.ui \
    CreateUser.ui \
    CreateBlogGroup.ui \
    AddUsersToBlogs.ui \
    addnewusertomessagegroup.ui \
    blogeditor.ui \
    ViewUserProfile.ui \
    ProfileEdit.ui \
    blog.ui

RESOURCES +=
