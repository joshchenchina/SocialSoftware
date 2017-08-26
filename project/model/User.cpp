#include "User.h"


int User::id_cnt = 0;

User::User(){
    id = id_cnt;
    id_cnt++;
    this->name = "null, null";
    this->password = "null";
    this->username = "null";
    gHist = new GroupHistory(this->id);

}
//constructor for creating a user object from database info
User::User(QSqlDatabase db, std::string username, std::string password)
{

    this->dataBase = db;

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
       index =0;
       while (true) {
            /* Locate the substring to replace. */
            index = password.find("\'", index);
            if (index == std::string::npos) break;

            /* Make the replacement. */
            password.replace(index, 1, "\'\'");

            /* Advance index forward so the next iteration doesn't pick it up as well. */
            index += 2;
       }

       //-----------------------------------------

    bool ok = dataBase.open();

    if ( ok ) {
        //--- we're good! ---
        //std::cout << "Database open\n";

        //--- run a query and print data returned ---

        std::string queryString = "SELECT * from UserTable WHERE "
                                  "Username ='"+username+"' "
                                                         "AND Password ='"+ password+"'";

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
        }


        else while (query.next()) {
            this->id = query.value(QString::fromStdString("UserID")).toInt();

            this->name = (query.value(QString::fromStdString("Name")).toString()).toStdString();

            std::cout <<"the id is " <<this->id<<"\n the name is "<<this->name<< std::endl;

        }

        //--- close connection to database
        dataBase.close();
    }
    else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
    }

    this->password = password;
    this->username = username;

    gHist = new GroupHistory(this->id, db);
}

User::User(std::string password, std::string username, std::string name){
    id = id_cnt;
    id_cnt++;
    this->name = name;
    this->password = password;
    this->username = username;
    gHist = new GroupHistory(this->id);
}

User::~User(){

}


void User::setName(std::string name){
    this->name = name;

    //--------------------------------------------------------http://stackoverflow.com/questions/4643512/replace-substring-with-another-substring-c
       //method to replace single apostrophe
       int index = 0;

       while (true) {
            /* Locate the substring to replace. */
            index = name.find("\'", index);
            if (index == std::string::npos) break;

            /* Make the replacement. */
            name.replace(index, 1, "\'\'");

            /* Advance index forward so the next iteration doesn't pick it up as well. */
            index += 2;
       }

       //-----------------------------------------

    bool ok = dataBase.open();

    if ( ok ) {
        //--- we're good! ---
        //std::cout << "Database open\n";

        //--- run a query and print data returned ---

        std::string queryString = "UPDATE UserTable "
                                  "SET Name = '"+name+"'"
                                                      " WHERE UserID = "+std::to_string(id);


        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
        }

        //--- close connection to database
        dataBase.close();
    }
    else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
    }



}

void User::setPassword(std::string password){
    this->password = password;

    //--------------------------------------------------------http://stackoverflow.com/questions/4643512/replace-substring-with-another-substring-c
       //method to replace single apostrophe
       int index = 0;

       while (true) {
            /* Locate the substring to replace. */
            index = password.find("\'", index);
            if (index == std::string::npos) break;

            /* Make the replacement. */
            password.replace(index, 1, "\'\'");

            /* Advance index forward so the next iteration doesn't pick it up as well. */
            index += 2;
       }


       //-----------------------------------------

    bool ok = dataBase.open();

    if ( ok ) {
        //--- we're good! ---
        //std::cout << "Database open\n";

        //--- run a query and print data returned ---

        std::string queryString = "UPDATE UserTable "
                                  "SET Password = '"+password+"'"
                                                              " WHERE UserID = "+std::to_string(id);


        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
        }

        //--- close connection to database
        dataBase.close();
    }
    else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
    }
}



bool User::createMessageGroup(std::string groupName){

    //--------------------------------------------------------http://stackoverflow.com/questions/4643512/replace-substring-with-another-substring-c
       //method to replace single apostrophe
       int index = 0;
       while (true) {
            /* Locate the substring to replace. */
            index = groupName.find("\'", index);
            if (index == std::string::npos) break;

            /* Make the replacement. */
            groupName.replace(index, 1, "\'\'");

            /* Advance index forward so the next iteration doesn't pick it up as well. */
            index += 2;
       }


       //-----------------------------------------

    bool ok = dataBase.open();
    int groupID = -1;
    if ( ok ) {
        //--- we're good! ---
        //std::cout << "Database open\n";

        //--- run a query for adding into a new group to the main GroupTable table

        QSqlQuery queryBegin(QString::fromStdString("BEGIN"));

        std::string queryString = "INSERT into GroupTable (GroupName, ModeratorID, GroupType) "
                                  "VALUES('"+groupName+"',"+std::to_string(this->id)+",'Message' )";


        QSqlQuery query(QString::fromStdString(queryString.c_str()));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
        }

        std::string queryStringUserGroup = "INSERT into UserGroup"
                                           " VALUES("+std::to_string(this->id)+", "
                                           " (SELECT MAX(GroupID) from GroupTable WHERE GroupName = '"+groupName+"' AND ModeratorID ="+std::to_string(this->id) +"))";

        //std::cout<<queryStringUserGroup<<std::endl;


        QSqlQuery query2(QString::fromStdString(queryStringUserGroup.c_str()));

        if ( !query2.isActive() ){
            QString qsError =  "Query Error " + query2.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;

        }

        //add a starting message to that group saying the group was created

        std::string querySelectGroupIDFirstMessage = "SELECT MAX(GroupID) from GroupTable "
                                                    "WHERE GroupName = '"+groupName+"' "
                                                            "AND ModeratorID ="+std::to_string(this->id);

        QSqlQuery query3(QString::fromStdString(querySelectGroupIDFirstMessage));


        if ( !query3.isActive() ){
            QString qsError =  "Query Error " + query3.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
        }
        else{

            while(query3.next()){//store the groupID
               groupID = query3.value(QString::fromStdString("MAX(GroupID)")).toInt();

            }//add the starting message

        }
        bool success = false;
        if(!query.isActive() || !query2.isActive()|| !query3.isActive()){

            QSqlQuery queryEndBad(QString::fromStdString("ROLLBACK"));
            std::cout<<"There was an error. Did not Create new message Group. Check your database handler or parameters provided to method. \n";
            success = false;
        }
        else{

            QSqlQuery queryEndGood(QString::fromStdString("COMMIT"));
            success =true;
        }
        if(success) {writeContent(groupID, "Message","Created a new Message Group");}




        //--- close connection to database
        dataBase.close();

        return success;
    }
    else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
        return false;
    }



}


// what about if the moderator wants to leaveGroup() or does he only have the option of deleting the group
bool User::leaveGroup(int groupID){
    if(!isAdmin){
        //only for message groups


        //writes a comment on the group which left to say that this user left

        //removes the person from the User/Group table

        if(this->isModerator(groupID)){
            return deleteGroup(groupID);
        }
        else{
            bool ok = dataBase.open();

            if ( ok ) {
                //--- we're good! ---
                //std::cout << "Database open\n";

                //--- run a query and print data returned ---

                std::string queryString = "DELETE FROM UserGroup "
                                          " WHERE   UserID="+std::to_string(id)+
                        " AND     GROUPID = "+std::to_string(groupID);//---------------------->this is where the id should go if not using objects


                QSqlQuery query(QString::fromStdString(queryString));

                if ( !query.isActive() ){
                    QString qsError =  "Query Error " + query.lastError().text();
                    std::cout<<qsError.toStdString()<<std::endl;
                    std::cout<<"point Query error User"<<std::endl;
                }

                //--- close connection to database
                dataBase.close();
                return true;
            }
            else{
                //--- something went wrong ---
                std::cout << "Error opening database\n";
                return false;
            }


        }
    }
    else {
        std::cout<<"The admin cannot leave a group";
        return false;
    }


}

bool User::deleteGroup(int groupID){
    bool ok = dataBase.open();

    if ( ok ) {
        //--- we're good! ---
        //std::cout << "Database open\n";

        //--- run a query and print data returned ---

        std::string queryString = "SELECT ContentID FROM GroupContentHistory "
                                  " WHERE GroupID = "+std::to_string(groupID);//---------------------->this is where the id should go if not using objects


        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
        }

        //delete from the different content tables and the user content history table
        else while (query.next()) {//for each content in that group
            int contentID = query.value(QString::fromStdString("ContentID")).toInt();//gets the content number

            std::string queryStringMessage = "DELETE from MessageTable"
                                             " WHERE ContentID = "+std::to_string(contentID);
            QSqlQuery queryMessage(QString::fromStdString(queryStringMessage));

            std::string queryStringBlog = "DELETE from BlogPostTable"
                                          " WHERE ContentID = "+std::to_string(contentID);
            QSqlQuery queryBlog(QString::fromStdString(queryStringBlog));

            std::string queryStringMedia = "DELETE from MediaPostTable"
                                           " WHERE ContentID = "+std::to_string(contentID);

            QSqlQuery queryMedia(QString::fromStdString(queryStringMedia));

            if(!queryMessage.isActive() || !queryBlog.isActive() || !queryMedia.isActive()){

                QString qsErrorContent = "Query Error " + queryMessage.lastError().text() + queryBlog.lastError().text() + queryMedia.lastError().text();
                std::cout<<qsErrorContent.toStdString()<<std::endl;
                std::cout<<"point Query error User"<<std::endl;
            }

            //delete content from the userupload history as well
            std::string queryStringUserContent = "DELETE from UserUploadHistory"
                                                 " WHERE ContentID = "+std::to_string(contentID);
            QSqlQuery queryUserContent(QString::fromStdString(queryStringUserContent));

            if(!queryUserContent.isActive()){

                QString qsErrorUserContent = "Query Error " + queryUserContent.lastError().text();
                std::cout<<qsErrorUserContent.toStdString()<<std::endl;
                std::cout<<"point Query error User"<<std::endl;
            }

        }

        std::string queryString2 = "SELECT ContentID_comment FROM CommentsBlogs "
                                   " WHERE GroupID = "+std::to_string(groupID);


        QSqlQuery query2(QString::fromStdString(queryString2));

        if ( !query2.isActive() ){
            QString qsError2 =  "Query Error " + query2.lastError().text();
            std::cout<<qsError2.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
        }

        else while(query2.next()){//delete from comments table
            int commentID = query.value(QString::fromStdString("ContentID_comment")).toInt();//gets the comment number

            std::string queryStringComment = "DELETE from CommentsTable"
                                             " WHERE ContentID = "+std::to_string(commentID);
            QSqlQuery queryComment(QString::fromStdString(queryStringComment));
            if(!queryComment.isActive()){

                QString qsErrorComment = "Query Error " + queryComment.lastError().text();
                std::cout<<qsErrorComment.toStdString()<<std::endl;
                std::cout<<"point Query error User"<<std::endl;
            }

        }

        std::string queryString3 = "DELETE FROM GroupContentHistory WHERE GroupID = "+std::to_string(groupID);
        std::string queryString4 = "DELETE FROM CommentsBlogs WHERE GroupID = "+std::to_string(groupID);
        std::string queryString5 = "DELETE FROM GroupContentHistory WHERE GroupID = "+std::to_string(groupID);
        std::string queryString6 = "DELETE FROM UserGroup WHERE GroupID = "+std::to_string(groupID);
        std::string queryString7 = "DELETE FROM GroupTable WHERE GroupID = "+std::to_string(groupID);


        QSqlQuery query3(QString::fromStdString(queryString3));
        QSqlQuery query4(QString::fromStdString(queryString4));
        QSqlQuery query5(QString::fromStdString(queryString5));
        QSqlQuery query6(QString::fromStdString(queryString6));
        QSqlQuery query7(QString::fromStdString(queryString7));


        //--- close connection to database
        dataBase.close();
        return true;
    }
    else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
        return false;
    }

}



int User::writeContent(int groupID, std::string uploadType, std::string content, std::string extension){
    bool ok = dataBase.open();


    //--------------------------------------------------------http://stackoverflow.com/questions/4643512/replace-substring-with-another-substring-c
       //method to replace single apostrophe
       int index = 0;
       while (true) {
            /* Locate the substring to replace. */
            index = content.find("\'", index);
            if (index == std::string::npos) break;

            /* Make the replacement. */
            content.replace(index, 1, "\'\'");

            /* Advance index forward so the next iteration doesn't pick it up as well. */
            index += 2;
       }


       //-----------------------------------------


    if(ok){

        int contentID= -1;

        //std::cout << "Database open\n";


        //-----------------------------------Add content to the group content history using a transaction
        // ////////////////////Database becomes locked and can only view at this time

        QSqlQuery queryStart(QString::fromStdString("BEGIN"));

        std::string queryInsertString = "INSERT into GroupContentHistory(GroupID, UploadType, TimeStamp)"
                                        " VALUES ("+std::to_string(groupID)+" , '"+ uploadType + "' , "+ std::to_string(cTimeStamp())+")";

        QSqlQuery queryInsert(QString::fromStdString(queryInsertString));

        if ( !queryInsert.isActive() ){
            QString qsError =  "Query Error " + queryInsert.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User insert"<<std::endl;
        }

        QSqlQuery querySelect(QString::fromStdString("SELECT MAX(ContentID) FROM GroupContentHistory"));

        if ( !querySelect.isActive() ){
            QString qsError =  "Query Error " + querySelect.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
        }
        else while(querySelect.next()){
            contentID = querySelect.value(QString::fromStdString("MAX(ContentID)")).toInt();
        }



        //--------------------------------------Add content to the appropriate content table

        std::string queryString;

        if(uploadType == "Blog"){
            queryString = "INSERT into BlogPostTable (ContentID, Content, UserID, Author)"
                          " VALUES("+std::to_string(contentID)+", '"+content+"' ,"+std::to_string(this->id)+", '"+this->username+"' )" ;


        }
        else if(uploadType == "Message"){
            queryString = "INSERT into MessageTable (ContentID, MessageContent, Author)"
                          " VALUES("+std::to_string(contentID)+", '"+content+"', '"+this->username+"' )" ;
        }
        else if(uploadType == "Media"){

            std::string filePath = "/auto/bunter_usr11/cs205_2016_Grp00/mediaContent_HarveyRanch/"+std::to_string(contentID)+extension;

            queryString = "INSERT into MediaPostTable (ContentID, Content, UserID, Author, FilePath)"
                          " VALUES("+std::to_string(contentID)+", '"+content+"' ,"+std::to_string(this->id)+", '"+this->username+"', '"+filePath+"')" ;
        }

        QSqlQuery queryUpload(QString::fromStdString(queryString));

        if ( !queryUpload.isActive() ){
            QString qsError =  "Query Error " + queryUpload.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
        }

        //------------------------------------------Add contentID to the UserUploadHistory

        bool typeBlogOrMediaError = false;//boolean which shows if the error occurs in the following sql query to add to the useruploadhistory
        if(uploadType== "Blog" || uploadType == "Media"){


            std::string queryUserUploadHistoryString = "INSERT into UserUploadHistory (UserID, ContentID)"
                                                       " VALUES("+std::to_string(this->id)+","+std::to_string(contentID)+")";

            QSqlQuery queryUserUpload(QString::fromStdString(queryUserUploadHistoryString));

            if ( !queryUserUpload.isActive() ){
                QString qsError =  "Query Error " + queryUserUpload.lastError().text();
                std::cout<<qsError.toStdString()<<std::endl;
                std::cout<<"point Query error User"<<std::endl;
                typeBlogOrMediaError = true;
            }
        }

        if(!queryUpload.isActive() || !queryInsert.isActive()|| typeBlogOrMediaError){

            QSqlQuery queryEndBad(QString::fromStdString("ROLLBACK"));
            std::cout<<"There was an error. Did not write new message. Check your database handler or parameters provided to method. \n";
            return -1;
        }
        else{

            QSqlQuery queryEndGood(QString::fromStdString("COMMIT"));
            return contentID;
        }

        //--- close connection to database
        dataBase.close();


    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";

    }
}


void User::writeComment(int groupID, int blogPostID, std::string comment){

    //--------------------------------------------------------http://stackoverflow.com/questions/4643512/replace-substring-with-another-substring-c
       //method to replace single apostrophe
       int index = 0;
       while (true) {
            /* Locate the substring to replace. */
            index = comment.find("\'", index);
            if (index == std::string::npos) break;

            /* Make the replacement. */
            comment.replace(index, 1, "\'\'");

            /* Advance index forward so the next iteration doesn't pick it up as well. */
            index += 2;
       }


       //-----------------------------------------

    bool ok = dataBase.open();


    if(ok){

        int contentID= -1;

        //std::cout << "Database open\n";


        //-----------------------------------Add content to the CommentsBlogs using a transaction
        // ////////////////////Database becomes locked and can only view at this time

        QSqlQuery queryStart(QString::fromStdString("BEGIN"));

        std::string queryInsertString = "INSERT into CommentsBlogs(GroupID, ContentID_blog, TimeStamp)"
                                        " VALUES ("+std::to_string(groupID)+" , "+ std::to_string(blogPostID)+ " , "+ std::to_string(cTimeStamp())+")";

        QSqlQuery queryInsert(QString::fromStdString(queryInsertString));

        if ( !queryInsert.isActive() ){
            QString qsError =  "Query Error " + queryInsert.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User insert"<<std::endl;
        }

        QSqlQuery querySelect(QString::fromStdString("SELECT MAX(ContentID_comment) FROM CommentsBlogs"));

        if ( !querySelect.isActive() ){
            QString qsError =  "Query Error " + querySelect.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
        }
        else while(querySelect.next()){
            contentID = querySelect.value(QString::fromStdString("MAX(ContentID_comment)")).toInt();
        }



        //--------------------------------------Add content to the appropriate content table

        std::string queryString = "INSERT into CommentsTable(ContentId, UserID, Content, Author)"
                                  " VALUES ("+std::to_string(contentID)+", "+std::to_string(this->id)+", '"+ comment+ "', '"+ this->username+"' )";

        QSqlQuery queryUpload(QString::fromStdString(queryString));

        if ( !queryUpload.isActive() ){
            QString qsError =  "Query Error " + queryUpload.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
        }

        if(!queryUpload.isActive() || !queryInsert.isActive()){
            QSqlQuery queryEndBad(QString::fromStdString("ROLLBACK"));
            std::cout<<"There was an error. Did not write new comment. Check your database handler or parameters provided to method. \n";
        }
        else{
            QSqlQuery queryEndGood(QString::fromStdString("COMMIT"));
        }

        //--- close connection to database
        dataBase.close();


    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";

    }
}



bool User::addUsers(int groupID, std::string username){

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

    bool ok = dataBase.open();

    if ( ok ) {
        //--- we're good! ---
        //std::cout << "Database open\n";

        //--- run a query and print data returned ---

        int id = -1; //initial id to see if the user even exists

        std::string queryStringExists = "SELECT UserID from UserTable"
                                        " WHERE Username ='"+username+"'";


        QSqlQuery queryExists(QString::fromStdString(queryStringExists));

        if ( !queryExists.isActive() ){
            QString qsError =  "Query Error " + queryExists.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
            return false;
        }
        else while(queryExists.next()){
            id = queryExists.value(QString::fromStdString("UserID")).toInt();
        }

        if(id== -1){
            //no such username in database
            return false;
        }
        else{
            std::string queryStringInsert = "INSERT into UserGroup(UserID, GroupID)"
                                            " VALUES("+std::to_string(id)+", "+std::to_string(groupID)+") ";


            QSqlQuery queryInsert(QString::fromStdString(queryStringInsert));

            if ( !queryInsert.isActive() ){
                QString qsError =  "Query Error " + queryInsert.lastError().text();
                std::cout<<qsError.toStdString()<<std::endl;
                std::cout<<"point Query error User"<<std::endl;
                return false;
            }
            else { return true; }

        }

        //--- close connection to database
        dataBase.close();
    }
    else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
        return false;
    }
}



bool User::isModerator(int groupID){
    bool ok = dataBase.open();

    if ( ok ) {
        //--- we're good! ---
        //std::cout << "Database open\n";

        //--- run a query and print data returned ---

        std::string queryString = "SELECT ModeratorID FROM GroupTable"
                                  " WHERE GroupID = "+std::to_string(groupID);


        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
        }
        else while(query.next()){
            if(this->id == query.value(QString::fromStdString("ModeratorID")).toInt()){//if the moderatorid is the current user id
                return true;
            }else{
                return false;
            }
        }

        //--- close connection to database
        dataBase.close();
    }
    else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
    }

}

bool User::isAuthor( int blogPostID, int commentID){
    bool ok = dataBase.open();

    if ( ok ) {
        //--- we're good! ---
        //std::cout << "Database open\n";

        //--- run a query and print data returned ---

        std::string queryString;

        if(commentID == -1){//if the groupID isnt required i.e. it isnt a comment

            queryString = "SELECT UserID FROM UserUploadHistory"
                          " WHERE ContentID = "+std::to_string(blogPostID);
        }
        else{ // it is a comment
            queryString = "SELECT UserID From CommentsTable"
                          " WHERE ContentID = "+std::to_string(commentID);
        }

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error User"<<std::endl;
        }
        else if(query.next()){
            if(this->id == query.value(QString::fromStdString("UserID")).toInt()){//if the moderatorid is the current user id
                return true;
            }else{
                return false;
            }
        }else { return false;}

        //--- close connection to database
        dataBase.close();
    }
    else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
    }
}

bool User::deleteBlogPost(std::string postType, int contentID){

    bool ok = dataBase.open();

    if ( ok ) {

        if(this->isAuthor(contentID)){//check if the user deleting the post is the author

            //--- we're good! ---
            //std::cout << "Database open\n";

            //--- run a query and print data returned ---

            QSqlQuery queryBegin(QString::fromStdString("BEGIN"));

            //------------------------------------------------------Deleting from the UserUploadHistory
            std::string queryStringUserUpload = "DELETE From UserUploadHistory"
                                                " WHERE ContentID = "+std::to_string(contentID);


            QSqlQuery queryUserUpload(QString::fromStdString(queryStringUserUpload));

            if ( !queryUserUpload.isActive() ){
                QString qsError =  "Query Error " + queryUserUpload.lastError().text();
                std::cout<<qsError.toStdString()<<std::endl;
                std::cout<<"point Query error User"<<std::endl;
            }
            //---------------------------------------------------------Deleting from the GroupContentHistory
            std::string queryStringGroupContent = "DELETE From GroupContentHistory"
                                                  " WHERE ContentID = "+std::to_string(contentID);


            QSqlQuery queryGroupContent(QString::fromStdString(queryStringGroupContent));

            if ( !queryGroupContent.isActive() ){
                QString qsError =  "Query Error " + queryGroupContent.lastError().text();
                std::cout<<qsError.toStdString()<<std::endl;
                std::cout<<"point Query error User"<<std::endl;
            }
            //---------------------------------------------------------Delete from the appropriate post table
            std::string queryStringPost ="";
            if(postType == "Media"){
                queryStringPost = "DELETE From MediaPostTable"
                                  " WHERE ContentID = "+std::to_string(contentID);
            }
            else if(postType == "Blog"){
                queryStringPost = "DELETE From BlogPostTable"
                                  " WHERE ContentID = "+std::to_string(contentID);
            }

            QSqlQuery queryPost(QString::fromStdString(queryStringPost));

            if ( !queryPost.isActive() ){
                QString qsError =  "Query Error " + queryPost.lastError().text();
                std::cout<<qsError.toStdString()<<std::endl;
                std::cout<<"point Query error User"<<std::endl;
            }

            //--------------------------------------------------------------------------

            if(!queryUserUpload.isActive() || !queryGroupContent.isActive() ||!queryPost.isActive() ){//if something goes wrong with the databse, rollback the function
                QSqlQuery queryEndBad(QString::fromStdString("ROLLBACK"));
                return false;
            }
            else{//else commit and go through with the delete
                QSqlQuery queryEndGood(QString::fromStdString("COMMIT"));
                return true;

            }



            //--- close connection to database
            dataBase.close();

        }
        else {
            return false; //the user was not the moderator of the group
        }
    }
    else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
    }

}

bool User::deleteComment(int commentID){
    bool ok = dataBase.open();

    if ( ok ) {
        if(this->isAuthor(-1,commentID)){

            //--- we're good! ---
            //std::cout << "Database open\n";

            //--- run a query and print data returned ---
            QSqlQuery queryBegin(QString::fromStdString("BEGIN"));
            //--------------------------------------------------------------Deleting from comments table

            std::string queryStringComments = "DELETE FROM CommentsTable "
                                              " WHERE ContentID = "+std::to_string(commentID);


            QSqlQuery queryComments(QString::fromStdString(queryStringComments));

            if ( !queryComments.isActive() ){
                QString qsError =  "Query Error " + queryComments.lastError().text();
                std::cout<<qsError.toStdString()<<std::endl;
                std::cout<<"point Query error User"<<std::endl;
            }
            //--------------------------------------------------------------Deleting from commentsBlog
            std::string queryStringBlogComments = "DELETE FROM CommentsBlogs "
                                                  " WHERE ContentID_comment = "+std::to_string(commentID);


            QSqlQuery queryCommentsBlogs(QString::fromStdString(queryStringBlogComments));

            if ( !queryCommentsBlogs.isActive() ){
                QString qsError =  "Query Error " + queryCommentsBlogs.lastError().text();
                std::cout<<qsError.toStdString()<<std::endl;
                std::cout<<"point Query error User"<<std::endl;
            }
            //--------------------------------------------------------------
            if(!queryCommentsBlogs.isActive() || !queryComments.isActive()){
                QSqlQuery queryEndBad(QString::fromStdString("ROLLBACK"));
                return false;
            }else{
                QSqlQuery queryEndGood(QString::fromStdString("COMMIT"));
                return true;
            }

            //--- close connection to database
            dataBase.close();
        }
    }
    else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";

    }

}





GroupHistory* User::getGHist(){
    return gHist;
}

/*!
 * Gets the first name of the user from the full name provided
 * finds the position of the comma in the full name as  lastname, firstname
 * gets the substring of the full name from position  where the comma is at to the last position
 */
std::string User::getFirstName(){
    std::string fName;

    int commaAt = name.find(",");

    int start = commaAt+2;

    fName = name.substr(start);

    return fName;
}


/*!
 * Gets the last name of the user from the full name provided
 * finds the position of the comma in the full name as  lastname, firstname
 * gets the substring of the full name from position 0 to the position where the comma is at
 */
std::string User::getLastName(){

    std::string lName;

    int commaAt = name.find(",");

    int end = commaAt;

    lName = name.substr(0,end);

    return lName;
}


std::string User::getFullName(){
    return name;
}

int User::getID(){
    return id;
}

std::string User::getPassword(){
    return password;
}

std::string User::getUsername(){
    return username;
}

bool User::getIsAdmin(){
    return isAdmin;
}


long User::cTimeStamp(){
    //http://www.cplusplus.com/reference/ctime/strftime/
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    std::time(&rawtime);
    timeinfo = localtime (&rawtime);

    std::strftime(buffer,80,"%Y%m%d%H%M%S",timeinfo);
    //std::puts(buffer);
    return std::stol(buffer);
}

