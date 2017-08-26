/********************************************************************************
** Form generated from reading UI file 'AddUsersToBlogs.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERSTOBLOGS_H
#define UI_ADDUSERSTOBLOGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddUsersToBlogs
{
public:
    QWidget *centralwidget;
    QListWidget *GroupList;
    QLabel *label;
    QLabel *label_2;
    QLabel *GroupName;
    QLineEdit *username;
    QLabel *errorBox;
    QPushButton *addUserButton;
    QPushButton *cancelButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddUsersToBlogs)
    {
        if (AddUsersToBlogs->objectName().isEmpty())
            AddUsersToBlogs->setObjectName(QStringLiteral("AddUsersToBlogs"));
        AddUsersToBlogs->resize(690, 600);
        centralwidget = new QWidget(AddUsersToBlogs);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        GroupList = new QListWidget(centralwidget);
        GroupList->setObjectName(QStringLiteral("GroupList"));
        GroupList->setGeometry(QRect(40, 60, 361, 451));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 0, 191, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 40, 301, 16));
        GroupName = new QLabel(centralwidget);
        GroupName->setObjectName(QStringLiteral("GroupName"));
        GroupName->setGeometry(QRect(430, 140, 241, 16));
        username = new QLineEdit(centralwidget);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(490, 200, 113, 27));
        errorBox = new QLabel(centralwidget);
        errorBox->setObjectName(QStringLiteral("errorBox"));
        errorBox->setGeometry(QRect(410, 240, 241, 20));
        addUserButton = new QPushButton(centralwidget);
        addUserButton->setObjectName(QStringLiteral("addUserButton"));
        addUserButton->setGeometry(QRect(500, 280, 92, 27));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(510, 450, 92, 27));
        AddUsersToBlogs->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddUsersToBlogs);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 690, 21));
        AddUsersToBlogs->setMenuBar(menubar);
        statusbar = new QStatusBar(AddUsersToBlogs);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AddUsersToBlogs->setStatusBar(statusbar);

        retranslateUi(AddUsersToBlogs);

        QMetaObject::connectSlotsByName(AddUsersToBlogs);
    } // setupUi

    void retranslateUi(QMainWindow *AddUsersToBlogs)
    {
        AddUsersToBlogs->setWindowTitle(QApplication::translate("AddUsersToBlogs", "MainWindow", 0));
        label->setText(QApplication::translate("AddUsersToBlogs", "Add Users to Groups", 0));
        label_2->setText(QApplication::translate("AddUsersToBlogs", "Groups : Double click on a group to select it", 0));
        GroupName->setText(QString());
        errorBox->setText(QString());
        addUserButton->setText(QApplication::translate("AddUsersToBlogs", "AddUser", 0));
        cancelButton->setText(QApplication::translate("AddUsersToBlogs", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddUsersToBlogs: public Ui_AddUsersToBlogs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERSTOBLOGS_H
