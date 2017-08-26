#ifndef GROUP_H
#define GROUP_H

#include<stddef.h>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<tuple>
#include "User.h"

#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>


/**
 * @brief The Group class serves as a container for a culmination of Users to interact.
 */
class Group
{
public:

    static QSqlDatabase dataBase;

    /**
     * @brief getUsers returns the list of user IDs in the group
     * @return a vector of tuples containing the user ids and their username.
     */
    static std::vector<std::tuple<int,std::string>> getUsers(int groupID);


    /**
     * @brief getGroups method to get the group names and ids of the groups of a user of a particular type
     * @param groupType The tpe of group as a sring i.e. Blog, Message
     * @param userID the id of the user currently logged in
     * @return a vector of tuples of the id of the group and its name
     */
    static std::vector<std::tuple<int,std::string>> getGroups(std::string groupType, int userID);

    /**
     * @brief getGroupMessages get the messages of a message group
     * @param groupID the id of the message group
     * @return a vector of tuples which contains , the content,the name of the author, the timestamp
     */
    static std::vector<std::tuple<std::string, std::string, std::string>> getGroupMessages(int groupID);


    /**
     * @brief getBlogPosts get the list of blog posts of a group
     * @param groupID the id of the group being viewed
     * @return a vector of tuples which contains for each post the id of that post, the timestamp, the content and the author
     */
    static std::vector<std::tuple<int, std::string, std::string, std::string>> getBlogPosts(int groupID);

    /**
     * @brief getBlogComments method to get the comments associated with a blog post
     * @param groupID the id of the blog group
     * @param blogID the contentID of the blog
     * @return  a vecotr of tuples which contains for each tuple the id of the comment, the content, the author, and the timestamp
     */
    static std::vector<std::tuple<int, std::string, std::string, std::string>> getBlogComments(int groupID, int blogID);


    /**
     * @brief viewAllBlogGroups method to get all the groups that are of type blog
     * @return a vector of tuples each tu[ple made up of the id and name of a group.
     */
    static std::vector<std::tuple<int,std::string>> viewAllBlogGroups();

    /**
     * @brief viewUserUploads Method to get all the blog posts and tweets of a user
     * @param username the username of the user being searche dfor
     * @return a vector of tuples each of which contain the timestamp of the post and the content of the post
     */
    static std::vector<std::tuple<std::string, std::string> > viewUserUploads(std::string username);


    /**
     * @brief isMedia method to get the media path if its a media content
     * @param contentID the contentid in the db
     * @return  a tuple of a bool and string, bool = true if media file and string == associated content
     */
    static std::tuple<bool,std::string> isMedia(int contentID);

    //author,timesamp,content, path
    /**
     * @brief getAllPosts method to get all media and blog posts
     * @return  a vector of tuples each containing the author, the timestamp, the content and the path if valid
     */
    static std::vector<std::tuple<std::string,std::string,std::string,std::string>> getAllPosts();


    /**
     * @brief getMediaPosts get the list of media posts of a group
     * @param groupID the id of the group being viewed
     * @return a vector of tuples which contains for each post the id of that post, the timestamp, the content and the author filePath
     */
    static std::vector<std::tuple<int, std::string, std::string, std::string, std::string>> getMediaPosts(int groupID);

    static void setDatabase();





};

#endif // GROUP_H
