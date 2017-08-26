#ifndef MESSAGING_H
#define MESSAGING_H

#include <QMainWindow>
#include <QApplication>
#include <QCoreApplication>
#include <QtSql>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QScrollBar>

#include "../model/User.h"
#include "../model/Group.h"
#include "Createnewgroup.h"
#include "Thread.h"
#include "Addnewusertomessagegroup.h"

namespace Ui {
class Messaging;
}

class Messaging : public QMainWindow
{
    Q_OBJECT

public:
    explicit Messaging(QWidget *parent = 0, User* user = NULL);
    ~Messaging();
    Thread * myThread;

public slots:
    void onupdate();

private slots:

    /**
     * @brief Return to the HomePage
     */
    void on_pushButton_clicked();

    /**
     * @brief Create a New Group
     */
    void on_pushButton_2_clicked();

    /**
     * @brief Choose a Group showed in Grouplist of the user
     */
    void on_GrouplistWidget_itemDoubleClicked(QListWidgetItem *item);

    /**
     * @brief Submit a Message to a certain group
     */
    void on_EnterButton_clicked();

    /**
     * @brief Delete a certain Group
     */
    void on_DeleteButton_clicked();

    /**
     * @brief Add an existing user into a group by username
     */
    void on_AddUserButton_clicked();

private:
    Ui::Messaging *ui;
    QMainWindow * subscreen;
    QSqlDatabase db;
    User* user;

    /**
     * @brief Update GroupList of the user
     */
    void updateGroupList();

    /**
     * @brief updateUserList updates the text browser which displayes the users in the chat
     */
    void updateUserList();

    /**
     * @brief Update the message of a Group
     */
    void updateMessages();
    int currentGroupID = -1;//set default currentGroupID as -1
    void setBackground();
};

#endif // MESSAGING_H
