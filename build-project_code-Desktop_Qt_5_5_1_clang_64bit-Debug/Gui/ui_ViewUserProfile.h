/********************************************************************************
** Form generated from reading UI file 'ViewUserProfile.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWUSERPROFILE_H
#define UI_VIEWUSERPROFILE_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewUserProfile
{
public:
    QWidget *centralwidget;
    QPushButton *cancelButton;
    QLabel *nameOfUser;
    QListWidget *uploadList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ViewUserProfile)
    {
        if (ViewUserProfile->objectName().isEmpty())
            ViewUserProfile->setObjectName(QStringLiteral("ViewUserProfile"));
        ViewUserProfile->resize(485, 600);
        centralwidget = new QWidget(ViewUserProfile);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(180, 530, 92, 27));
        nameOfUser = new QLabel(centralwidget);
        nameOfUser->setObjectName(QStringLiteral("nameOfUser"));
        nameOfUser->setGeometry(QRect(120, 10, 251, 16));
        QFont font;
        font.setPointSize(12);
        nameOfUser->setFont(font);
        uploadList = new QListWidget(centralwidget);
        uploadList->setObjectName(QStringLiteral("uploadList"));
        uploadList->setGeometry(QRect(25, 51, 421, 471));
        QFont font1;
        font1.setPointSize(11);
        uploadList->setFont(font1);
        uploadList->setTabKeyNavigation(true);
        uploadList->setAlternatingRowColors(true);
        uploadList->setIconSize(QSize(0, 0));
        uploadList->setTextElideMode(Qt::ElideNone);
        uploadList->setMovement(QListView::Free);
        uploadList->setFlow(QListView::TopToBottom);
        uploadList->setProperty("isWrapping", QVariant(false));
        uploadList->setResizeMode(QListView::Adjust);
        uploadList->setLayoutMode(QListView::Batched);
        uploadList->setSpacing(0);
        uploadList->setWordWrap(true);
        uploadList->setSortingEnabled(false);
        ViewUserProfile->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ViewUserProfile);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 485, 21));
        ViewUserProfile->setMenuBar(menubar);
        statusbar = new QStatusBar(ViewUserProfile);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ViewUserProfile->setStatusBar(statusbar);

        retranslateUi(ViewUserProfile);

        QMetaObject::connectSlotsByName(ViewUserProfile);
    } // setupUi

    void retranslateUi(QMainWindow *ViewUserProfile)
    {
        ViewUserProfile->setWindowTitle(QApplication::translate("ViewUserProfile", "MainWindow", 0));
        cancelButton->setText(QApplication::translate("ViewUserProfile", "Cancel", 0));
        nameOfUser->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ViewUserProfile: public Ui_ViewUserProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWUSERPROFILE_H
