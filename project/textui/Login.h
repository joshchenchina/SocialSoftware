#ifndef LOGIN_H
#define LOGIN_H

#include "../model/Group.h"
#include "../model/User.h"
#include "Screen.h"
#include "MainMenu.h"

/**
 * @brief The Login class serves as the first screen users see and allows/denies Users.
 */
class Login : public Screen
{
private:

    static int maxUserLength; /*!< Max username character length*/
    static int maxPassLength; /*!< Max password character length*/

    /**
     * @brief display This method displays the content on the screen.
     */
    void display();

    /**
     * @brief getInput Gets input from the user
     * @param hasAttempted Indicates whether or not the user has already made a log in attempt
     * @param user Indicates whether or not they are trying to type in the username or password
     * @param username The username to display, only visible if they have entered one in already
     * @return The content the user has typed
     */
    std::string getInput(bool hasAttempted, bool user, std::string username);

    /**
     * @brief checkCredentials Checks whether or not the entered information matches the information
     * in the database
     * @param username The username the User entered
     * @param password The password the User entered
     * @return bool - whether or not the credentials passed
     */
    bool checkCredentials(std::string username, std::string password);

    /**
     * @brief advance This method creates an instance of the main menu screen
     */
    void advance();

    MainMenu * main; /*!< A pointer referring to the MainMenu that was created*/

    /**
     * @brief getHelp This method pulls up a help screen
     */
    void getHelp();

    QSqlDatabase *myDB; /*!< A pointer to the database in use*/
    User* myUser; /*!< The User that has logged in, when they have done so successfully*/

public:
    /**
     * @brief Login The basic constructor for creating an instance of a Login Screen. Note that
     * calling this will do nothing.
     */
    Login();

    /**
     * @brief Login The constructor for creating a usable instance of a Login Sreen.
     * @param db The database that will be used throughout the app.
     */
    Login(QSqlDatabase* db);
};

#endif // LOGIN_H
