#include "CommentViewer.h"

//setting constants
int CommentViewer::maxMessageWidth = 50;
int CommentViewer::maxMessageLength = 500;

CommentViewer::CommentViewer(){

}

CommentViewer::CommentViewer(int groupID, int messageID, std::string oh, std::vector<std::tuple<int, std::string, std::string, std::string>> mc, User* u)
{
    initialize();

    offset = 2;

    //Storing information for later use
    headerInfo = oh;
    myUser = u;
    myComments = mc;
    myGroupID = groupID;
    myMessageID = messageID;

    myMessage = "";

    selectedMessage = myComments.size()-1;

    display();
    endwin();
}

void CommentViewer::display(){
    //initial print before the loop as we wait for key inputs so we do not want the screen to be
    //blank before the User hits a key
    printCommentPanel(18,&myComments);
    do {
        int ch = getch();
        switch (ch){
        case 269: //F5
            getHelp();
            return;
        case KEY_UP:
            if(selectedMessage > 0) selectedMessage--;
            break;
        case KEY_DOWN:
            if(selectedMessage < myComments.size()-1) selectedMessage++;
            break;
        case 27: //Escape
            return;

        case 330: //Delete
            if(myComments.size() > 0) deletePost();
            break;

        case 10: //Enter
            if(myMessage.compare("")!=0){
                myUser->writeComment(myGroupID,myMessageID,myMessage);
                refreshCommentList();
                myMessage = "";
            }
            break;
            //one is for Mac one is for Linux
        case 263: //Backspace
        case 127: //Backspace
            if(myMessage.length() > 0){
                myMessage = myMessage.substr(0,myMessage.length()-1);
            }
            break;
        default:
            if(myMessage.length() < maxMessageLength) myMessage += (char) ch;
            break;
        }
        printCommentPanel(18,&myComments);
    } while(true);
}

bool CommentViewer::checkMessageHeights(int current, int yStart, std::vector<std::tuple<int, std::string, std::string, std::string>> *content){
    float topHeight = yStart;
    std::string message;
    for(int i=current; i >= 0 && i > current - 20; i--){
        message = std::get<2>(content->at(i));
        topHeight -= 1 + (int) message.size() / maxMessageWidth + offset; //the one is for the author and timestamp inclusions
    }
    return (topHeight <= offset);
}

void CommentViewer::printCommentPanel(int startY, std::vector<std::tuple<int, std::string, std::string, std::string>>* content){
    clear();
    refresh();

    std::string headerInfo;
    std::string messagePart;
    std::string message;

    //This gets the height of the message that is being typed, used for offset
    int responseHeight = (int) myMessage.length()/maxMessageWidth;

    int adjustedStart = startY+1-responseHeight;

    for(int j=0; j<responseHeight+1; j++){
        //parses the messages into lines based on the messageheight/the maximum length
        messagePart = myMessage.substr(j*maxMessageWidth,maxMessageWidth);
        mvprintw(adjustedStart + offset + 2 + j, 20, messagePart.c_str());
    }

    int currentHeight = adjustedStart;
    int messageHeight;

    int start = selectedMessage;

    //moves the starting position in the array up so we can fill the screen always (as long as there are enough messages)
    while(start < content->size()-1 && !checkMessageHeights(start,20,content) ) start++;

    std::string author;

    //prints in reverse order to show oldest (index 0) at the top/last
    for(int i=start; i >=0 && i > selectedMessage - 20; i--){
        author = std::get<3>(content->at(i));
        headerInfo = author + " : " + parseTimeStamp(std::get<1>(content->at(i)));
        message = std::get<2>(content->at(i));
        messageHeight = 1 + (int) message.size()/maxMessageWidth;
        currentHeight -= messageHeight;

        //Highlights if the message being printed is also the comment the User is viewing
        if(i==selectedMessage) attrset(A_STANDOUT);

        mvprintw(currentHeight, 20, headerInfo.c_str());
        for(int j=0; j<messageHeight; j++){
            messagePart = message.substr(j*maxMessageWidth,maxMessageWidth);
            mvprintw(currentHeight + j+1, 20, messagePart.c_str());
        }
        if(i==selectedMessage) standend();

        currentHeight -= offset;
    }

    mvprintw(adjustedStart + offset + 1, 1, "Write your");
    mvprintw(adjustedStart + offset + 2, 1, "comment here ->");
    for(int i=0; i<80; i++) mvprintw(adjustedStart + offset,i,"_");
    if(selectedMessage > 0) mvprintw(9, 6, "/\\");
    if(selectedMessage < myComments.size()-1) mvprintw(11, 6, "\\/");

    //Ensures there is never just a blank screen, that's no fun
    if(content->size()==0) mvprintw(12,20,("No comments yet! Go ahead and be the first!"));

}

void CommentViewer::getHelp(){
    //A vector of tuples representing <y,x,content> to be printed to the help screen
    std::vector<std::tuple<int, int, std::string>> *content = new std::vector<std::tuple<int, int, std::string>>();

    std::tuple<int, int, std::string> tup1 (7,8,"You are writing on the");
    std::tuple<int, int, std::string> tup2 (9,8, headerInfo.c_str());
    content->push_back(tup1);
    content->push_back(tup2);
    showHelpScreen(content);
    display();
}

std::string CommentViewer::parseTimeStamp(std::string timestamp){
    return timestamp.substr(0,4) + "-" + timestamp.substr(4,2) + "-" + timestamp.substr(6,2) + " " +
            timestamp.substr(8,2) + ":" + timestamp.substr(10,2) + ":" + timestamp.substr(12,2);
}

void CommentViewer::deletePost(){
    std::string message;
    bool isAuthor = (std::get<3>(myComments.at(selectedMessage))).compare(myUser->getUsername())==0;
    if(isAuthor) message = "Are you sure you want to delete this comment? Press Y to delete it, anything else to cancel.";
    else message = "You cannot delete someone else\'s comment!";
    int responseHeight = (int) message.length()/15;


    for(int j=0; j<responseHeight+1; j++){
        mvprintw(j, 1, (message.substr(j*15,15)).c_str());
    }

    int ch = getch();
    if(ch=='y' || ch=='Y'){
        if(isAuthor){
            if(myUser->deleteComment(std::get<0>(myComments.at(selectedMessage)))){
                refreshCommentList();
            }
        }
    }
}

void CommentViewer::refreshCommentList(){
    myComments = Group::getBlogComments(myGroupID, myMessageID);
    selectedMessage = myComments.size()-1;
}
