/********************************************************************************
** Form generated from reading UI file 'CreateUser.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUSER_H
#define UI_CREATEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateUser
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *OK;
    QPushButton *cancel;
    QLineEdit *nameEdit;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *errorBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreateUser)
    {
        if (CreateUser->objectName().isEmpty())
            CreateUser->setObjectName(QStringLiteral("CreateUser"));
        CreateUser->resize(800, 600);
        centralwidget = new QWidget(CreateUser);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 80, 131, 31));
        OK = new QPushButton(centralwidget);
        OK->setObjectName(QStringLiteral("OK"));
        OK->setGeometry(QRect(100, 440, 92, 27));
        cancel = new QPushButton(centralwidget);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(590, 440, 92, 27));
        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(110, 260, 113, 27));
        usernameEdit = new QLineEdit(centralwidget);
        usernameEdit->setObjectName(QStringLiteral("usernameEdit"));
        usernameEdit->setGeometry(QRect(360, 260, 113, 27));
        passwordEdit = new QLineEdit(centralwidget);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setGeometry(QRect(590, 260, 113, 27));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 150, 181, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 240, 241, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(360, 240, 121, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(620, 240, 61, 15));
        errorBox = new QLabel(centralwidget);
        errorBox->setObjectName(QStringLiteral("errorBox"));
        errorBox->setGeometry(QRect(190, 350, 361, 20));
        CreateUser->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateUser);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        CreateUser->setMenuBar(menubar);
        statusbar = new QStatusBar(CreateUser);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CreateUser->setStatusBar(statusbar);

        retranslateUi(CreateUser);

        QMetaObject::connectSlotsByName(CreateUser);
    } // setupUi

    void retranslateUi(QMainWindow *CreateUser)
    {
        CreateUser->setWindowTitle(QApplication::translate("CreateUser", "MainWindow", 0));
        label->setText(QApplication::translate("CreateUser", "User Creator Lab", 0));
        OK->setText(QApplication::translate("CreateUser", "OK", 0));
        cancel->setText(QApplication::translate("CreateUser", "Cancel", 0));
        nameEdit->setText(QString());
        label_2->setText(QApplication::translate("CreateUser", "All fields must be entered", 0));
        label_3->setText(QApplication::translate("CreateUser", "Full name as [Lastname], [Firstname]", 0));
        label_4->setText(QApplication::translate("CreateUser", "Unique UserName", 0));
        label_5->setText(QApplication::translate("CreateUser", "Password", 0));
        errorBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateUser: public Ui_CreateUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSER_H
