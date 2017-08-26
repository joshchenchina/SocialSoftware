#ifndef CREATEUSER_H
#define CREATEUSER_H

#include <QMainWindow>
#include "../model/User.h"
#include "../model/Admin.h"

namespace Ui {
class CreateUser;
}

class CreateUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateUser(QWidget *parent = 0, Admin* a = NULL);
    ~CreateUser();

private slots:
    /**
     * @brief Return to AdminMainMenu
     */
    void on_cancel_clicked();

    /**
     * @brief Create a new user
     */
    void on_OK_clicked();

private:
    Ui::CreateUser *ui;
    Admin* admin;
    void setBackground();

};

#endif // CREATEUSER_H
