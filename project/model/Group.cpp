#include "Group.h"

QSqlDatabase Group::dataBase;

std::vector<std::tuple<int, std::string>> Group::getUsers(int groupID){
    bool ok = dataBase.open();

    if(ok){
        std::vector<std::tuple<int, std::string>> userList;

        //std::cout << "Database open\n";

        std::string queryString = "SELECT UserTable.UserID, UserTable.Username "
                                  " FROM UserTable "
                                  " INNER JOIN UserGroup"
                                  " ON UserTable.UserID = UserGroup.UserID"
                                  " WHERE GroupID = "+std::to_string(groupID);

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Group"<<std::endl;
        }
        else while(query.next()){
            int id = query.value(QString::fromStdString("UserID")).toInt();
            std::string name = (query.value(QString::fromStdString("Username")).toString()).toStdString();

            std::tuple<int, std::string> user(id, name);
            userList.push_back(user);
        }

        //--- close connection to database
        dataBase.close();

        return userList;




    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";

    }


}

std::vector<std::tuple<int, std::string>> Group::getGroups(std::string groupType,int userID){

    bool ok = dataBase.open();



    if(ok){

        std::vector<std::tuple<int, std::string>> groupList;

        //std::cout << "Database open\n";

        //gets the groupname
        std::string queryString = " SELECT GroupTable.GroupName, GroupTable.GroupID"
                                  " FROM GroupTable "
                                  " INNER JOIN UserGroup"
                                  " ON UserGroup.GroupID = GroupTable.GroupID"
                                  " WHERE GroupTable.GroupType= '"+groupType+"'"
                                                                             " AND UserGroup.UserID = "+std::to_string(userID);

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Group"<<std::endl;
        }
        else while(query.next()){
            int id = query.value(QString::fromStdString("GroupID")).toInt();
            std::string name = (query.value(QString::fromStdString("GroupName")).toString()).toStdString();

            std::tuple<int, std::string> group(id, name);//adds the name and the group id to a tuple
            groupList.push_back(group);                              //adds the tuple to the groupList
        }

        //--- close connection to database
        dataBase.close();

        return groupList;

    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";

    }

}

std::vector<std::tuple<int,std::string>> Group::viewAllBlogGroups(){
    bool ok = dataBase.open();



    if(ok){

        std::vector<std::tuple<int, std::string>> groupList;

        //std::cout << "Database open\n";

        //gets the groupname
        std::string queryString = " SELECT GroupTable.GroupName, GroupTable.GroupID"
                                  " FROM GroupTable "
                                  " WHERE GroupType = 'Blog'";

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Group"<<std::endl;
        }
        else while(query.next()){
            int id = query.value(QString::fromStdString("GroupID")).toInt();
            std::string name = (query.value(QString::fromStdString("GroupName")).toString()).toStdString();

            std::tuple<int, std::string> group(id, name);//adds the name and the group id to a tuple
            groupList.push_back(group);                              //adds the tuple to the groupList
        }

        //--- close connection to database
        dataBase.close();

        return groupList;

    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";

    }
}



std::vector<std::tuple<std::string, std::string, std::string>> Group::getGroupMessages(int groupID){

    bool ok = dataBase.open();



    if(ok){

        std::vector<std::tuple<std::string, std::string, std::string>> groupMessages;

        //std::cout << "Database open\n";

        //gets the groupname
        std::string queryString = " SELECT MessageTable.Author, MessageTable.MessageContent , GroupContentHistory.TimeStamp"
                                  " FROM GroupContentHistory "
                                  " INNER JOIN MessageTable"
                                  " ON GroupContentHistory.ContentID = MessageTable.ContentID"
                                  " WHERE GroupContentHistory.GroupID = "+ std::to_string(groupID)+
                " ORDER BY GroupContentHistory.TimeStamp";

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Group"<<std::endl;
        }
        else while(query.next()){
            std::string author = (query.value(QString::fromStdString("Author")).toString()).toStdString();
            std::string content = (query.value(QString::fromStdString("MessageContent")).toString()).toStdString();


            std::string timeStamp = (query.value(QString::fromStdString("TimeStamp")).toString()).toStdString();

            std::tuple<std::string, std::string, std::string> message(content, author, timeStamp);//adds the name and the group id to a tuple

            groupMessages.push_back(message);                              //adds the tuple to the groupList
        }

        //--- close connection to database
        dataBase.close();

        return groupMessages;

    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";

    }

}


std::vector<std::tuple<int, std::string, std::string, std::string> > Group::getBlogPosts(int groupID){
    bool ok = dataBase.open();



    if(ok){

        std::vector<std::tuple<int, std::string, std::string,std::string>> blogPosts;

        //std::cout << "Database open\n";

        //gets the groupname
        std::string queryString = " SELECT BlogPostTable.Author, BlogPostTable.ContentID, BlogPostTable.Content , GroupContentHistory.TimeStamp"
                                  " FROM GroupContentHistory "
                                  " INNER JOIN BlogPostTable"
                                  " ON GroupContentHistory.ContentID = BlogPostTable.ContentID"
                                  " WHERE GroupContentHistory.GroupID = "+ std::to_string(groupID)+
                                  " ORDER BY GroupContentHistory.TimeStamp";

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Group"<<std::endl;
        }
        else while(query.next()){
            std::string author = (query.value(QString::fromStdString("Author")).toString()).toStdString();
            std::string content = (query.value(QString::fromStdString("Content")).toString()).toStdString();
            int id = query.value(QString::fromStdString("ContentID")).toInt();
            std::string timeStamp = (query.value(QString::fromStdString("TimeStamp")).toString()).toStdString();

            std::tuple<int, std::string, std::string, std::string> blog(id, timeStamp, content, author);//adds the name and the group id to a tuple

            blogPosts.push_back(blog);                              //adds the tuple to the blogPosts list
        }

        //--- close connection to database
        dataBase.close();

        return blogPosts;

    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";

    }
}


std::vector<std::tuple<int, std::string, std::string, std::string, std::string>> Group::getMediaPosts(int groupID){
    bool ok = dataBase.open();

    if(ok){

        std::vector<std::tuple<int, std::string, std::string,std::string ,std::string>> mediaPosts;

        //std::cout << "Database open\n";

        //gets the groupname
        std::string queryString = " SELECT MediaPostTable.Author, MediaPostTable.ContentID, MediaPostTable.Content ,MediaPostTable.FilePath, GroupContentHistory.TimeStamp"
                                  " FROM GroupContentHistory "
                                  " INNER JOIN MediaPostTable"
                                  " ON GroupContentHistory.ContentID = MediaPostTable.ContentID"
                                  " WHERE GroupContentHistory.GroupID = "+ std::to_string(groupID)+
                                  " ORDER BY GroupContentHistory.TimeStamp";

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Group"<<std::endl;
        }
        else while(query.next()){
            std::string author = (query.value(QString::fromStdString("Author")).toString()).toStdString();
            std::string content = (query.value(QString::fromStdString("Content")).toString()).toStdString();
            int id = query.value(QString::fromStdString("ContentID")).toInt();
            std::string timeStamp = (query.value(QString::fromStdString("TimeStamp")).toString()).toStdString();
            std::string filePath = (query.value(QString::fromStdString("FilePath")).toString()).toStdString();

            std::tuple<int, std::string, std::string, std::string, std::string> media(id, timeStamp, content, author,filePath);//adds the name and the group id to a tuple

            mediaPosts.push_back(media);                              //adds the tuple to the blogPosts list
        }

        //--- close connection to database
        dataBase.close();

        return mediaPosts;

    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";

    }
}




std::vector<std::tuple<int, std::string, std::string, std::string>> Group::getBlogComments(int groupID, int blogID){
    bool ok = dataBase.open();



    if(ok){

        std::vector<std::tuple<int, std::string, std::string,std::string>> blogComments;

        //std::cout << "Database open\n";

        //gets the groupname
        std::string queryString = " SELECT CommentsTable.ContentID, CommentsTable.Content, CommentsTable.Author , CommentsBlogs.TimeStamp"
                                  " FROM CommentsTable "
                                  " INNER JOIN CommentsBlogs"
                                  " ON CommentsBlogs.ContentID_comment = CommentsTable.ContentID"
                                  " WHERE CommentsBlogs.GroupID = "+ std::to_string(groupID)+
                                  " AND CommentsBlogs.ContentID_blog = "+ std::to_string(blogID)+
                                  " ORDER BY CommentsBlogs.TimeStamp";

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Group"<<std::endl;
        }
        else while(query.next()){
            std::string author = (query.value(QString::fromStdString("Author")).toString()).toStdString();
            std::string content = (query.value(QString::fromStdString("Content")).toString()).toStdString();
            int id = query.value(QString::fromStdString("ContentID")).toInt();
            std::string timeStamp = (query.value(QString::fromStdString("TimeStamp")).toString()).toStdString();

            std::tuple<int, std::string, std::string, std::string> comment(id, timeStamp, content, author);// adds the info about the comment to the tuple
            blogComments.push_back(comment);                              //adds the tuple to the blog comments list
        }

        //--- close connection to database
        dataBase.close();

        return blogComments;

    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";

    }
}


std::vector<std::tuple<std::string, std::string>> Group::viewUserUploads(std::string username){
    bool ok = dataBase.open();

    //--------------------------------------------------------http://stackoverflow.com/questions/4643512/replace-substring-with-another-substring-c
       //method to replace single apostrophe
       int index = 0;
       while (true) {
            /* Locate the substring to replace. */
            index = username.find("\'", index);
            if (index == std::string::npos) break;

            /* Make the replacement. */
            username.replace(index, 1, "\'\'");

            /* Advance index forward so the next iteration doesn't pick it up as well. */
            index += 2;
       }

       //-----------------------------------------


    if(ok){

        std::vector<std::tuple<std::string, std::string>> uploads;

        //std::cout << "Database open\n";

        //gets the groupname
        std::string queryString = " SELECT BlogPostTable.Content , GroupContentHistory.TimeStamp"
                                  " FROM GroupContentHistory "
                                  " INNER JOIN BlogPostTable"
                                  " ON GroupContentHistory.ContentID = BlogPostTable.ContentID"
                                  " WHERE BlogPostTable.Author = '"+username +"' "
                                  " ORDER BY GroupContentHistory.TimeStamp";

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Group"<<std::endl;
        }
        else while(query.next()){
            std::string content = (query.value(QString::fromStdString("Content")).toString()).toStdString();
            std::string timeStamp = (query.value(QString::fromStdString("TimeStamp")).toString()).toStdString();

            std::tuple<std::string, std::string> post(timeStamp, content);//adds the timestamp and the content to a tuple

            uploads.push_back(post);                              //adds the tuple to the uploads list
        }

        //--- close connection to database
        dataBase.close();

        return uploads;

    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";


    }
}


std::tuple<bool, std::string> Group::isMedia(int contentID){
    bool ok = dataBase.open();


    if(ok){


        //std::cout << "Database open\n";

        //gets the groupname
        std::string queryString = " SELECT GroupContentHistory.UploadType, MediaPostTable.FilePath "
                                  " FROM GroupContentHistory "
                                  " INNER JOIN MediaPostTable"
                                  " ON GroupContentHistory.ContentID = MediaPostTable.ContentID"
                                  " WHERE GroupContentHistory.ContentID = "+std::to_string(contentID);

        QSqlQuery query(QString::fromStdString(queryString));

        bool isMedia=false;
        std::string filePath= "";

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Group"<<std::endl;
        }
        else while(query.next()){


            std::string type = (query.value(QString::fromStdString("UploadType")).toString()).toStdString();
            if(type == "Media"){
                isMedia = true;
                filePath = (query.value(QString::fromStdString("FilePath")).toString()).toStdString();
            }
        }

        std::tuple<bool, std::string> media(isMedia, filePath);//adds the isMedia bool and file path to the tuple

        //--- close connection to database
        dataBase.close();

        return media;

    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
        return std::tuple<int,std::string>(false,"");


    }
}



std::vector<std::tuple<std::string,std::string,std::string,std::string>> Group::getAllPosts(){
    bool ok = dataBase.open();



    if(ok){

        std::vector<std::tuple<std::string,std::string,std::string,std::string>> allPosts;

        //std::cout << "Database open\n";

        //gets the groupname
        std::string queryString = "Select BlogPostTable.Author, BlogPostTable.Content, NULL, GroupContentHistory.TimeStamp "
                                  " FROM BlogPostTable "
                                  " INNER JOIN GroupContentHistory"
                                  " ON GroupContentHistory.ContentID = BlogPostTable.ContentID"
                                  " UNION"
                                  " Select MediaPostTable.Author, MediaPostTable.Content,MediaPostTable.FilePath, GroupContentHistory.TimeStamp "
                                  " FROM MediaPostTable "
                                  " INNER JOIN GroupContentHistory "
                                  " ON GroupContentHistory.ContentID = MediaPostTable.ContentID"
                                  " ORDER BY GroupContentHistory.TimeStamp" ;

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Group"<<std::endl;
        }
        else while(query.next()){
            std::string author = (query.value(QString::fromStdString("Author")).toString()).toStdString();
            std::string content = (query.value(QString::fromStdString("Content")).toString()).toStdString();
            std::string timeStamp = (query.value(QString::fromStdString("TimeStamp")).toString()).toStdString();
            std::string filePath = (query.value(QString::fromStdString("NULL")).toString()).toStdString();//colun is stated as null since Blog posts were queried first

            std::tuple<std::string, std::string, std::string, std::string> post(author,timeStamp,content,filePath);//adds the name and the group id to a tuple

            allPosts.push_back(post);                              //adds the tuple to the blogPosts list
        }

        //--- close connection to database
        dataBase.close();

        return allPosts;

    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";


    }
}


