/********************************************************************************
** Form generated from reading UI file 'CreateBlogGroup.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEBLOGGROUP_H
#define UI_CREATEBLOGGROUP_H

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

class Ui_CreateBlogGroup
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *groupNameEdit;
    QLabel *label_2;
    QPushButton *OKButton;
    QPushButton *cancelButton;
    QLabel *errorText;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreateBlogGroup)
    {
        if (CreateBlogGroup->objectName().isEmpty())
            CreateBlogGroup->setObjectName(QStringLiteral("CreateBlogGroup"));
        CreateBlogGroup->resize(542, 435);
        centralwidget = new QWidget(CreateBlogGroup);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 70, 131, 16));
        groupNameEdit = new QLineEdit(centralwidget);
        groupNameEdit->setObjectName(QStringLiteral("groupNameEdit"));
        groupNameEdit->setGeometry(QRect(200, 160, 113, 27));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 130, 141, 16));
        OKButton = new QPushButton(centralwidget);
        OKButton->setObjectName(QStringLiteral("OKButton"));
        OKButton->setGeometry(QRect(80, 270, 92, 27));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(350, 270, 92, 27));
        errorText = new QLabel(centralwidget);
        errorText->setObjectName(QStringLiteral("errorText"));
        errorText->setGeometry(QRect(100, 210, 351, 20));
        CreateBlogGroup->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateBlogGroup);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 542, 21));
        CreateBlogGroup->setMenuBar(menubar);
        statusbar = new QStatusBar(CreateBlogGroup);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CreateBlogGroup->setStatusBar(statusbar);

        retranslateUi(CreateBlogGroup);

        QMetaObject::connectSlotsByName(CreateBlogGroup);
    } // setupUi

    void retranslateUi(QMainWindow *CreateBlogGroup)
    {
        CreateBlogGroup->setWindowTitle(QApplication::translate("CreateBlogGroup", "MainWindow", 0));
        label->setText(QApplication::translate("CreateBlogGroup", "Blog Group Creator", 0));
        label_2->setText(QApplication::translate("CreateBlogGroup", "BlogGroupName", 0));
        OKButton->setText(QApplication::translate("CreateBlogGroup", "OK", 0));
        cancelButton->setText(QApplication::translate("CreateBlogGroup", "Cancel", 0));
        errorText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateBlogGroup: public Ui_CreateBlogGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEBLOGGROUP_H
