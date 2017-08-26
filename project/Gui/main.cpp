#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QtSql>

#include "../model/Group.h"
#include "../model/User.h"
#include "../model/Admin.h"
#include "../model/Command.h"
#include "../model/GroupHistory.h"

int main(int argc, char *argv[])
{
    QApplication *a = new QApplication(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("CS205_MONSTER_HUNTERS");
    db.setDatabaseName("/Users/yizhongchen/Desktop/205_working_copy/HarveyRanchFinalDB.sql");
    db.setUserName("ahmadw");
    db.setPassword("password");

    Group::dataBase = db;//set the group database as db
    Command::dataBase = db;
    MainWindow::database = db; //for all the times you log out
    //create the main window

    MainWindow * mainMenu = new MainWindow();
    mainMenu->show();

    return a->exec();
}
