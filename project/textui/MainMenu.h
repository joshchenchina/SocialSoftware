#ifndef MAINMENU_H
#define MAINMENU_H

#include "../model/Website.h"
#include "../model/User.h"
#include "Screen.h"
#include "Messaging.h"
#include "PostCreator.h"
#include "PostViewer.h"

/**
 * @brief The MainMenu class serves as a selection pane for the overall TUI.
 */
class MainMenu : public Screen
{
private:

    /**
     * @brief display This function displays the options to the screen
     */
    void display();

    int selected; /*!< The selected option on the screen*/
    std::vector<std::string> options; /*!< The list of options*/
    Messaging * message; /*!< A pointer to a new Messaging Screen*/
    PostCreator * newPost; /*!< A pointer to a new PostCreator Screen*/
    PostViewer * viewPost; /*!< A pointer to a new PostViewer Screen*/

    /**
     * @brief processChoice This function takes the selection made and acts accordingly
     * @param selection The selection made
     */
    void processChoice(int selection);

    /**
     * @brief getHelp This method pulls up the help screen
     */
    void getHelp();

    QSqlDatabase *myDB; /*!< A pointer to the Database being used*/
    User* myUser; /*!< The User that is logged in*/

public:
    /**
     * @brief MainMenu The basic constructor for the MainMenu. Note calling this will
     * not do anything.
     */
    MainMenu();

    /**
     * @brief MainMenu The constructor for a usable instance of MainMenu.
     * @param u The currently signed in User
     * @param db The database being used in the app
     */
    MainMenu(User *u, QSqlDatabase* db);
};

#endif //MAINMENU_H
