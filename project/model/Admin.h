#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Group.h"
#include <algorithm>
/**
 * @brief The Admin class will serve as the class structure to represent an Admin for the system.
 */
class Admin: public User
{
private:
    int id;                 /*!< the unique id of the Administrator*/
    std::string username;   /*!< the username used to login cannot be changed*/
    std::string password;   /*!< the password used to login*/
    QSqlDatabase dataBase;
public:
    /**
     * @brief Admin The generic Admin constructor.
     */
    Admin();

    /**
     * @brief Admin The constructor for an Admin which requires basic details to create an account
     */
    Admin(QSqlDatabase db, std::string username, std::string password);

    /**
     * @brief create a new Group and store in the groupList
     */
    bool createNewBlogGroup(std::string groupName);

    /**
     * @brief createNewUser Method for the admin to create a new user
     * @param name the name of the new user
     * @param username the username of the new user
     * @param password the password of the new user
     * @return true if successful, false otherwise
     */
    bool createNewUser(std::string name, std::string username, std::string password);



};

#endif // ADMIN_H
