#ifndef POSTVIEWER_H
#define POSTVIEWER_H

#include "Screen.h"
#include "CommentViewer.h"
#include "../model/Group.h"

class PostViewer : public Screen
{
private:
    std::vector<std::tuple<int, std::string, std::string, std::string>> blogPostList; /*!< An array associated with the messages of the User*/
    std::vector<std::tuple<int,std::string>> groupList; /*!< An array associated with the groups of the User*/

    /**
     * @brief populateBlogPosts This method gets all of the posts of the active group
     */
    void populateBlogPosts();

    /**
     * @brief populateGroups This method gets the list of groups the User has
     */
    void populateGroups();

    /**
     * @brief display This method displays the content the User can interact with
     */
    void display();

    int selectedBlogPost; /*!< Indicates which option is selected*/
    int selectedGroup; /*!< The group the User was last hovering over*/
    int activeGroup; /*!< The group the User is viewing posts on*/
    bool inMessages; /*!< Whether the User is in the Message pane or the conversation pane*/

    std::string currentAuthor; /*!< The author of the post that is currently present*/

    int offset; /*!< Vertical buffer between 2 messages*/
    int options; /*!< The number of options to select*/
    static int maxMessageWidth; /*!< Max message display width*/

    /**
     * @brief checkGroupHeights This method checks that the screen is filled while scrolling
     * @param current The current index in the content vector
     * @param yStart The starting position of the pane
     * @param height The maximum height of the pane
     * @param content The content that will be displayed
     * @return bool - whether or not the screen is filled with the content
     */
    bool checkGroupHeights(int current, int yStart, int height, std::vector<std::tuple<int,std::string>> *content);

    /**
     * @brief deleteComment This method deletes a User's comment if it was their own. This does not return a boolean as
     * proper actions are taken accordingly within the method
     */
    void deleteComment();

    /**
     * @brief printPanels This method prints the different panels to the screen
     */
    void printPanels();

    /**
     * @brief printMessagePanel This method prints the Messages to the screen
     * @param startY The lowest Y position to be printed
     * @param content A vector with the messages to be printed
     */
    void printMessagePanel(int startY, std::vector<std::tuple<int, std::string, std::string, std::string>> *content);

    /**
     * @brief printConversationPanel This method prints the list of groups the User has to the screen
     * @param width The width of the pane
     * @param content A vector with the messages to be printed
     */
    void printConversationPanel(int width, std::vector<std::tuple<int,std::string>> *content);

    /**
     * @brief parseTimeStamp This method takes a raw timestamp and makes it more aesthetically pleasing
     * @param timestamp The raw timestamp
     * @return The more aestheticall pleasing representation
     */
    std::string parseTimeStamp(std::string timestamp);

    /**
     * @brief getHelp This method brings up a help screen.
     */
    void getHelp();

    QSqlDatabase *myDB; /*!< The database that is used in the app*/
    User* myUser; /*!< The User that is logged in*/

public:
    /**
     * @brief PostViewer The basic constructor for an instance of PostViewer. Note, calling this will do nothing.
     */
    PostViewer();

    /**
     * @brief PostViewer This is the constructor for a usable PostViewer
     * @param u The User that is logged in
     * @param db The database being used by the app
     */
    PostViewer(User *u, QSqlDatabase *db);
};

#endif // POSTVIEWER_H
