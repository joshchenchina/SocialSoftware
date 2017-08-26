/********************************************************************************
** Form generated from reading UI file 'blogeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOGEDITOR_H
#define UI_BLOGEDITOR_H

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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlogEditor
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *returnButton;
    QLabel *label_2;
    QPushButton *okButton;
    QPushButton *commentDeletionButton_;
    QPushButton *downloadButton;
    QListWidget *groupListWidget;
    QListWidget *bloglistWidget;
    QPushButton *tweetButton;
    QPushButton *blogButton;
    QPushButton *blogdeletionButton;
    QListWidget *commentlistWidget;
    QTextEdit *CommentEdit;
    QListWidget *mediaPosts;
    QTextBrowser *userList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BlogEditor)
    {
        if (BlogEditor->objectName().isEmpty())
            BlogEditor->setObjectName(QStringLiteral("BlogEditor"));
        BlogEditor->resize(1218, 507);
        centralwidget = new QWidget(BlogEditor);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(510, 10, 221, 41));
        returnButton = new QPushButton(centralwidget);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(10, 10, 92, 27));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 40, 201, 16));
        okButton = new QPushButton(centralwidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(810, 410, 155, 27));
        commentDeletionButton_ = new QPushButton(centralwidget);
        commentDeletionButton_->setObjectName(QStringLiteral("commentDeletionButton_"));
        commentDeletionButton_->setGeometry(QRect(1000, 410, 155, 27));
        downloadButton = new QPushButton(centralwidget);
        downloadButton->setObjectName(QStringLiteral("downloadButton"));
        downloadButton->setGeometry(QRect(630, 420, 121, 27));
        groupListWidget = new QListWidget(centralwidget);
        groupListWidget->setObjectName(QStringLiteral("groupListWidget"));
        groupListWidget->setGeometry(QRect(11, 71, 191, 211));
        bloglistWidget = new QListWidget(centralwidget);
        bloglistWidget->setObjectName(QStringLiteral("bloglistWidget"));
        bloglistWidget->setGeometry(QRect(210, 70, 361, 341));
        tweetButton = new QPushButton(centralwidget);
        tweetButton->setObjectName(QStringLiteral("tweetButton"));
        tweetButton->setGeometry(QRect(210, 420, 101, 27));
        blogButton = new QPushButton(centralwidget);
        blogButton->setObjectName(QStringLiteral("blogButton"));
        blogButton->setGeometry(QRect(320, 420, 101, 27));
        blogdeletionButton = new QPushButton(centralwidget);
        blogdeletionButton->setObjectName(QStringLiteral("blogdeletionButton"));
        blogdeletionButton->setGeometry(QRect(430, 420, 141, 27));
        commentlistWidget = new QListWidget(centralwidget);
        commentlistWidget->setObjectName(QStringLiteral("commentlistWidget"));
        commentlistWidget->setGeometry(QRect(809, 72, 381, 192));
        CommentEdit = new QTextEdit(centralwidget);
        CommentEdit->setObjectName(QStringLiteral("CommentEdit"));
        CommentEdit->setGeometry(QRect(809, 270, 381, 121));
        QFont font;
        font.setPointSize(13);
        CommentEdit->setFont(font);
        mediaPosts = new QListWidget(centralwidget);
        mediaPosts->setObjectName(QStringLiteral("mediaPosts"));
        mediaPosts->setGeometry(QRect(585, 71, 211, 341));
        userList = new QTextBrowser(centralwidget);
        userList->setObjectName(QStringLiteral("userList"));
        userList->setGeometry(QRect(10, 290, 191, 151));
        BlogEditor->setCentralWidget(centralwidget);
        groupListWidget->raise();
        bloglistWidget->raise();
        tweetButton->raise();
        blogButton->raise();
        blogdeletionButton->raise();
        commentlistWidget->raise();
        CommentEdit->raise();
        label->raise();
        returnButton->raise();
        label_2->raise();
        okButton->raise();
        commentDeletionButton_->raise();
        downloadButton->raise();
        mediaPosts->raise();
        userList->raise();
        menubar = new QMenuBar(BlogEditor);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1218, 21));
        BlogEditor->setMenuBar(menubar);
        statusbar = new QStatusBar(BlogEditor);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        BlogEditor->setStatusBar(statusbar);

        retranslateUi(BlogEditor);

        QMetaObject::connectSlotsByName(BlogEditor);
    } // setupUi

    void retranslateUi(QMainWindow *BlogEditor)
    {
        BlogEditor->setWindowTitle(QApplication::translate("BlogEditor", "MainWindow", 0));
        label->setText(QApplication::translate("BlogEditor", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; text-decoration: underline;\">Blog/Tweet</span></p></body></html>", 0));
        returnButton->setText(QApplication::translate("BlogEditor", "<-- Return", 0));
        label_2->setText(QApplication::translate("BlogEditor", "*Notice: Double Click to Select", 0));
        okButton->setText(QApplication::translate("BlogEditor", "Submit", 0));
        commentDeletionButton_->setText(QApplication::translate("BlogEditor", "Delete this Comment", 0));
        downloadButton->setText(QApplication::translate("BlogEditor", "Download File", 0));
        tweetButton->setText(QApplication::translate("BlogEditor", "Create Tweet", 0));
        blogButton->setText(QApplication::translate("BlogEditor", "Create Blog", 0));
        blogdeletionButton->setText(QApplication::translate("BlogEditor", "Delete this Blogs", 0));
    } // retranslateUi

};

namespace Ui {
    class BlogEditor: public Ui_BlogEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOGEDITOR_H
