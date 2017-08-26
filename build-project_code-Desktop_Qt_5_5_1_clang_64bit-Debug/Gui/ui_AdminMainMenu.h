/********************************************************************************
** Form generated from reading UI file 'AdminMainMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMAINMENU_H
#define UI_ADMINMAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminMainMenu
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *newBlogButton;
    QPushButton *createUser;
    QPushButton *addUsersButton;
    QPushButton *LogOutButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminMainMenu)
    {
        if (AdminMainMenu->objectName().isEmpty())
            AdminMainMenu->setObjectName(QStringLiteral("AdminMainMenu"));
        AdminMainMenu->resize(800, 600);
        centralwidget = new QWidget(AdminMainMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 70, 101, 41));
        newBlogButton = new QPushButton(centralwidget);
        newBlogButton->setObjectName(QStringLiteral("newBlogButton"));
        newBlogButton->setGeometry(QRect(280, 200, 201, 31));
        createUser = new QPushButton(centralwidget);
        createUser->setObjectName(QStringLiteral("createUser"));
        createUser->setGeometry(QRect(280, 150, 201, 31));
        addUsersButton = new QPushButton(centralwidget);
        addUsersButton->setObjectName(QStringLiteral("addUsersButton"));
        addUsersButton->setGeometry(QRect(280, 250, 201, 31));
        LogOutButton = new QPushButton(centralwidget);
        LogOutButton->setObjectName(QStringLiteral("LogOutButton"));
        LogOutButton->setGeometry(QRect(610, 430, 92, 27));
        AdminMainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminMainMenu);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        AdminMainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminMainMenu);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AdminMainMenu->setStatusBar(statusbar);

        retranslateUi(AdminMainMenu);

        QMetaObject::connectSlotsByName(AdminMainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *AdminMainMenu)
    {
        AdminMainMenu->setWindowTitle(QApplication::translate("AdminMainMenu", "MainWindow", 0));
        label->setText(QApplication::translate("AdminMainMenu", "ADMIN MENU", 0));
        newBlogButton->setText(QApplication::translate("AdminMainMenu", "Create New Blog group", 0));
        createUser->setText(QApplication::translate("AdminMainMenu", "Create New User", 0));
        addUsersButton->setText(QApplication::translate("AdminMainMenu", "Add Users to Blogs", 0));
        LogOutButton->setText(QApplication::translate("AdminMainMenu", "LOGOUT", 0));
    } // retranslateUi

};

namespace Ui {
    class AdminMainMenu: public Ui_AdminMainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMAINMENU_H
