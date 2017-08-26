#include "Login.h"

//Setting initial constants
int Login::maxUserLength = 20;
int Login::maxPassLength = 20;

Login::Login()
{

}

Login::Login(QSqlDatabase* db){
    initialize();
    myDB = db;
    display();
}

void Login::display(){

    bool attempted = false;
    bool passed = false;

    while(!passed){
        std::string name = getInput(attempted, true, "");
        if(name.compare("")==0){ //Escape key was pressed
            endwin();
            return;
        }
        std::string pass = getInput(attempted, false, name);
        if(pass.compare("")==0){ //Escape key was pressed
            endwin();
            return;
        }
        passed = checkCredentials(name, pass);
        attempted = true;
    }
    advance();
}

bool Login::checkCredentials(std::string username, std::string password){

    //check database if the combination of username and password is correct
    std::tuple<bool, bool> loginVerify = Command::loginVerification(username, password);

    if(std::get<0>(loginVerify)){ //check if the account exists

        if(std::get<1>(loginVerify)){
            //admin login
            //This was trimmed from the TUI and the functionality was moved solely to the GUI
        }
        else{
            myUser = new User(*myDB, username, password);
            return true;
        }

    }
    else{
        return false;
    }
}

std::string Login::getInput(bool hasAttempted, bool user, std::string username){
    int myMax = user ? maxUserLength : maxPassLength;
    char response[myMax];

    //dummy characters to print out instead of printing out the actual password
    std::string buffer = "********************";

    bool continue_looping;
    int length = 0;
    std::string output;

    do{
        continue_looping = true;
        refresh();
        clear();
        mvprintw(8,10,"Please type your username and password to proceed.");
        mvprintw(9,10,"Press Enter to move to the next field/submit.");
        mvprintw(10,10,"Hit ESC to close!");
        if(hasAttempted) mvprintw(11, 10, "Could not find a matching username and password, please try again!");
        mvprintw(15,10,"Enter your username: ");
        if(!user) mvprintw(16,10,username.c_str());
        mvprintw(18,10,"Enter your password: ");

        output = response;
        output = output.substr(0,length);

        //This next block controls where to display the cursor and what content to print out
        if(user){ //If typing out the username
            mvprintw(16,10,output.c_str());
            attrset(A_STANDOUT);
            mvprintw(16, 10+length, " ");
            standend();
        }
        else{ //if typing out the password
            mvprintw(19,10,buffer.substr(0,length).c_str());
            attrset(A_STANDOUT);
            mvprintw(19, 10+length, " ");
            standend();
        }

        int ch = getch();
        if(ch==269)
            getHelp(); //F5
        else if(ch==10){ //Enter
            if(length > 0)
                continue_looping=false;
        }
        else if(ch==263 || ch==127){ //Backspace for Mac and Linux
            if(length > 0)
                length--;
        }
        else if(ch==27){ //Escape
            return "";
        }
        else if(length < myMax){ //Default
            response[length] = char(ch);
            length++;
        }
    } while(continue_looping);
    return output; //What the user has typed
}

void Login::advance(){
    main = new MainMenu(myUser, myDB);
    //restarts after the MainMenu is terminated
    display();
}

void Login::getHelp(){
    std::vector<std::tuple<int, int, std::string>> *content = new std::vector<std::tuple<int, int, std::string>>();

    std::tuple<int, int, std::string> newTup (7,8,"Hello World");
    content->push_back(newTup);
    showHelpScreen(content);
}
