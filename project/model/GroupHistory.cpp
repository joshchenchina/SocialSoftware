#include "GroupHistory.h"

GroupHistory::GroupHistory()
{
    this->gHistID = -1;

}

GroupHistory::GroupHistory(int id){
    this->gHistID = id;
}


GroupHistory::GroupHistory(int id, QSqlDatabase db){
    this->gHistID = id;
    this->dataBase = db;

}


std::vector<int> GroupHistory::viewGroups(){
    updateListOfGroups();
    return groupIDs;
}

void GroupHistory::updateListOfGroups(){

    //first clear the vector
    groupIDs.clear();

    //then reload from database

    bool ok = dataBase.open();
    if ( ok ) {
        //--- we're good! ---
        std::cout << "Database open\n";

        //--- run a query and print data returned ---

        std::string queryString = "SELECT * from UserGroup WHERE "
                                  "UserID ="+std::to_string(gHistID);


        QSqlQuery query(QString::fromStdString(queryString));

        if ( !query.isActive() ){
            QString qsError =  "Query Error " + query.lastError().text();
            std::cout<<qsError.toStdString()<<std::endl;
            std::cout<<"point Query error GroupHistory"<<std::endl;
        }


        else while (query.next()) {
            int groupID = query.value(QString::fromStdString("GroupID")).toInt();//get the value of the groupID
            this->groupIDs.push_back(groupID);//add that group to the vector storing all the groups

        }

        //--- close connection to database
        dataBase.close();
    }
    else{
        //--- something went wrong ---
        std::cout << "Error opening database\n";
    }
}


GroupHistory::~GroupHistory(){

}


int GroupHistory::getGHistID(){
    return this->gHistID;
}





