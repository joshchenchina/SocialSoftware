#ifndef ADMINMAINMENU_H
#define ADMINMAINMENU_H

#include <QWidget>
#include <QString>
#include <QMainWindow>

#include <QApplication>
#include <QCoreApplication>
#include <QtSql>
#include "mainwindow.h"
#include "CreateUser.h"
#include "CreateBlogGroup.h"
#include "AddUsersToBlogs.h"
#include "../model/User.h"
#include "../model/Admin.h"

namespace Ui {
class AdminMainMenu;
}

class AdminMainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainMenu(QWidget *parent = 0, Admin* a = NULL);
    ~AdminMainMenu();

private slots:
    /**
     * @brief Screen of Creating a new User
     */
    void on_createUser_clicked();

    /**
     * @brief Screen of creating a new blog group
     */
    void on_newBlogButton_clicked(bool checked);

    /**
     * @brief Log out
     */
    void on_LogOutButton_pressed();

    /**
     * @brief Screen of add user into an existing blog group
     */
    void on_addUsersButton_clicked();

private:
    Ui::AdminMainMenu *ui;
    QMainWindow* subscreen;
    Admin *admin;
    void setBackground();

};

#endif // ADMINMAINMENU_H
