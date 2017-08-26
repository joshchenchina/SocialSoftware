/********************************************************************************
** Form generated from reading UI file 'blogeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOGEDITOR_H
#define UI_BLOGEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlogEditor
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *returnButton;
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *groupListWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *bloglistWidget;
    QPushButton *tweetButton;
    QPushButton *blogButton;
    QPushButton *blogdeletionButton;
    QVBoxLayout *verticalLayout_3;
    QListWidget *commentlistWidget;
    QTextEdit *CommentEdit;
    QVBoxLayout *verticalLayout_2;
    QPushButton *okButton;
    QPushButton *commentDeletionButton_;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BlogEditor)
    {
        if (BlogEditor->objectName().isEmpty())
            BlogEditor->setObjectName(QStringLiteral("BlogEditor"));
        BlogEditor->resize(1218, 600);
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
        label_2->setGeometry(QRect(960, 30, 201, 16));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 70, 1191, 462));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupListWidget = new QListWidget(layoutWidget);
        groupListWidget->setObjectName(QStringLiteral("groupListWidget"));

        horizontalLayout->addWidget(groupListWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        bloglistWidget = new QListWidget(layoutWidget);
        bloglistWidget->setObjectName(QStringLiteral("bloglistWidget"));

        verticalLayout->addWidget(bloglistWidget);

        tweetButton = new QPushButton(layoutWidget);
        tweetButton->setObjectName(QStringLiteral("tweetButton"));

        verticalLayout->addWidget(tweetButton);

        blogButton = new QPushButton(layoutWidget);
        blogButton->setObjectName(QStringLiteral("blogButton"));

        verticalLayout->addWidget(blogButton);

        blogdeletionButton = new QPushButton(layoutWidget);
        blogdeletionButton->setObjectName(QStringLiteral("blogdeletionButton"));

        verticalLayout->addWidget(blogdeletionButton);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        commentlistWidget = new QListWidget(layoutWidget);
        commentlistWidget->setObjectName(QStringLiteral("commentlistWidget"));

        verticalLayout_3->addWidget(commentlistWidget);

        CommentEdit = new QTextEdit(layoutWidget);
        CommentEdit->setObjectName(QStringLiteral("CommentEdit"));

        verticalLayout_3->addWidget(CommentEdit);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        verticalLayout_2->addWidget(okButton);

        commentDeletionButton_ = new QPushButton(layoutWidget);
        commentDeletionButton_->setObjectName(QStringLiteral("commentDeletionButton_"));

        verticalLayout_2->addWidget(commentDeletionButton_);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);

        BlogEditor->setCentralWidget(centralwidget);
        label->raise();
        returnButton->raise();
        layoutWidget->raise();
        label_2->raise();
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
        tweetButton->setText(QApplication::translate("BlogEditor", "Create Tweet", 0));
        blogButton->setText(QApplication::translate("BlogEditor", "Create Blog", 0));
        blogdeletionButton->setText(QApplication::translate("BlogEditor", "Delete this Blogs", 0));
        okButton->setText(QApplication::translate("BlogEditor", "Submit", 0));
        commentDeletionButton_->setText(QApplication::translate("BlogEditor", "Delete this Comment", 0));
    } // retranslateUi

};

namespace Ui {
    class BlogEditor: public Ui_BlogEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOGEDITOR_H
