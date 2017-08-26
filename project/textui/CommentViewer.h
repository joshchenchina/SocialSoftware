#ifndef COMMENTVIEWER_H
#define COMMENTVIEWER_H

#include "Screen.h"
#include "../model/User.h"
#include "../model/Group.h"

/**
 * @brief The CommentViewer class will serve as the means for viewing comments on a specific blog post.
 */
class CommentViewer : public Screen
{
private:

    static int maxMessageWidth; /*!< The maximum screen width of a message*/
    static int maxMessageLength; /*!< The maximum number of characters in a message*/

    std::vector<std::tuple<int, std::string, std::string, std::string>> myComments; /*!< An array associated with the comments on a particular post*/

    std::string myMessage; /*!< The comment being typed by the User*/
    std::string headerInfo; /*!< The information about the given blog post*/

    void display(); /*!< Initializes the display actions*/
    int selectedMessage; /*!< Indicates which option is selected*/

    int offset; /*!< Buffer between 2 messages*/
    int myGroupID; /*!< The ID of the specific group the User is viewing*/
    int myMessageID; /*!< The ID of the specific message the User is viewing*/

    /**
     * @brief printCommentPanel This method prints the comments on a specific post
     * @param startY The lowest Y value on the screen
     * @param content An array of tuples as specified by the database
     */
    void printCommentPanel(int startY, std::vector<std::tuple<int, std::string, std::string, std::string>> *content);

    /**
     * @brief parseTimeStamp This method converts a string timestamp into a more aesthetically appealing view.
     * @param timestamp The timestamp in raw string form
     * @return
     */
    std::string parseTimeStamp(std::string timestamp);

    /**
     * @brief checkMessageHeights This method checks that the screen will be filled before proceeding to scroll
     * @param current The current position on the screen
     * @param yStart The starting y position on the screen
     * @param content An array of tuples as specified in the database
     * @return bool - corresponds to whether or not the content fills the screen and can be shifted
     */
    bool checkMessageHeights(int current, int yStart, std::vector<std::tuple<int, std::string, std::string, std::string>>* content);

    /**
     * @brief refreshCommentList This method pulls a new version of the Comment list
     */
    void refreshCommentList();

    /**
     * @brief getHelp This pulls up a HelpScreen
     */
    void getHelp();

    User* myUser; /*!< The User that is viewing/writing a comment*/

    /**
     * @brief deletePost Deletes a comment from the comment list/ from the database. There is not boolean return as
     * things are checked within the method and appropriate actions are handled accordingly
     */
    void deletePost();

public:
    /**
     * @brief CommentViewer The basic constructor for a CommentViewer. Note calling this will not do anything.
     */
    CommentViewer();

    /**
     * @brief CommentViewer The constructor to be used for creating a usable and flexible CommentViewer instance.
     * @param groupID The ID of the group the User is viewing.
     * @param messageID The ID of the comment the User is viewing
     * @param oh The header information of the post
     * @param mc A list of the current comments on the post
     * @param u The current User
     */
    CommentViewer(int groupID, int messageID, std::string oh, std::vector<std::tuple<int, std::string, std::string, std::string>> mc, User* u);
};

#endif // COMMENTVIEWER_H
