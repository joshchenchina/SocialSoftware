#ifndef ADDUSERSTOBLOGS_H
#define ADDUSERSTOBLOGS_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMessageBox>
#include "../model/User.h"
#include "../model/Admin.h"
namespace Ui {
class AddUsersToBlogs;
}

class AddUsersToBlogs : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddUsersToBlogs(QWidget *parent = 0, Admin* a = NULL);
    ~AddUsersToBlogs();

private slots:
    /**
     * @brief Return to the AdminMainMenu Screen
     */
    void on_cancelButton_clicked();

    /**
     * @brief Select a Group on the lsit
     */
    void on_GroupList_itemDoubleClicked(QListWidgetItem *item);

    /**
     * @brief Add user into selected Group
     */
    void on_addUserButton_clicked();

    /**
     * @brief Delete selected Group
     */
    void on_pushButton_clicked();

private:
    Ui::AddUsersToBlogs *ui;
    Admin* admin;
    int currentGroupID = -1;
    void updateList();
    void setBackground();
};

#endif // ADDUSERSTOBLOGS_H
