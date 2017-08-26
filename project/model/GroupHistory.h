#ifndef GROUPHISTORY_H
#define GROUPHISTORY_H

#include<stddef.h>
#include<string>
#include<iostream>
#include<fstream>
#include"Group.h"
#include "User.h"

#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>
#include<stddef.h>

class Group;
/**
 * @brief The GroupHistory class will serve as a way to track all of the history of a group.
 */
class GroupHistory
{
private:
    std::vector<int> groupIDs;
    QSqlDatabase dataBase;
    int gHistID;

public:
    /**
     * @brief GroupHistory The generic constructor for a groups history.
     */
    GroupHistory();

    /**
     * @brief GroupHistory the constructor which will take in an id from the user
     * @param id the id of the user
     */
    GroupHistory(int id);

    /**
     * @brief GroupHistory Constructor to create using a database
     * @param id the id of the user
     * @param db the database being used
     */
    GroupHistory(int id, QSqlDatabase db);

    /**
     * @brief viewGroups gives a list of all the id's of groups the user is currently a part of
     * @return a vector of all the ids of the groups the user is a member of
     */
    std::vector<int> viewGroups();

    /**
     * @brief updateListOfGroups updates the vector stored in the group history of the ids of groups the user is a part of
     */
    void updateListOfGroups();


    ~GroupHistory();

    int getGHistID();

};

#endif // GROUPHISTORY_H
