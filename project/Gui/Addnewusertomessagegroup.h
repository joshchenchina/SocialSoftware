#ifndef ADDNEWUSERTOMESSAGEGROUP_H
#define ADDNEWUSERTOMESSAGEGROUP_H

#include <QMainWindow>
#include "../model/User.h"

namespace Ui {
class AddNewUsertoMessageGroup;
}

class AddNewUsertoMessageGroup : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewUsertoMessageGroup(QWidget *parent = 0, int groupID = -1, User *user = NULL);
    ~AddNewUsertoMessageGroup();

private slots:
    /**
     * @brief Return to the Messaging Screen
     */
    void on_cancelButton_2_clicked();

    /**
     * @brief Add a new User into the Message Group
     */
    void on_okButton_2_clicked();

private:
    Ui::AddNewUsertoMessageGroup *ui;
    int currentGroupID;
    QString username;
    User *u;
    void setBackground();
};

#endif // ADDNEWUSERTOMESSAGEGROUP_H
