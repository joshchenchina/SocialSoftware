/********************************************************************************
** Form generated from reading UI file 'createnewgroup.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWGROUP_H
#define UI_CREATENEWGROUP_H

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

class Ui_CreateNewGroup
{
public:
    QWidget *centralwidget;
    QLabel *newMemberEdit;
    QPushButton *CancelButton;
    QPushButton *OKButton;
    QLabel *errorBox;
    QLabel *label_2;
    QLineEdit *GroupNameEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreateNewGroup)
    {
        if (CreateNewGroup->objectName().isEmpty())
            CreateNewGroup->setObjectName(QStringLiteral("CreateNewGroup"));
        CreateNewGroup->resize(548, 384);
        centralwidget = new QWidget(CreateNewGroup);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        newMemberEdit = new QLabel(centralwidget);
        newMemberEdit->setObjectName(QStringLiteral("newMemberEdit"));
        newMemberEdit->setGeometry(QRect(9, 9, 396, 16));
        CancelButton = new QPushButton(centralwidget);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(440, 250, 85, 27));
        OKButton = new QPushButton(centralwidget);
        OKButton->setObjectName(QStringLiteral("OKButton"));
        OKButton->setGeometry(QRect(340, 250, 85, 27));
        errorBox = new QLabel(centralwidget);
        errorBox->setObjectName(QStringLiteral("errorBox"));
        errorBox->setGeometry(QRect(180, 190, 341, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(114, 130, 90, 16));
        GroupNameEdit = new QLineEdit(centralwidget);
        GroupNameEdit->setObjectName(QStringLiteral("GroupNameEdit"));
        GroupNameEdit->setGeometry(QRect(210, 130, 251, 27));
        CreateNewGroup->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateNewGroup);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 548, 21));
        CreateNewGroup->setMenuBar(menubar);
        statusbar = new QStatusBar(CreateNewGroup);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CreateNewGroup->setStatusBar(statusbar);

        retranslateUi(CreateNewGroup);

        QMetaObject::connectSlotsByName(CreateNewGroup);
    } // setupUi

    void retranslateUi(QMainWindow *CreateNewGroup)
    {
        CreateNewGroup->setWindowTitle(QApplication::translate("CreateNewGroup", "MainWindow", 0));
        newMemberEdit->setText(QApplication::translate("CreateNewGroup", "                                    Create A New Group/Add new Members", 0));
        CancelButton->setText(QApplication::translate("CreateNewGroup", "Cancel", 0));
        OKButton->setText(QApplication::translate("CreateNewGroup", "OK", 0));
        errorBox->setText(QString());
        label_2->setText(QApplication::translate("CreateNewGroup", "Group Name: ", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateNewGroup: public Ui_CreateNewGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWGROUP_H
