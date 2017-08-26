#ifndef POSTCREATOR_H
#define POSTCREATOR_H

#include "../model/User.h"
#include "../model/Group.h"
#include "Screen.h"
#include <unistd.h>

class PostCreator : public Screen
{
private:

    /**
     * @brief getContent This method returns the content typed in the message field
     * @return std::string - corresponding to the typed content
     */
    std::string getContent();

    /**
     * @brief getLink This message gets the link typed in the link field
     * @param content The content initially typed in the message field, to be displayed
     * @param attemptedLink A string that they attempted should the first one fail
     * @return std::string - corresponding to the typed link
     */
    std::string getLink(std::string content, std::string attemptedLink);

    int type; /*!< The type of post to be created*/
    int myMax; /*!< The maximum content size for the given post*/
    static int xStart; /*!< Starting position of the content*/
    static int maxContentWidth; /*!< Max message display width*/
    static int maxTweetLength; /*!< The maximum number of characters in a tweet*/
    static int maxBlogLength; /*!< The maximum number of characters in a blog*/
    static int offset; /*!< The vertical buffer between content*/

    int selectedGroup; /*!< The Group the User is writing their message to*/

    /**
     * @brief getHelp This method pulls up a HelpScreen and is overloading the method from Screen
     */
    void getHelp();

    QSqlDatabase *myDB;/*!< The database to be used in the app.*/

    /**
     * @brief printConversationPanel This method prints the group panel
     * @param width The width of the panel itself
     * @param content A list of the groups the User can select from
     */
    void printConversationPanel(int width, std::vector<std::tuple<int,std::string>> *content);

    /**
     * @brief checkGroupHeights This method checks that the content can scroll and still fill the screen
     * @param current The current index in the content
     * @param yStart THe starting position vertically and the highest point
     * @param height The height of the message panel
     * @param content The vector corresponding to the list of groups the user is a part of
     * @return bool - whether or not the screen can be filled
     */
    bool checkGroupHeights(int current, int yStart, int height, std::vector<std::tuple<int,std::string>> *content);

    std::vector<std::tuple<int,std::string>> groupList; /*!< An array associated with the groups of the User*/

    bool canComment; /*!< A boolean corresponding to whether or not the User can comment, based on whether or not they
have selected the group they want to write to*/

    /**
     * @brief getGroup This method gets information for either the blog post or tweet post
     * @param blog A boolean corresponding to whether the message is a blog or not
     * @return bool - true if something was written, false if quitting
     */
    bool getGroup(bool blog);

    /**
     * @brief checkMedia This method checks whether or not the path was to a valid file
     * @param mediaPath The path to check
     * @return bool - true if exists, false if not
     */
    bool checkMedia(std::string mediaPath);

    /**
     * @brief getExtension This method extracts the extension of the file for storage in the database
     * @param mediaPath The path to grab the extension from
     * @return The extension of the media path
     */
    std::string getExtension(std::string mediaPath);

    /**
     * @brief checkFullPath This method checks if there is a '~' used rather than the full path
     * @param input The media path to check
     * @return A full path string
     */
    std::string checkFullPath(std::string input);

public:
    /**
     * @brief PostCreator The basic PostCreator constructor. Note, calling this will not do anything.
     */
    PostCreator();

    /**
     * @brief PostCreator This constructor is used for a usable instance of PostCreator
     * @param blogPost Whether or not this is a blog post or tweet post
     * @param u The User who is writing the post
     * @param db The database to be used in the app.
     */
    PostCreator(bool blogPost, User* u, QSqlDatabase *db);
};

#endif // POSTCREATOR_H
