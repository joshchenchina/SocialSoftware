#ifndef MESSAGING_H
#define MESSAGING_H

#include "../model/User.h"
#include "../model/Group.h"
#include "Screen.h"

#include <thread>

class Messaging : public Screen
{
private:
    //content, author, timestamp
    std::vector<std::tuple<std::string, std::string, std::string>> messageList; /*!< An array associated with the messages of the User*/
    //id, groupname
    std::vector<std::tuple<int,std::string>> groupList; /*!< An array associated with the groups of the User*/

    std::string myMessage; /*!< The message the User is typing to send*/

    /**
     * @brief populateMessages This method populates the User's messages
     * @param id The Group ID
     */
    void populateMessages(int id);

    /**
     * @brief populateGroups This method populates a list of groups the User is a part of
     */
    void populateGroups();

    /**
     * @brief display Initializes the display actions
     */
    void display();

    int selectedMessage; /*!< Indicates which message is selected*/
    int selectedGroup; /*!< Indicates which group the cursor is on*/
    int activeGroup; /*!< Indicates which group the User is in*/
    bool inConvo; /*!< Indicates whether the User is scrolling through messages or groups*/
    bool switchedGroups; /*!< Indicates whether or not the User switched into a new group or if entering the same group*/

    int offset; /*!< Vertical buffer between 2 messages*/

    static int maxMessageWidth; /*!< Max message display width*/
    static int conversationPanelWidth; /*!< Conversation panel display width*/
    static int maxMessageLength; /*!< Max character length*/

    /**
     * @brief checkMessageHeights This method determines whether or not the messages will fill the entire screen
     * @param current The current message in the vector
     * @param yStart The initial starting point, also the lowest.
     * @param content The content to traverse through that will be printed.
     * @return bool - indicating whether there will be enough messages to fill the screen, allowing it to either
     * shift up or scroll
     */
    bool checkMessageHeights(int current, int yStart, std::vector<std::tuple<std::string, std::string, std::string> > *content);

    /**
     * @brief checkGroupHeights This method determines whether or not the groups will fill the entire screen
     * @param current The current group in the vector
     * @param yStart The initial starting point, also the lowest.
     * @param content The content to traverse through that will be printed.
     * @return bool - indicating whether there will be enough groups to fill the screen, allowing it to either
     * shift up or scroll
     */
    bool checkGroupHeights(int current, int yStart, int height, std::vector<std::tuple<int,std::string>> *content);

    /**
     * @brief printPanels This method prints the messaging and conversation panels
     */
    void printPanels();

    /**
     * @brief printMessagePanel This method prints the message panel to the screen
     * @param startY The lowest point to print from.
     * @param content A vector of the messages to print to the screen.
     */
    void printMessagePanel(int startY, std::vector<std::tuple<std::string, std::string, std::string>> *content);

    /**
     * @brief printConversationPanel This method prints the group conversation panel to the screen.
     * @param width The width of the panel
     * @param content A vector of the groups to print to the screen.
     */
    void printConversationPanel(int width, std::vector<std::tuple<int,std::string>> *content);

    /**
     * @brief getHelp This method pulls up a HelpScreen.
     */
    void getHelp();

    QSqlDatabase *myDB; /*!< The database to be used by the app*/
    User* myUser; /*!< The User that has logged into the system*/

    bool updateMe;/*!< Indicates whether or not the app should pull a new copy of the database*/

    /**
     * @brief startTimer This method creates and starts a new thread which will continually count in the background
     * @param m The app that is running/calling the custom timer.
     */
    static void startTimer(Messaging *m);

    /**
     * @brief parseTimeStamp This method takes a raw timestamp string and makes it a little bit more aesthetically pleasing.
     * @param timestamp The raw timestamp
     * @return std::string - The more aesthetically pleasing version of the timestamp
     */
    std::string parseTimeStamp(std::string timestamp);

public:
    /**
     * @brief Messaging The basic constructor for an instance of the Messaging class. Note, calling this will do nothing
     */
    Messaging();

    /**
     * @brief Messaging Th constructor for a usable Messaging class.
     * @param u The logged in User
     * @param db The database the app is using.
     */
    Messaging(User *u, QSqlDatabase *db);

    /**
     * @brief reloadMessenger This method reloads the messenger as if it was loaded up the first time
     */
    void reloadMessenger();

    /**
     * @brief getUpdateMe This method returns whether or not the app has refreshed itself
     * @return bool - true if app has just updated itself
     */
    bool getUpdateMe();

    /**
     * @brief setUpdateMe This method sets the messaging apps update boolean
     * @param set What to set the update boolean to.
     */
    void setUpdateMe(bool set);
};

#endif // MESSAGING_H
