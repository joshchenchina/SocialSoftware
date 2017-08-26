#include <iostream>
#include <stddef.h>

//#include "curses.h"
#include "Login.h"

#ifndef WRAPPED_NCURSES_H
#define WRAPPED_NCURSES_H

#include <ncurses.h>
namespace hiddenncurses {
}
#endif


int main(int argc, char *argv[])
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("CS205_MONSTER_HUNTERS");
    db.setDatabaseName("/auto/bunter_usr11/cs205_2016_Grp00/database_HarveyRanch/HarveyRanchFinalDB.sql");//"/auto/bunter_usr11/cs205_2016_Grp00/database_HarveyRanch/HarveyRanchFinalDB.sql");
    db.setUserName("ahmadw");
    db.setPassword("password");

    Group::dataBase = db;
    Command::dataBase = db;

    Login* login = new Login(&db);

    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
    QSqlDatabase::database().removeDatabase("default");

    return 0;
}
