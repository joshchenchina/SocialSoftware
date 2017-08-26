#include <iostream>
#include <fstream>
#include "User.h"
#include "Admin.h"
#include "Group.h"
#include "Command.h"

#include <QCoreApplication>


using namespace std;

int main(int argc, char *argv[])
{
//    std::ofstream tmp;
//    tmp.open("HelloWorld.txt");
//    tmp << "Hello World";
//    tmp.close();

//    BlogPost* newBP = new BlogPost("This is a test","/usr23/lombardc/Desktop/waseh.jpg","01");
//    BlogPost* newBP2 = new BlogPost("This is a","HelloWorld.txt","00");



    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("CS205_MONSTER_HUNTERS");
    db.setDatabaseName("../../HarveyRanchDB.sql");
    db.setUserName("ahmadw");
    db.setPassword("password");

    Group::dataBase = db;//set the group database as db
    Command::dataBase = db;

//    Admin * admin = new Admin(db, "admin","adminPass");

//    User * user2 = new User(db, "pfaffmaj", "newPassword");

//    std::vector<std::tuple<int, std::string>> userList = Group::getUsers(1);

////    user2->leaveGroup(3);
////   user2->createMessageGroup("CS205");
//  //  user2->deleteGroup(4);

//    std::vector<std::tuple<int, std::string>> groupList = Group::getGroups("Blog", 0);

//    std::vector<std::tuple<int, std::string, std::string, std::string>> blogList = Group::getBlogPosts(3);

//    std::vector<std::tuple<int, std::string, std::string, std::string>> commentsList = Group::getBlogComments(3,2);

//    std::tuple<bool, bool> verification = Command::loginVerification("ahmadw", "password");

// //   user2->writeContent(1,"Blog", "Hi, just testing this Message");

//  //  user2->writeComment(3,2,"Just testing the comments");

//   // admin->createNewBlogGroup("TestBlog");

//    std::cout<<user2->isModerator(0)<<" Point"<< std::endl;
//    std::cout<<user2->isModerator(1)<<std::endl;
//    std::cout<<user2->isAuthor(-1,4)<<" Point"<<std::endl;

//    std::cout<<user2->deleteBlogPost("Blog", 6)<<std::endl;

//    std::cout<<user2->deleteComment(4)<<std::endl;


    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
    QSqlDatabase::database().removeDatabase("default");

    return 0;
}
