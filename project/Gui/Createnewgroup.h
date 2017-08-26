#ifndef CREATENEWGROUP_H
#define CREATENEWGROUP_H

#include <QMainWindow>
#include "../model/User.h"

namespace Ui {
class CreateNewGroup;
}

class CreateNewGroup : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateNewGroup(QWidget *parent = 0, User* user = NULL, int id = -1);
    ~CreateNewGroup();

private slots:
    /**
     * @brief Create a new message group
     */
    void on_OKButton_clicked();

    /**
     * @brief Return to message screen
     */
    void on_CancelButton_clicked();

private:
    Ui::CreateNewGroup *ui;
    User* user;
    int groupID = 0;
    QString groupname;
    void setBackground();
};

#endif // CREATENEWGROUP_H
