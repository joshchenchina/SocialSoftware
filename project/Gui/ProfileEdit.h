#ifndef PROFILEEDIT_H
#define PROFILEEDIT_H

#include <QWidget>
#include <QString>
#include <QMainWindow>

#include <QApplication>
#include <QCoreApplication>
#include <QtSql>
#include "mainwindow.h"
#include "../model/User.h"

namespace Ui {
class ProfileEdit;
}

class ProfileEdit : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProfileEdit(QWidget *parent = 0, User* u = NULL);
    ~ProfileEdit();

private slots:
    /**
     * @brief Change username
     */
    void on_changeName_clicked();

    /**
     * @brief Change password
     */
    void on_changePassword_clicked();

    /**
     * @brief Return to the previous screen
     */
    void on_pushButton_3_clicked();

private:
    Ui::ProfileEdit *ui;
    User* user;
    void setBackground();
};

#endif // PROFILEEDIT_H
