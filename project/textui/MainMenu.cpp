#include "MainMenu.h"

MainMenu::MainMenu(){

}

MainMenu::MainMenu(User* u, QSqlDatabase *db)
{
    clear();
    selected = 0;
    options = {"Messaging","Create Blog Post",
               "Create Tweet","View Posts",
               "Launch Website","Exit"};
    initialize();
    myDB = db;
    myUser = u;
    display();
    endwin();
}

void MainMenu::display(){
    std::string loginMessage = "Signed in as : " + myUser->getUsername();
    do {
        clear();
        refresh();

        mvprintw(20,2,loginMessage.c_str());

        for(int i = 0; i<options.size(); i++){
            //if current option to be printed is also the selected one, highlight it
            if(i==selected) attrset(A_STANDOUT);
            mvprintw(6+2*i,20,options.at(i).c_str());
            if(i==selected) standend();
        }

        int ch = getch();

        switch (ch){
        case 269: //F5
            getHelp();
            break;
        case 259: //Up
            selected--;
            if(selected < 0) selected += options.size();
            break;
        case 258: //Down
            selected++;
            if(selected == options.size()) selected -= options.size();
            break;
        case 10: //Enter
            processChoice(selected);
            return;
        case 27: //Escape
            //Automatically chooses the last option which is exit
            processChoice(options.size()-1);
            return;
        }

    } while(true);
}

void MainMenu::processChoice(int selection){
    switch(selection){

    case 0: //Messaging
        if(Group::getGroups("Message",myUser->getID()).size()>0){
            message = new Messaging(myUser, myDB);
        }
        break;

    case 1: //Create Blog Post
        newPost = new PostCreator(true, myUser, myDB);
        break;

    case 2: //Create Tweet
        newPost = new PostCreator(false, myUser, myDB);
        break;

    case 3: //View Posts
        if(Group::getGroups("Blog",myUser->getID()).size()>0){
            viewPost = new PostViewer(myUser, myDB);
        }
        break;

    case 4: //Launch Website
        Website::createWebsite();
        break;

    case 5: //exit
        return;
    }
    display();
}

void MainMenu::getHelp(){
    std::vector<std::tuple<int, int, std::string>> *content = new std::vector<std::tuple<int, int, std::string>>();

    std::tuple<int, int, std::string> newTup (7,8,"Hello World");
    content->push_back(newTup);
    showHelpScreen(content);
}
