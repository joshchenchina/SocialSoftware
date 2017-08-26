#include <iostream>
#include "gtest/gtest.h"
#include "../model/User.h"
#include "../model/Command.h"
#include "../model/GroupHistory.h"
#include<string>


TEST(TEST1, USER){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("CS205_MONSTER_HUNTERS12");
    db.setDatabaseName("TestUser.sql");
    db.setUserName("ahmadw12");
    db.setPassword("password12");

    system( "sqlite3 TestUser.sql < ../../DropHarveyRanchDB.txt;");//drop the database tables
    system("sqlite3 TestUser.sql < ../../BuildHarveyRanchDB.txt;");//create the database tables with the admin already in
    system("sqlite3 TestUser.sql < ../../testDBInserts.txt");//add a set of values to the tables

    /*the test values from the tesDBInsert.txt

    INSERT into UserGroup VALUES(0,0);
    INSERT into UserGroup VALUES(0,1);
    INSERT into UserGroup VALUES(0,2);
    INSERT into UserGroup VALUES(1,3);
    INSERT into UserGroup VALUES(1,1);
    INSERT into UserGroup VALUES(0,3);

    INSERT into UserTable VALUES(1 , "Pfaffman, Jeff", "pfaffmaj", "newPassword");

    INSERT into UserTable(Name, Username, Password) VALUES ("Ahmad, Waseh", "ahmadw" , "password");
    INSERT into UserTable(Name, Username, Password) VALUES ("Lombardo, Craig", "lombardoc" , "password");
    INSERT into UserTable(Name, Username, Password) VALUES ("Chen, Yizhong ", "chenyi" , "password");

    INSERT into UserGroup VALUES(2,3);
    INSERT into UserGroup VALUES(3,3);
    INSERT into UserGroup VALUES(4,3);

    INSERT into GroupContentHistory (GroupId, UploadType, TimeStamp) VALUES(3, "Blog" , 201604152252);
    INSERT into GroupContentHistory (GroupId, UploadType, TimeStamp) VALUES(3, "Blog" , 201604152253);
    INSERT into GroupContentHistory (GroupId, UploadType, TimeStamp) VALUES(3, "Blog" , 201604152254);


    INSERT into BlogPostTable (ContentID, Content, UserID, Author) VALUES(1, "Hello from waseh", 2 , "Ahmad, Waseh");
    INSERT into BlogPostTable (ContentID, Content, UserID, Author) VALUES(2, "Hello from craig", 3 , "Lombardo, Craig");
    INSERT into BlogPostTable (ContentID, Content, UserID, Author) VALUES(3, "Hello from josh", 4 , "Chen, Yizhong");

    INSERT into UserUploadHistory (UserID, ContentID) VALUES(2,1);
    INSERT into UserUploadHistory (UserID, ContentID) VALUES(3,2);
    INSERT into UserUploadHistory (UserID, ContentID) VALUES(4,3);

    INSERT into CommentsBlogs (GroupID, ContentID_blog ,  TimeStamp ) VALUES (3, 2, 201604152256);
    INSERT into CommentsBlogs (GroupID, ContentID_blog ,  TimeStamp ) VALUES (3, 2, 201604152257);
    INSERT into CommentsBlogs (GroupID, ContentID_blog ,  TimeStamp ) VALUES (3, 2, 201604152258);

    INSERT into CommentsTable (ContentID , UserID , Content, Author ) VALUES (1, 2, "Comment1", "Ahmad, Waseh");
    INSERT into CommentsTable (ContentID , UserID , Content, Author ) VALUES (2, 3, "Comment2", "Lombardo, Craig");
    INSERT into CommentsTable (ContentID , UserID , Content, Author ) VALUES (3, 4, "Comment3", "Chen, Yizhong");



    INSERT into GroupTable VALUES(0,"MainGroup0",0, "Blog");
    INSERT into GroupTable VALUES(1,"MainGroup1",1, "Message");
    INSERT into GroupTable VALUES(2,"MainGroup2",0, "Blog");
    INSERT into GroupTable VALUES(3,"MainGroup3",0, "Blog");


    INSERT into GroupContentHistory(GroupID, UploadType, TimeStamp) VALUES(1, "Message", 20160415225612);
    INSERT into GroupContentHistory(GroupID, UploadType, TimeStamp) VALUES(1, "Message", 20160415225613);
    INSERT into GroupContentHistory(GroupID, UploadType, TimeStamp) VALUES(1, "Message", 20160415225614);
    INSERT into GroupContentHistory(GroupID, UploadType, TimeStamp) VALUES(1, "Message", 20160415225615);

    INSERT into MessageTable(ContentID, MessageContent, Author) VALUES(4, "Testing message 1", "pfaffmaj");
    INSERT into MessageTable(ContentID, MessageContent, Author) VALUES(5, "Testing message 2", "admin");
    INSERT into MessageTable(ContentID, MessageContent, Author) VALUES(6, "Testing message 3", "pfaffmaj");
    INSERT into MessageTable(ContentID, MessageContent, Author) VALUES(7, "Testing message 4", "admin");

    */


    QSqlDatabase * datab = &db;

    Group::dataBase = *datab;
    Command::dataBase= *datab;

    User * user0 = new User(*datab,"pfaffmaj", "newPassword");

    ASSERT_TRUE(user0->getFullName()== "Pfaffman, Jeff");

    user0->createMessageGroup("TestUserMessageGroup");

    ASSERT_TRUE(user0->isModerator(1))<<"The user is not the moderator";
    ASSERT_TRUE(user0->isModerator(4))<<"The user is not the moderator";

    std::vector<std::tuple<int,std::string>> userList = Group::getUsers(4);
    ASSERT_TRUE(userList.size()==1);

    user0->addUsers(4,"ahmadw");
    user0->addUsers(4,"chenyi");
    user0->addUsers(4,"lombardoc");

    userList = Group::getUsers(4);
    ASSERT_TRUE(userList.size()==4);

    user0->leaveGroup(4);//moderator leaves, the whole group is deleted

    userList = Group::getUsers(4);
    ASSERT_TRUE(userList.size()==0);

    std::cout<<"----------------------------------------------"<<std::endl;

    int id = user0->writeContent(3,"Blog","Testing Blog from the unittest , wrriten by pfaffmaj");

    ASSERT_EQ(id,8)<<"The id of the content was not the one specified";

    //first assert that the password isnt the new one
    std::string oldPass = user0->getPassword();
    ASSERT_TRUE("PasswordNEW" != oldPass);

    //change it
    user0->setPassword("PasswordNEW");

    ASSERT_FALSE(std::get<0>(Command::loginVerification(user0->getUsername(),oldPass)));
    ASSERT_TRUE(std::get<0>(Command::loginVerification(user0->getUsername(),"PasswordNEW")));

    std::cout<<"----------------------------------------------"<<std::endl;

    user0->createMessageGroup("Testing2User");
    user0->addUsers(4,"ahmadw");
    user0->addUsers(4,"chenyi");
    user0->addUsers(4,"lombardoc");

    userList = Group::getUsers(4);

    User* user1 = new User(*datab,"ahmadw","password");

    ASSERT_FALSE(user1->isModerator(4));
    ASSERT_TRUE(userList.size()==4);
    ASSERT_TRUE(user1->leaveGroup(4));
    userList = Group::getUsers(4);

    ASSERT_TRUE(userList.size()==3);


    std::cout<<"----------------------------------------------"<<std::endl;

    int newBlogID = user0->writeContent(3,"Blog","This is a test blog to test for comments");
    user0->writeComment(3,newBlogID,"This is the 1st test comment");
    user1->writeComment(3,newBlogID,"This is the 2nd test comment by a different user");
    user0->writeComment(3,newBlogID,"This is the 3rd test comment");
    user1->writeComment(3,newBlogID,"This is the 4th test comment by a different user");

    std::cout<<"-------------------------------------------------"<<std::endl;



    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);

    QSqlDatabase::database().removeDatabase("default");
}
