#include <iostream>
#include <stddef.h>
#include "gtest/gtest.h"
#include "../model/Group.h"
#include<string>
#include <QCoreApplication>
#include <QtSql>


TEST(TEST1, GROUP){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("CS205_MONSTER_HUNTERS1");
    db.setDatabaseName("TestGroup.sql");
    db.setUserName("ahmadw1");
    db.setPassword("password1");

    system( "sqlite3 TestGroup.sql < ../../DropHarveyRanchDB.txt;");//drop the database tables
    system("sqlite3 TestGroup.sql < ../../BuildHarveyRanchDB.txt;");//create the database tables with the admin already in
    system("sqlite3 TestGroup.sql < ../../testDBInserts.txt");//add a set of values to the tables

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

    std::cout<<"----------------------------------------------"<<std::endl;


    std::vector<std::tuple<int,std::string>> userList = Group::getUsers(1223131);//for a group not created;
    ASSERT_TRUE(userList.size()==0);

    for(int j=0; j<4; j++){//for all groups

        userList = Group::getUsers(j);
        std::cout<<"\n \n Group "+std::to_string(j)<<std::endl;
        for(unsigned int i=0; i<userList.size(); i++){//print all the users in that group
            std::cout<<std::get<1>(userList.at(i))<<std::endl;
        }

    }

    std::cout<<"----------------------------------------------"<<std::endl;

    std::vector<std::tuple<int,std::string>> groupList = Group::getGroups("Blog", 12312);
    ASSERT_TRUE(groupList.size()==0);

    //for all users
    for(int k = 0; k<5; k++){
        std::cout<<"\n \n";
        //display all groups id and name

        groupList = Group::getGroups("Blog", k);//for blog groups
        for(unsigned int l =0; l<groupList.size(); l++){
            std::cout<<"Group "+std::to_string(std::get<0>(groupList.at(l)))+" :"+std::get<1>(groupList.at(l))<<std::endl;
        }
        groupList = Group::getGroups("Message", k); //for message groups
        for(unsigned int l =0; l<groupList.size(); l++){
            std::cout<<"Group "+std::to_string(std::get<0>(groupList.at(l)))+" :"+std::get<1>(groupList.at(l))<<std::endl;
        }
    }
    std::cout<<"----------------------------------------------"<<std::endl;
    std::vector<std::tuple<int,std::string>> allGroupList = Group::viewAllBlogGroups();
    ASSERT_FALSE(allGroupList.size()==0);



        allGroupList = Group::viewAllBlogGroups();//for blog groups
        for(unsigned int x =0; x<allGroupList.size(); x++){
            std::cout<<"Group "+std::to_string(std::get<0>(allGroupList.at(x)))+" :"+std::get<1>(allGroupList.at(x))<<std::endl;
        }







    std::cout<<"----------------------------------------------"<<std::endl;
    for(int m=0; m<4; m++){ //for all message groups get all messages
        std::vector<std::tuple<std::string, std::string, std::string>> groupMessages = Group::getGroupMessages(m);

        for ( auto const& i : groupMessages ) {
            std::cout<< std::get<0>(i)<<" : " << std::get<1>(i)<<" : " << std::get<2>(i)<<" : " << std::endl;
        }

    }


    std::cout<<"----------------------------------------------"<<std::endl;

    for(int n=0; n<4; n++){ //for all  groups get all blogs if th egroup is a blog group
        std::vector<std::tuple<int, std::string, std::string, std::string>> groupBlogs = Group::getBlogPosts(n);
        std::cout<<" \n Group :"+std::to_string(n)<<std::endl;
        for ( auto const& i : groupBlogs ) {
            std::cout<< std::to_string(std::get<0>(i))<<" : " << std::get<1>(i)<<" : " << std::get<2>(i)<<" : " << std::endl;
        }

    }
    std::cout<<"----------------------------------------------"<<std::endl;

    for(int p=0; p<10; p++){ //for all  blogs get all comments if the blog has any
        std::vector<std::tuple<int, std::string, std::string, std::string>> blogComments = Group::getBlogComments(3,p);
        std::cout<<" \n Blog :"+std::to_string(p)<<std::endl;
        for ( auto const& i : blogComments ) {
            std::cout<< std::to_string(std::get<0>(i))<<" : " << std::get<1>(i)<<" : " << std::get<2>(i)<<" : " <<std::get<3>(i)<< std::endl;
        }

    }


    std::cout<<"----------------------------------------------"<<std::endl;



    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    QSqlDatabase::database().removeDatabase("default");

}
