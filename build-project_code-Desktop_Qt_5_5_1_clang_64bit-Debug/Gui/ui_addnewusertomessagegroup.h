/********************************************************************************
** Form generated from reading UI file 'addnewusertomessagegroup.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWUSERTOMESSAGEGROUP_H
#define UI_ADDNEWUSERTOMESSAGEGROUP_H

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

class Ui_AddNewUsertoMessageGroup
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *okButton_2;
    QPushButton *cancelButton_2;
    QLabel *errorBox;
    QLineEdit *usernameEdit_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddNewUsertoMessageGroup)
    {
        if (AddNewUsertoMessageGroup->objectName().isEmpty())
            AddNewUsertoMessageGroup->setObjectName(QStringLiteral("AddNewUsertoMessageGroup"));
        AddNewUsertoMessageGroup->resize(556, 392);
        centralwidget = new QWidget(AddNewUsertoMessageGroup);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 9, 299, 16));
        okButton_2 = new QPushButton(centralwidget);
        okButton_2->setObjectName(QStringLiteral("okButton_2"));
        okButton_2->setGeometry(QRect(60, 300, 85, 27));
        cancelButton_2 = new QPushButton(centralwidget);
        cancelButton_2->setObjectName(QStringLiteral("cancelButton_2"));
        cancelButton_2->setGeometry(QRect(410, 300, 85, 27));
        errorBox = new QLabel(centralwidget);
        errorBox->setObjectName(QStringLiteral("errorBox"));
        errorBox->setGeometry(QRect(110, 220, 351, 20));
        usernameEdit_2 = new QLineEdit(centralwidget);
        usernameEdit_2->setObjectName(QStringLiteral("usernameEdit_2"));
        usernameEdit_2->setGeometry(QRect(199, 150, 231, 27));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 150, 73, 16));
        AddNewUsertoMessageGroup->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddNewUsertoMessageGroup);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 556, 21));
        AddNewUsertoMessageGroup->setMenuBar(menubar);
        statusbar = new QStatusBar(AddNewUsertoMessageGroup);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AddNewUsertoMessageGroup->setStatusBar(statusbar);

        retranslateUi(AddNewUsertoMessageGroup);

        QMetaObject::connectSlotsByName(AddNewUsertoMessageGroup);
    } // setupUi

    void retranslateUi(QMainWindow *AddNewUsertoMessageGroup)
    {
        AddNewUsertoMessageGroup->setWindowTitle(QApplication::translate("AddNewUsertoMessageGroup", "MainWindow", 0));
        label->setText(QApplication::translate("AddNewUsertoMessageGroup", "                                                 Add A New User", 0));
        okButton_2->setText(QApplication::translate("AddNewUsertoMessageGroup", "OK", 0));
        cancelButton_2->setText(QApplication::translate("AddNewUsertoMessageGroup", "Cancel", 0));
        errorBox->setText(QString());
        label_3->setText(QApplication::translate("AddNewUsertoMessageGroup", "UserName:", 0));
    } // retranslateUi

};

namespace Ui {
    class AddNewUsertoMessageGroup: public Ui_AddNewUsertoMessageGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWUSERTOMESSAGEGROUP_H
