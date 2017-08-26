#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QString>
#include <QMainWindow>
#include <QApplication>
#include <QCoreApplication>
#include <QtSql>

#include "mainwindow.h"
#include "Tweet.h"
#include "Messaging.h"
#include "ViewUserProfile.h"
#include "Blogeditor.h"
#include "ProfileEdit.h"

#include "../model/User.h"
#include "../model/Website.h"

namespace Ui {
class HomePage;
}

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0, User* u = NULL);
    ~HomePage();

private slots:
    /**
     * @brief Logout this account
     */
    void on_LogoutButton_clicked();

    /**
     * @brief Open Tweet Screen to post a Tweet
     */
    void on_TweetButton_clicked();

    /**
     * @brief Open Message Screen
     */
    void on_MessageButton_clicked();

    /**
     * @brief Screen to view User Profile
     */
    void on_viewProfile_clicked();

    /**
     * @brief Open Blog/tweet Screen
     */
    void on_BlogButton_clicked();

    /**
     * @brief Screen to edit user profile
     */
    void on_profileEdit_clicked();


    /**
     * @brief Open the website
     */
    void on_WebsiteButton_clicked();

private:
    Ui::HomePage *ui;
    QMainWindow* subscreen;
    User *user;
    void setBackground();
};

#endif // HOMEPAGE_H
