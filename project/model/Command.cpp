#include "Command.h"


QSqlDatabase Command::dataBase;

std::tuple<bool, bool> Command::loginVerification(std::string username, std::string password){
    bool ok = dataBase.open();
    bool isAdmin=false;
    bool exists = false;


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




    if(ok){

        std::cout << "Database open\n";

        std::string queryString = "SELECT UserID"
                                  " FROM UserTable "
                                  " WHERE Username = '"+username+"' "
                                  " AND Password = '"+password+"'";

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Command"<<std::endl;
        }
        else if(query.next()){//if the username and password are valid
            int id = query.value(QString::fromStdString("UserID")).toInt();
            exists = true;
            if(id==0){
                isAdmin = true;
            }
        }

        std::tuple<bool, bool> verification(exists, isAdmin);

        //--- close connection to database
        dataBase.close();

        return verification;


    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";

    }
}


std::string Command::nameOfUser(std::string username){
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

        std::cout << "Database open\n";

        std::string queryString = "SELECT Name"
                                  " FROM UserTable "
                                  " WHERE Username = '"+username+"' ";

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Command"<<std::endl;
            return NULL;
        }
        else if(query.next()){//if the username and password are valid
            std::string nameOfUser = query.value(QString::fromStdString("Name")).toString().toStdString();
            return nameOfUser;
        }



        //--- close connection to database
        dataBase.close();


    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
        return NULL;
    }
}


bool Command::exists(std::string username){
    bool ok = dataBase.open();
    bool exists = false;

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

        std::cout << "Database open\n";

        std::string queryString = "SELECT UserID"
                                  " FROM UserTable "
                                  " WHERE Username = '"+username+"' ";

        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error Command"<<std::endl;

        }
        else if(query.next()){//if the username is valid
            int id = query.value(QString::fromStdString("UserID")).toInt();
            exists = true;

        }



        //--- close connection to database
        dataBase.close();
        return exists;


    }else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
        return false;

    }
}
