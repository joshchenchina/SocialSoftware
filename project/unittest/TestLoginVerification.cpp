#include <iostream>
#include <stddef.h>
#include "gtest/gtest.h"
#include "../model/Command.h"
#include<string>
#include <QCoreApplication>
#include <QtSql>



TEST(TEST1, COMMAND){

    system( "sqlite3 TestCommand.sql < ../../DropHarveyRanchDB.txt");//drop the database tables
    system("sqlite3 TestCommand.sql < ../../BuildHarveyRanchDB.txt");//create the database tables with the admin already in

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("CS205_MONSTER_HUNTERS");
    db.setDatabaseName("TestCommand.sql");
    db.setUserName("ahmadw");
    db.setPassword("password");

    QSqlDatabase * datab = &db;


    Command::dataBase = *datab;

    bool ok = db.open();

    if(ok){


        QSqlQuery query1(QString::fromStdString("INSERT into UserTable(Name, Username, Password)"
                                                " VALUES('testName1', 'testUserName', 'testPass')"));

        db.close();
    }

    //testing if it can test if
    ASSERT_FALSE(std::get<0>(Command::loginVerification("sasdasdsd", "dsa2sdsad")));
    ASSERT_FALSE(std::get<0>(Command::loginVerification("testUserName", "dasda123e21;or")));
    ASSERT_FALSE(std::get<0>(Command::loginVerification("123adcaslke", "testPass")));
    ASSERT_TRUE(std::get<0>(Command::loginVerification("testUserName", "testPass")));//proper username and password user exists
    ASSERT_FALSE(std::get<1>(Command::loginVerification("testUserName", "testPass")));//still not admin though


    ASSERT_FALSE(std::get<0>(Command::loginVerification("admin", "dsa2sdsad")));
    ASSERT_FALSE(std::get<0>(Command::loginVerification("2321sasa", "adminPass")));
    ASSERT_TRUE(std::get<0>(Command::loginVerification("admin", "adminPass"))); //admin is a user which exists
    ASSERT_TRUE(std::get<1>(Command::loginVerification("admin", "adminPass")));//admin is an 'admin' of the program





    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
    QSqlDatabase::database().removeDatabase("default");





}
