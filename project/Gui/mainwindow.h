#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QString>
#include <QMainWindow>
#include "Homepage.h"
#include "AdminMainMenu.h"

#include "../model/User.h"
#include "../model/Admin.h"
#include "../model/Command.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString username;
    static QSqlDatabase database;

private slots:
    /**
     * @brief Quit the Program
     */
    void on_QuitButton_clicked();

    /**
     * @brief Sign in as a User or an Admin
     */
    void on_SignInButton_clicked();

private:
    Ui::MainWindow *ui;
    QMainWindow * subscreen = NULL;
    QString password;
    void setBackground();

};

#endif // MAINWINDOW_H
