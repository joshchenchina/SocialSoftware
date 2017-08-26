/********************************************************************************
** Form generated from reading UI file 'ProfileEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEEDIT_H
#define UI_PROFILEEDIT_H

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

class Ui_ProfileEdit
{
public:
    QWidget *centralwidget;
    QLineEdit *oldPassword;
    QLineEdit *newPassword;
    QLineEdit *confirmPassword;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *changePassword;
    QLabel *label_4;
    QLineEdit *newName;
    QPushButton *changeName;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProfileEdit)
    {
        if (ProfileEdit->objectName().isEmpty())
            ProfileEdit->setObjectName(QStringLiteral("ProfileEdit"));
        ProfileEdit->resize(671, 421);
        centralwidget = new QWidget(ProfileEdit);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        oldPassword = new QLineEdit(centralwidget);
        oldPassword->setObjectName(QStringLiteral("oldPassword"));
        oldPassword->setGeometry(QRect(470, 90, 113, 27));
        oldPassword->setEchoMode(QLineEdit::Password);
        newPassword = new QLineEdit(centralwidget);
        newPassword->setObjectName(QStringLiteral("newPassword"));
        newPassword->setGeometry(QRect(470, 140, 113, 27));
        newPassword->setEchoMode(QLineEdit::Password);
        confirmPassword = new QLineEdit(centralwidget);
        confirmPassword->setObjectName(QStringLiteral("confirmPassword"));
        confirmPassword->setGeometry(QRect(470, 200, 113, 27));
        confirmPassword->setEchoMode(QLineEdit::Password);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 90, 121, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 150, 101, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(310, 200, 161, 20));
        changePassword = new QPushButton(centralwidget);
        changePassword->setObjectName(QStringLiteral("changePassword"));
        changePassword->setGeometry(QRect(460, 250, 141, 27));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 100, 121, 16));
        newName = new QLineEdit(centralwidget);
        newName->setObjectName(QStringLiteral("newName"));
        newName->setGeometry(QRect(130, 100, 113, 27));
        changeName = new QPushButton(centralwidget);
        changeName->setObjectName(QStringLiteral("changeName"));
        changeName->setGeometry(QRect(100, 140, 141, 27));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(220, 20, 231, 31));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(280, 320, 92, 27));
        ProfileEdit->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProfileEdit);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 671, 21));
        ProfileEdit->setMenuBar(menubar);
        statusbar = new QStatusBar(ProfileEdit);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ProfileEdit->setStatusBar(statusbar);

        retranslateUi(ProfileEdit);

        QMetaObject::connectSlotsByName(ProfileEdit);
    } // setupUi

    void retranslateUi(QMainWindow *ProfileEdit)
    {
        ProfileEdit->setWindowTitle(QApplication::translate("ProfileEdit", "MainWindow", 0));
        label->setText(QApplication::translate("ProfileEdit", "Current Password:", 0));
        label_2->setText(QApplication::translate("ProfileEdit", "New Password:", 0));
        label_3->setText(QApplication::translate("ProfileEdit", "Confirm New Password:", 0));
        changePassword->setText(QApplication::translate("ProfileEdit", "Change Password", 0));
        label_4->setText(QApplication::translate("ProfileEdit", "New Name", 0));
        changeName->setText(QApplication::translate("ProfileEdit", "Change Name", 0));
        label_5->setText(QApplication::translate("ProfileEdit", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; text-decoration: underline;\">PROFILE EDITOR</span></p></body></html>", 0));
        pushButton_3->setText(QApplication::translate("ProfileEdit", "DONE", 0));
    } // retranslateUi

};

namespace Ui {
    class ProfileEdit: public Ui_ProfileEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEEDIT_H
