#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include<stddef.h>
#include<string>
#include<fstream>
#include<vector>
#include<tuple>
#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>

class Command
{
public:

    static QSqlDatabase dataBase;

    /**
     * @brief loginVerification method to find whether the user exists and if it is an admin or user
     * @param username the username entered by the person
     * @param password the password entered by the person
     * @return a tuple of two booleans, the first of which represents if the person exists and the second if the person is an admin
     */
    static std::tuple<bool, bool> loginVerification(std::string username, std::string password);

    /**
     * @brief nameOfUser method to get the name of the user provided the unsername
     * @param username the username of the user
     * @return the name of the user
     */
    static std::string nameOfUser(std::string username);

    /**
     * @brief exists method to see if a user exists
     * @param username the claimed username of a user being tested
     * @return true if exists, false otherwise
     */
    static bool exists(std::string username);


};
#endif // COMMAND_H
