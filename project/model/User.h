#ifndef USER_H
#define USER_H

#include<stddef.h>
#include<string>
#include<iostream>
#include<fstream>

#include "Upload.h"
#include "GroupHistory.h"

#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>
#include<stddef.h>


class GroupHistory;
/**
 * @brief The User class will serve as a generic User class.
 */
class User
{

protected:
    std::string name;       /*!< the full name of the user stored as [last name], [first, name]*/
    std::string username;   /*!< the username used to login cannot be changed*/
    std::string password;   /*!< the password used to login*/
    int id;                 /*!< the unique id of the user*/
    bool isAdmin;           /*!< boolean indicating whether the user is an admin or not*/

    GroupHistory* gHist;    /*!< group history object to store all of the groups the user is a part of*/
    QSqlDatabase dataBase;

public:
    static int id_cnt;      /*!< static id counter */


    /**
     * @brief User The generic constructor for a User
     */
    User();

    User(QSqlDatabase db, std::string username, std::string password);

    /**
     * @brief User The constructor for a user which requires basic details to create an account
     */
    User(std::string password,std::string username, std::string name);

    /**
     * @brief The destructor for the user
     */
    ~User();

    /**
     * @brief Method to create a group
     * @param groupName the name of the group
     * @return true if created, false otherwise
     */
    bool createMessageGroup(std::string groupName);

    /**
     * @brief Method to delete the group if youre the moderator
     * @param groupID the id of the group being deleted
     * @return true if the group is successfully deleted
     */
    bool deleteGroup(int groupID);


    /**
     * @brief method to delete a group for which the user is a moderator
     * @param groupID the id of the group to leave from
     * @return  true if deleted, false otherwise
     */
    bool leaveGroup(int groupID);


    /**
     * @brief writeContent method to write content to the database
     * @param groupID the id of the group being written to
     * @param uploadType the type of content 'Blog' , 'Message' or 'Media'
     * @param content the actual content in string format
     * @param extension the extension of the file
     * @return the contentID
     */
    int writeContent(int groupID, std::string uploadType, std::string content= "", std::string extension ="");

    /**
     * @brief writeComment method to write a comment to a blog and store it in the database
     * @param groupID the id of the group which contais the blog
     * @param blogPostID the id of the blog being commented on
     * @param comment the actual comment written
     */
    void writeComment(int groupID, int blogPostID, std::string comment);


    /**
     * @brief addUsers method to add users one at a time to a group
     * @param groupID the id of the group being added to
     * @param username the username of the user being added
     * @return true if successful, false if user not found
     */
    virtual bool addUsers(int groupID,std::string username);

    /**
     * @brief isModerator method to check if the user is the moderator of the group
     * @param groupID the id of the group needed to be checked
     * @return true if the user is the moderator of the group false otherwise
     */
    bool isModerator(int groupID);

    /**
     * @brief isAuthor method to check if the user is the author of a  content
     * @param blogPostID the id of the blog post
     * @param commentID the id of the comment if its being checked, if not, its given a default value of -1
     * @return true if the user is the author, false otherwise
     */
    bool isAuthor(int blogPostID, int commentID=-1 );

    /**
     * @brief deleteBlogPost method to delete a blog pos that the user is an author of
     * @param postType the tpe of post 'Blog' or 'Media'
     * @param contentID the id of the content to be deleted
     * @return true if successfully deleted.
     */
    bool deleteBlogPost(std::string postType, int contentID);

    /**
     * @brief deleteComment the method to delete a comment made by the user
     * @param commentID the id of the comment to be deleted
     * @return true if successful, false otherwise
     */
    bool deleteComment(int commentID);

    /**
     * @brief cTimeStamp method to get a timestamp for current time
     * @return concatanated long of [Year][Month][day][Hour][Min][Sec]
     */
    long cTimeStamp();



    /**
     * @brief setName method to set the name of th user
     * @param name the name of the user in [last name], [first, name] format
     */
    void setName(std::string name);

    /**
     * @brief setPassword method to set the password of th user
     * @param password the password set by the user
     */
    void setPassword(std::string password);

    /**
     * @brief obtains the password set by the user
     * @return user password as a string
     */
    std::string getPassword();

    /**
     * @brief getFullName
     * @return the full name of the user in [last name], [first, name] format
     */
    std::string getFullName();

    /**
     * @brief getFirstName
     * @return the first name of the user
     */
    std::string getFirstName();

    /**
     * @brief getLastName
     * @return the last name of the user
     */
    std::string getLastName();

    /**
     * @brief getUsername
     * @return the username of the user (unique username)
     */
    std::string getUsername();

    /**
     * @brief getIsAdmin
     * @return true if user is admin, false otherwise
     */
    bool getIsAdmin();

    /**
     * @brief getID
     * @return the unique id of the user
     */
    int getID();

    /**
     * @brief getGHist This method returns the User's GroupHistory
     * @return The GroupHistory associated with the User
     */
    GroupHistory* getGHist();



};

#endif // USER_H
