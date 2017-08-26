/********************************************************************************
** Form generated from reading UI file 'messaging.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGING_H
#define UI_MESSAGING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Messaging
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *firstname;
    QPushButton *pushButton_2;
    QPushButton *DeleteButton;
    QPushButton *AddUserButton;
    QLabel *errorBox;
    QTextEdit *newMessageEdit;
    QLabel *firstname_2;
    QListWidget *GrouplistWidget;
    QTextBrowser *pastMessageView;
    QPushButton *EnterButton;
    QTextBrowser *userList;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Messaging)
    {
        if (Messaging->objectName().isEmpty())
            Messaging->setObjectName(QStringLiteral("Messaging"));
        Messaging->resize(753, 536);
        centralwidget = new QWidget(Messaging);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 115, 32));
        firstname = new QLabel(centralwidget);
        firstname->setObjectName(QStringLiteral("firstname"));
        firstname->setGeometry(QRect(80, 50, 71, 21));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 0, 141, 32));
        DeleteButton = new QPushButton(centralwidget);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));
        DeleteButton->setGeometry(QRect(410, 400, 141, 31));
        AddUserButton = new QPushButton(centralwidget);
        AddUserButton->setObjectName(QStringLiteral("AddUserButton"));
        AddUserButton->setGeometry(QRect(280, 400, 131, 31));
        errorBox = new QLabel(centralwidget);
        errorBox->setObjectName(QStringLiteral("errorBox"));
        errorBox->setGeometry(QRect(280, 450, 261, 16));
        newMessageEdit = new QTextEdit(centralwidget);
        newMessageEdit->setObjectName(QStringLiteral("newMessageEdit"));
        newMessageEdit->setGeometry(QRect(10, 380, 261, 75));
        firstname_2 = new QLabel(centralwidget);
        firstname_2->setObjectName(QStringLiteral("firstname_2"));
        firstname_2->setGeometry(QRect(310, 50, 241, 21));
        GrouplistWidget = new QListWidget(centralwidget);
        GrouplistWidget->setObjectName(QStringLiteral("GrouplistWidget"));
        GrouplistWidget->setGeometry(QRect(339, 71, 191, 301));
        GrouplistWidget->setAlternatingRowColors(true);
        GrouplistWidget->setSelectionRectVisible(false);
        pastMessageView = new QTextBrowser(centralwidget);
        pastMessageView->setObjectName(QStringLiteral("pastMessageView"));
        pastMessageView->setGeometry(QRect(11, 72, 321, 301));
        pastMessageView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        EnterButton = new QPushButton(centralwidget);
        EnterButton->setObjectName(QStringLiteral("EnterButton"));
        EnterButton->setGeometry(QRect(100, 460, 85, 27));
        userList = new QTextBrowser(centralwidget);
        userList->setObjectName(QStringLiteral("userList"));
        userList->setGeometry(QRect(535, 71, 201, 301));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(590, 50, 111, 20));
        Messaging->setCentralWidget(centralwidget);
        EnterButton->raise();
        firstname->raise();
        pushButton_2->raise();
        pushButton->raise();
        DeleteButton->raise();
        AddUserButton->raise();
        GrouplistWidget->raise();
        pastMessageView->raise();
        errorBox->raise();
        newMessageEdit->raise();
        firstname_2->raise();
        userList->raise();
        label->raise();
        menubar = new QMenuBar(Messaging);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 753, 21));
        Messaging->setMenuBar(menubar);
        statusbar = new QStatusBar(Messaging);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Messaging->setStatusBar(statusbar);

        retranslateUi(Messaging);

        QMetaObject::connectSlotsByName(Messaging);
    } // setupUi

    void retranslateUi(QMainWindow *Messaging)
    {
        Messaging->setWindowTitle(QApplication::translate("Messaging", "MainWindow", 0));
        pushButton->setText(QApplication::translate("Messaging", "<-- Return", 0));
        firstname->setText(QApplication::translate("Messaging", "Messages", 0));
        pushButton_2->setText(QApplication::translate("Messaging", "Create New Group", 0));
        DeleteButton->setText(QApplication::translate("Messaging", "Leave Group", 0));
        AddUserButton->setText(QApplication::translate("Messaging", "Add New User", 0));
        errorBox->setText(QString());
        firstname_2->setText(QApplication::translate("Messaging", "Group::Please DoubleClick on a group", 0));
        EnterButton->setText(QApplication::translate("Messaging", "Enter", 0));
        label->setText(QApplication::translate("Messaging", "Users in Group", 0));
    } // retranslateUi

};

namespace Ui {
    class Messaging: public Ui_Messaging {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGING_H
