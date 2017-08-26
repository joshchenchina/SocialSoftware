/********************************************************************************
** Form generated from reading UI file 'tweet.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWEET_H
#define UI_TWEET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tweet
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTextEdit *tweetEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *enterButton;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Tweet)
    {
        if (Tweet->objectName().isEmpty())
            Tweet->setObjectName(QStringLiteral("Tweet"));
        Tweet->resize(573, 450);
        centralwidget = new QWidget(Tweet);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        tweetEdit = new QTextEdit(centralwidget);
        tweetEdit->setObjectName(QStringLiteral("tweetEdit"));

        verticalLayout->addWidget(tweetEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        enterButton = new QPushButton(centralwidget);
        enterButton->setObjectName(QStringLiteral("enterButton"));

        horizontalLayout->addWidget(enterButton);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        Tweet->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Tweet);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 573, 21));
        Tweet->setMenuBar(menubar);
        statusbar = new QStatusBar(Tweet);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Tweet->setStatusBar(statusbar);

        retranslateUi(Tweet);

        QMetaObject::connectSlotsByName(Tweet);
    } // setupUi

    void retranslateUi(QMainWindow *Tweet)
    {
        Tweet->setWindowTitle(QApplication::translate("Tweet", "MainWindow", 0));
        label->setText(QApplication::translate("Tweet", "                                  Tweet", 0));
        label_2->setText(QApplication::translate("Tweet", "              Maximize Content: 250", 0));
        tweetEdit->setHtml(QApplication::translate("Tweet", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'.Helvetica Neue DeskInterface'; font-size:13pt;\"><br /></p></body></html>", 0));
        enterButton->setText(QApplication::translate("Tweet", "Enter", 0));
        pushButton->setText(QApplication::translate("Tweet", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Tweet: public Ui_Tweet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWEET_H
