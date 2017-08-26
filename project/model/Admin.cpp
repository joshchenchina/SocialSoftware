#include "Admin.h"

Admin::Admin()
{
    isAdmin = true;
    id = id_cnt;
    id_cnt++;
    this->name = "null, null";
    this->password = "null";
    this->username = "null";
}

Admin::Admin(QSqlDatabase db, std::string username, std::string password):User(db,username,password)
{
    this->dataBase = db;

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


    if ( ok ) {
        //--- we're good! ---
        std::cout << "Database open\n";

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

bool Admin::createNewBlogGroup(std::string groupName){


    bool ok = dataBase.open();

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

    if ( ok ) {
        //--- we're good! ---
        std::cout << "Database open\n";

        //--- run a query for adding into a new group to the main GroupTable table

        std::string queryString = "INSERT into GroupTable (GroupName, ModeratorID, GroupType) "
                                  "VALUES('"+groupName+"',"+std::to_string(this->id)+", 'Blog' )";


        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Admin"<<std::endl;
        }

        // ----------------------------------------- add the admin himself to the group
        std::string queryStringUserGroup = "INSERT into UserGroup (UserID, GroupID)"
                                           " VALUES("+std::to_string(this->id)+", "
                                           " (SELECT MAX(GroupID) from GroupTable WHERE GroupName = '"+groupName+"' AND ModeratorID ="+std::to_string(this->id) +"))";


        QSqlQuery query2(QString::fromStdString(queryStringUserGroup));

        if ( !query2.isActive() ){
            QString qsError =  "Query Error " + query2.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Admin"<<std::endl;
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

bool Admin::createNewUser(std::string name, std::string username, std::string password){
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
       index =0;
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




    if ( ok ) {
        //--- we're good! ---
        std::cout << "Database open\n";

        //--- run a query for adding a new user to the usertable

        std::string queryString = "INSERT into UserTable (Name, Username, Password) "
                                  "VALUES('"+name+"', '"+username+"', '"+password+"' )";


        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Admin"<<std::endl;
            return false;
        }
        else{
            return true;
        }

        //--- close connection to database
        dataBase.close();



    }
    else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
    }
}

