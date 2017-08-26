#include "PostCreator.h"

int PostCreator::maxTweetLength = 250;
int PostCreator::maxBlogLength = 500;
int PostCreator::maxContentWidth = 50;
int PostCreator::xStart = 20;
int PostCreator::offset = 2;

PostCreator::PostCreator(){
}

PostCreator::PostCreator(bool blogPost, User* u, QSqlDatabase *db)
{
    initialize();

    //set to false as this is for control later
    bool quitting = false;

    //start at the first group
    selectedGroup = 0;

    //set to false because they have to select a group first
    canComment = false;

    myDB = db;
    type = blogPost ? 0 : 1;
    myMax = blogPost ? maxBlogLength : maxTweetLength;

    groupList = Group::getGroups("Blog",u->getID());
    std::string content = "";
    std::string link = "";
    std::string newLink;

    //gets the group that will be written to
    //If the user hits escape then that returns false
    if(getGroup(blogPost)){
        content = getContent();
        //returns "" if the User hits escape
        if(content.compare("")!=0){

            if(blogPost){
                link = getLink(content,"");
                newLink = link;
                //returns "" if the user chooses to not select a link
                if(link.compare("")!=0){
                    //returns "~~QUITTING~~" if the user hit escape
                    if(link.compare("~~QUITTING~~")!=0){
                        newLink = checkFullPath(link);

                        while(!quitting && !checkMedia(newLink)){
                            newLink = getLink(content,newLink);
                            if(newLink.compare("~~QUITTING~~") == 0) quitting = true;
                            newLink = checkFullPath(newLink);
                        }

                    }
                    else quitting = true;
                }
            }

        }
        else quitting = true;
        //ADD POST TO DB
        if(!quitting){
            //writing comments as specified in the User class
            int postID = u->writeContent(std::get<0>(groupList.at(selectedGroup)),
                                         blogPost ? (newLink.compare("")==0 ? "Blog" : "Media") : "Blog" ,
                                         content,
                                         getExtension(newLink) );
            //copies the link to a folder for access later
            system(("cp " + newLink + " /auto/bunter_usr11/cs205_2016_Grp00/mediaContent_HarveyRanch/" + std::to_string(postID) + getExtension(newLink)).c_str());
        }
    }

    endwin();
}

std::string PostCreator::getContent(){

    //sets response length
    char response[type == 0 ? maxBlogLength : maxTweetLength];
    bool continue_looping;
    int length = 0;
    int ypos = 8;

    //sets position based on the maximum height that can be achieved in the content above it
    int linkYPos = ypos + maxBlogLength/maxContentWidth + 1;
    std::string output;
    do{
        continue_looping = true;
        refresh();
        clear();
        printConversationPanel(15,&groupList);
        mvprintw(3,xStart,"Please type your message here.");
        mvprintw(4,xStart,"Press Enter to move to the next field/submit.");
        mvprintw(5,xStart,"Hit ESC to close!");
        mvprintw(7,xStart,("Content:   " + std::to_string(myMax-length) + "/" + std::to_string(myMax)).c_str());

        output = response;
        output = output.substr(0,length);
        //prints the full content typed by the user
        for(int i=0; i<=length; i++){
            mvprintw(ypos + (int) (i/maxContentWidth),xStart+i-((int) (i/maxContentWidth))*maxContentWidth,output.substr(i,1).c_str());
        }

        //sets a cursor at the next position
        attrset(A_STANDOUT);
        mvprintw(ypos + (int) (length/maxContentWidth),xStart+length-((int) (length/maxContentWidth))*maxContentWidth, " ");
        standend();

        if(type==0) mvprintw(linkYPos,xStart, "Add a filepath to the media you would like to include!");
        int ch = getch();
        if(ch==269) getHelp(); //F5
        else if(ch==10){ //Enter
            if(length > 0) continue_looping=false;
        }
        else if(ch==263 || ch==127){ //Backspace for Mac and Linux
            if(length > 0) length--;
        }
        else if(ch==27){ //Escape
            return "";
        }
        else if(length<myMax){ //Default
            response[length] = char(ch);
            length++;
        }
    } while(continue_looping);
    return output;
}

std::string PostCreator::getLink(std::string content, std::string attemptedLink){
    //This method directly mimics get content, look at that for further assistance
    char response[type == 0 ? maxBlogLength : maxTweetLength];
    bool continue_looping;
    int length = 0;
    int ypos = 8;
    int linkYPos = ypos + maxBlogLength/maxContentWidth + 1;
    std::string output;
    do{
        continue_looping = true;
        refresh();
        clear();
        printConversationPanel(15,&groupList);
        mvprintw(3,xStart,"Please type your message here.");
        mvprintw(4,xStart,"Press Enter to move to the next field/submit.");
        mvprintw(5,xStart,"Hit ESC to close!");
        mvprintw(7,xStart,("Content:   " + std::to_string(myMax-content.length()) + "/" + std::to_string(myMax)).c_str());

        //rewriting the content to the screen
        for(int i=0; i<=content.length(); i++){
            mvprintw(ypos + (int) (i/maxContentWidth),xStart+i-((int) (i/maxContentWidth))*maxContentWidth,content.substr(i,1).c_str());
        }

        output = response;
        output = output.substr(0,length);
        for(int i=0; i<=length; i++){
            mvprintw(linkYPos + (int) (i/maxContentWidth),xStart+i-((int) (i/maxContentWidth))*maxContentWidth,output.substr(i,1).c_str());
        }

        if(type==0) mvprintw(linkYPos,xStart, "Add a filepath to the media you would like to include!");

        for(int i=0; i<=length; i++){
            mvprintw(1 + linkYPos + (int) (i/maxContentWidth),xStart+i-((int) (i/maxContentWidth))*maxContentWidth,output.substr(i,1).c_str());
        }

        if(attemptedLink.compare("")!=0){

            mvprintw(linkYPos-1, xStart, ("\'" + attemptedLink + "\' not found.").c_str());
        }

        attrset(A_STANDOUT);
        mvprintw(1 + linkYPos + (int) (length/maxContentWidth),xStart+length-((int) (length/maxContentWidth))*maxContentWidth, " ");
        standend();

        int ch = getch();
        if(ch==10){ //Enter
            continue_looping=false;
        }
        else if(ch==263 || ch==127){ //Backspace for Mac and Linux
            if(length > 0) length--;
        }
        else if(ch==27){ //Escape
            return "~~QUITTING~~";
        }
        else if(length<myMax){ //Default
            response[length] = char(ch);
            length++;
        }
    } while(continue_looping);
    return length == 0 ? "" : output; //This is here because if the User chooses to not include a link then thats okay
}

void PostCreator::getHelp(){
    std::vector<std::tuple<int, int, std::string>> *content = new std::vector<std::tuple<int, int, std::string>>();

    std::tuple<int, int, std::string> newTup (7,8,"Hello World");
    content->push_back(newTup);
    showHelpScreen(content);
}

void PostCreator::printConversationPanel(int width, std::vector<std::tuple<int,std::string>> *content){
    int currentHeight = 0;
    int messageHeight;
    std::string messagePart;

    int start = selectedGroup;

    //checks that the content will fill the screen before shifting the screen
    while(!checkGroupHeights(start,currentHeight,24,content) && start>0) start--;

    for(int i=start; i<content->size(); i++){
        std::string message = std::get<1>(content->at(i));
        if(i==selectedGroup) attrset(A_STANDOUT);

        //provides a cutoff for group names that are too long to fit
        if(message.size() > width) messagePart = message.substr(0,width-3) + "...";
        else messagePart = message;

        mvprintw(currentHeight, 2, messagePart.c_str());
        if(i==selectedGroup) attroff(A_STANDOUT);
        currentHeight += offset;
    }

    //Creates the side border
    for(int i=0; i<24; i++) mvprintw(i,2+width,"|");
}

bool PostCreator::checkGroupHeights(int current, int yStart, int height, std::vector<std::tuple<int,std::string>> *content){
    int bottomHeight = yStart;
    std::string message;
    for(int i=current; i < content->size(); i++){

        //don't actually need this next line anymore!
        message = std::get<1>(content->at(i));
        bottomHeight += offset;
    }
    return (bottomHeight+offset) > (yStart+height);
}

bool PostCreator::getGroup(bool blog){
    do{
        refresh();
        clear();
        printConversationPanel(15,&groupList);
        mvprintw(3,xStart,"Please type your message here.");
        mvprintw(4,xStart,"Press Enter to move to the next field/submit.");
        mvprintw(5,xStart,"Hit ESC to close!");
        mvprintw(7,xStart,("Content:   " + std::to_string(blog ? 500 : 250) + "/" + std::to_string(myMax)).c_str());
        if(type==0) mvprintw(9 + maxBlogLength/maxContentWidth, xStart, "Add a filepath to the media you would like to include!");

        int ch = getch();
        if(ch==10){
            return true;
        }
        else if(ch==KEY_UP && selectedGroup>0){
            selectedGroup--;
        }
        else if(ch==KEY_DOWN && selectedGroup<groupList.size()-1){
            selectedGroup++;
        }
        else if(ch==27){
            return false;
        }
    } while(true);
}

bool PostCreator::checkMedia(std::string mediaPath){
    return (access(mediaPath.c_str(), F_OK) != -1);
}

std::string PostCreator::getExtension(std::string mediaPath){
    for(int i = mediaPath.length()-1; i>=0; i--){
        if(mediaPath.substr(i,1).compare(".")==0) return mediaPath.substr(i);
    }
    return "";
}

std::string PostCreator::checkFullPath(std::string input){
    std::string output = input;
    if(input.substr(0,1).compare("~")==0){
        output = std::string(getenv("HOME"));
        output += input.substr(1);
    }
    return output;
}
