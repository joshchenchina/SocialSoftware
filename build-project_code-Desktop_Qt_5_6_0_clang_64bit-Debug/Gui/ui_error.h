/********************************************************************************
** Form generated from reading UI file 'error.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_H
#define UI_ERROR_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Error
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *CancelButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Error)
    {
        if (Error->objectName().isEmpty())
            Error->setObjectName(QStringLiteral("Error"));
        Error->resize(627, 428);
        centralwidget = new QWidget(Error);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        CancelButton = new QPushButton(centralwidget);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        verticalLayout->addWidget(CancelButton);

        Error->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Error);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 627, 22));
        Error->setMenuBar(menubar);
        statusbar = new QStatusBar(Error);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Error->setStatusBar(statusbar);

        retranslateUi(Error);

        QMetaObject::connectSlotsByName(Error);
    } // setupUi

    void retranslateUi(QMainWindow *Error)
    {
        Error->setWindowTitle(QApplication::translate("Error", "MainWindow", 0));
        label->setText(QApplication::translate("Error", "                                                Your Username or Password is Incorrect!", 0));
        CancelButton->setText(QApplication::translate("Error", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Error: public Ui_Error {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_H
