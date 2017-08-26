/********************************************************************************
** Form generated from reading UI file 'blog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOG_H
#define UI_BLOG_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Blog
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTextEdit *blogEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *enterButton;
    QPushButton *cancelButton;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *filePathEdit;
    QPushButton *pathButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Blog)
    {
        if (Blog->objectName().isEmpty())
            Blog->setObjectName(QStringLiteral("Blog"));
        Blog->resize(800, 600);
        centralwidget = new QWidget(Blog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_4->addWidget(label);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        blogEdit = new QTextEdit(centralwidget);
        blogEdit->setObjectName(QStringLiteral("blogEdit"));
        QFont font1;
        font1.setPointSize(11);
        blogEdit->setFont(font1);

        verticalLayout->addWidget(blogEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        enterButton = new QPushButton(centralwidget);
        enterButton->setObjectName(QStringLiteral("enterButton"));

        horizontalLayout->addWidget(enterButton);

        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(75);
        label_3->setFont(font2);

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        filePathEdit = new QLineEdit(centralwidget);
        filePathEdit->setObjectName(QStringLiteral("filePathEdit"));

        horizontalLayout_2->addWidget(filePathEdit);

        pathButton = new QPushButton(centralwidget);
        pathButton->setObjectName(QStringLiteral("pathButton"));

        horizontalLayout_2->addWidget(pathButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        Blog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Blog);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        Blog->setMenuBar(menubar);
        statusbar = new QStatusBar(Blog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Blog->setStatusBar(statusbar);

        retranslateUi(Blog);

        QMetaObject::connectSlotsByName(Blog);
    } // setupUi

    void retranslateUi(QMainWindow *Blog)
    {
        Blog->setWindowTitle(QApplication::translate("Blog", "MainWindow", 0));
        label->setText(QApplication::translate("Blog", "                                                     Blog", 0));
        label_2->setText(QApplication::translate("Blog", "              Maximize Content: 500", 0));
        enterButton->setText(QApplication::translate("Blog", "Enter", 0));
        cancelButton->setText(QApplication::translate("Blog", "Cancel", 0));
        label_3->setText(QApplication::translate("Blog", "Add a filepath to the media you would like to include:", 0));
        pathButton->setText(QApplication::translate("Blog", "Submit", 0));
    } // retranslateUi

};

namespace Ui {
    class Blog: public Ui_Blog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOG_H
