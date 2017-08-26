/********************************************************************************
** Form generated from reading UI file 'AddUsersToBlogs.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERSTOBLOGS_H
#define UI_ADDUSERSTOBLOGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *cancelButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *username;
    QPushButton *addUserButton;
    QLabel *errorBox;
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
        label->setGeometry(QRect(210, 0, 241, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 40, 301, 16));
        GroupName = new QLabel(centralwidget);
        GroupName->setObjectName(QStringLiteral("GroupName"));
        GroupName->setGeometry(QRect(430, 140, 241, 16));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(470, 300, 178, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(413, 210, 271, 52));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        username = new QLineEdit(layoutWidget1);
        username->setObjectName(QStringLiteral("username"));

        horizontalLayout->addWidget(username);

        addUserButton = new QPushButton(layoutWidget1);
        addUserButton->setObjectName(QStringLiteral("addUserButton"));

        horizontalLayout->addWidget(addUserButton);


        verticalLayout->addLayout(horizontalLayout);

        errorBox = new QLabel(layoutWidget1);
        errorBox->setObjectName(QStringLiteral("errorBox"));

        verticalLayout->addWidget(errorBox);

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
        label->setText(QApplication::translate("AddUsersToBlogs", "Add Users to Groups/ Delete Groups", 0));
        label_2->setText(QApplication::translate("AddUsersToBlogs", "Groups : Double click on a group to select it", 0));
        GroupName->setText(QString());
        pushButton->setText(QApplication::translate("AddUsersToBlogs", "Delete", 0));
        cancelButton->setText(QApplication::translate("AddUsersToBlogs", "Cancel", 0));
        addUserButton->setText(QApplication::translate("AddUsersToBlogs", "AddUser", 0));
        errorBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddUsersToBlogs: public Ui_AddUsersToBlogs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERSTOBLOGS_H
