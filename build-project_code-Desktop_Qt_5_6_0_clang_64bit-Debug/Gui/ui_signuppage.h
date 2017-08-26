/********************************************************************************
** Form generated from reading UI file 'signuppage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPPAGE_H
#define UI_SIGNUPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpPage
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *UsernameDisplay;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *PasswordDisplay;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SignUpPage)
    {
        if (SignUpPage->objectName().isEmpty())
            SignUpPage->setObjectName(QStringLiteral("SignUpPage"));
        SignUpPage->resize(630, 415);
        centralwidget = new QWidget(SignUpPage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 40, 61, 31));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 100, 206, 58));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        UsernameDisplay = new QLineEdit(layoutWidget);
        UsernameDisplay->setObjectName(QStringLiteral("UsernameDisplay"));

        horizontalLayout->addWidget(UsernameDisplay);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        PasswordDisplay = new QLineEdit(layoutWidget);
        PasswordDisplay->setObjectName(QStringLiteral("PasswordDisplay"));

        horizontalLayout_2->addWidget(PasswordDisplay);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(350, 250, 228, 32));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        submitButton = new QPushButton(layoutWidget1);
        submitButton->setObjectName(QStringLiteral("submitButton"));

        horizontalLayout_3->addWidget(submitButton);

        cancelButton = new QPushButton(layoutWidget1);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);

        SignUpPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SignUpPage);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 630, 22));
        SignUpPage->setMenuBar(menubar);
        statusbar = new QStatusBar(SignUpPage);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SignUpPage->setStatusBar(statusbar);

        retranslateUi(SignUpPage);

        QMetaObject::connectSlotsByName(SignUpPage);
    } // setupUi

    void retranslateUi(QMainWindow *SignUpPage)
    {
        SignUpPage->setWindowTitle(QApplication::translate("SignUpPage", "MainWindow", 0));
        label->setText(QApplication::translate("SignUpPage", "Sign Up", 0));
        label_2->setText(QApplication::translate("SignUpPage", "Username:", 0));
        label_3->setText(QApplication::translate("SignUpPage", "Password: ", 0));
        submitButton->setText(QApplication::translate("SignUpPage", "Submit", 0));
        cancelButton->setText(QApplication::translate("SignUpPage", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class SignUpPage: public Ui_SignUpPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPPAGE_H
