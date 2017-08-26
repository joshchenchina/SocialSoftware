/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *profileEdit;
    QPushButton *viewProfile;
    QPushButton *MessageButton;
    QPushButton *BlogButton;
    QPushButton *TweetButton;
    QPushButton *WebsiteButton;
    QPushButton *LogoutButton;
    QLineEdit *userNameEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName(QStringLiteral("HomePage"));
        HomePage->resize(742, 519);
        centralwidget = new QWidget(HomePage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 50, 221, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(540, 420, 211, 31));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 130, 151, 260));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        profileEdit = new QPushButton(layoutWidget);
        profileEdit->setObjectName(QStringLiteral("profileEdit"));

        verticalLayout->addWidget(profileEdit);

        viewProfile = new QPushButton(layoutWidget);
        viewProfile->setObjectName(QStringLiteral("viewProfile"));

        verticalLayout->addWidget(viewProfile);

        MessageButton = new QPushButton(layoutWidget);
        MessageButton->setObjectName(QStringLiteral("MessageButton"));

        verticalLayout->addWidget(MessageButton);

        BlogButton = new QPushButton(layoutWidget);
        BlogButton->setObjectName(QStringLiteral("BlogButton"));

        verticalLayout->addWidget(BlogButton);

        TweetButton = new QPushButton(layoutWidget);
        TweetButton->setObjectName(QStringLiteral("TweetButton"));

        verticalLayout->addWidget(TweetButton);

        WebsiteButton = new QPushButton(layoutWidget);
        WebsiteButton->setObjectName(QStringLiteral("WebsiteButton"));

        verticalLayout->addWidget(WebsiteButton);

        LogoutButton = new QPushButton(layoutWidget);
        LogoutButton->setObjectName(QStringLiteral("LogoutButton"));

        verticalLayout->addWidget(LogoutButton);

        userNameEdit = new QLineEdit(centralwidget);
        userNameEdit->setObjectName(QStringLiteral("userNameEdit"));
        userNameEdit->setGeometry(QRect(440, 170, 149, 27));
        HomePage->setCentralWidget(centralwidget);
        layoutWidget->raise();
        label->raise();
        label_2->raise();
        userNameEdit->raise();
        menubar = new QMenuBar(HomePage);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 742, 19));
        HomePage->setMenuBar(menubar);
        statusbar = new QStatusBar(HomePage);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        HomePage->setStatusBar(statusbar);
        toolBar = new QToolBar(HomePage);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        HomePage->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(HomePage);

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QMainWindow *HomePage)
    {
        HomePage->setWindowTitle(QApplication::translate("HomePage", "MainWindow", 0));
        label->setText(QApplication::translate("HomePage", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; text-decoration: underline;\">Home Menu</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("HomePage", "*Owned by Harvey Rocket Ranch", 0));
        profileEdit->setText(QApplication::translate("HomePage", "Edit Profile", 0));
        viewProfile->setText(QApplication::translate("HomePage", "View User Profile", 0));
        MessageButton->setText(QApplication::translate("HomePage", "Message", 0));
        BlogButton->setText(QApplication::translate("HomePage", "View Tweet and Blog", 0));
        TweetButton->setText(QApplication::translate("HomePage", "Create Tweet", 0));
        WebsiteButton->setText(QApplication::translate("HomePage", "Launch Website", 0));
        LogoutButton->setText(QApplication::translate("HomePage", "Log out", 0));
        userNameEdit->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("HomePage", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
