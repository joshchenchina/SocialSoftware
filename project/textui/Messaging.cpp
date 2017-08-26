#include "Messaging.h"

//Initial constants
int Messaging::maxMessageWidth = 50;
int Messaging::conversationPanelWidth = 15;
int Messaging::maxMessageLength = 500;

Messaging::Messaging(){

}

Messaging::Messaging(User* u, QSqlDatabase *db)
{
    initialize();

    //Set's a timeout which will be used to help with the auto refresh occuring even if the user is
    //not pressing any key as the timeout happens every half of a second, note this only affects getch
    timeout(500);

    //This thread will be used to clock this messaging app
    std::thread first (&Messaging::startTimer,this);

    selectedGroup = 0;
    activeGroup = 0;
    inConvo = true;
    offset = 2;
    myDB = db;
    myUser = u;

    switchedGroups = false;
    updateMe = false;

    //The message the User is typing
    myMessage = "";

    reloadMessenger();
    //sets the selected message to the last message in the list
    selectedMessage = messageList.size()-1;
    display();

    //releases the thread
    first.detach();
    //sets the timeout back to infinity essentially, timeout can never reach a negative number
    //as it's counted upwards from 0
    timeout(-1);

    endwin();
}

void Messaging::display(){
    //Initial print so the screen is not blank
    printPanels();
    int ch;
    do {
        ch = -1; //sets to an invalid selection at the start of every selection

        while(ch==-1 && !updateMe) ch = getch();

        if(ch!=-1){ //If a key was pressed
            switch (ch){

            case 269: //F5
                getHelp();
                return;

            case KEY_UP:
                if(inConvo){ //Message Panel
                    if(selectedMessage > 0)
                        selectedMessage--;
                }
                else{ //Group Panel
                    if(selectedGroup > 0)
                        selectedGroup--;
                }
                break;

            case KEY_DOWN:
                if(inConvo){ //Conversation Panel
                    if(selectedMessage < messageList.size()-1)
                        selectedMessage++;
                }
                else{ //Group Panel
                    if(selectedGroup < groupList.size()-1)
                        selectedGroup++;
                }
                break;

            case 27: //Escape
                return;

            case 10: //Enter
                if(inConvo && myMessage.compare("")!=0){
                    myUser->writeContent(std::get<0>(groupList.at(activeGroup)), "Message", myMessage);
                    myMessage = ""; //don't want the same message to be held after sending it
                    updateMe = true;
                }
                else if(!inConvo){
                    if(selectedGroup != activeGroup){
                        activeGroup = selectedGroup;
                        updateMe = true;
                        switchedGroups = true;
                    }
                }
                break;

            case '\t': //TAB
                //switches between the group and Messaging panels
                inConvo = !inConvo;
                break;

                //backspace for Mac and Linux
            case 263:
            case 127:
                if(myMessage.length() > 0){
                    myMessage = myMessage.substr(0,myMessage.length()-1);
                }
                break;

            default:
                if(inConvo && myMessage.length() < maxMessageLength) myMessage += (char) ch;
                break;
            }
        }
        else{ //Timeout hit
            int ol = messageList.size(); //previous size
            reloadMessenger();
            populateGroups();
            populateMessages(activeGroup);
            int ne = messageList.size(); // new size
            //If the new size is greater or we switched conversations then we want to shift to
            //the most recent message
            if(ne > ol || switchedGroups) selectedMessage = messageList.size()-1;
            switchedGroups = false;
        }
        printPanels();
    } while(true);
}

void Messaging::populateMessages(int id){

    messageList = Group::getGroupMessages(std::get<0>(groupList.at(id)));

}

void Messaging::populateGroups(){

    groupList = Group::getGroups("Message",myUser->getID());

}

bool Messaging::checkMessageHeights(int current, int yStart, std::vector<std::tuple<std::string, std::string, std::string>> *content){
    //works upwards

    float topHeight = yStart;
    std::string message;
    //Iterate through a max of 20 messages subtracting the heights from the initial starting point
    for(int i=current; i >= 0 && i > current - 20; i--){
        message = std::get<0>(content->at(i));
        topHeight -= 1 + (int) message.size() / maxMessageWidth + offset; //the one is for the author and timestamp inclusions
    }
    return (topHeight <= offset);
}

bool Messaging::checkGroupHeights(int current, int yStart, int height, std::vector<std::tuple<int,std::string>> *content){
    //works downwards
    int bottomHeight = yStart;
    std::string message;

    //CHANGE THIS TO ONLY TAKE CONTENT SIZE AS GROUP NAMES ARE RESTRICTED TO 1 LINE A PIECE
    for(int i=current; i < content->size(); i++){
        message = std::get<1>(content->at(i));
        bottomHeight += offset;
    }
    return (bottomHeight+offset) > (yStart+height);
}

void Messaging::printMessagePanel(int startY, std::vector<std::tuple<std::string, std::string, std::string>>* content){
    std::string headerInfo;
    std::string messagePart;
    std::string message;

    //The total height of the soon to be wrapped message
    int responseHeight = (int) myMessage.length()/maxMessageWidth;
    int adjustedStart = startY+1-responseHeight;

    for(int j=0; j<responseHeight+1; j++){
        messagePart = myMessage.substr(j*maxMessageWidth,maxMessageWidth);
        mvprintw(adjustedStart + offset + 2 + j, 28, messagePart.c_str());
    }

    int currentHeight = adjustedStart;
    int messageHeight;

    int start = selectedMessage;

    //Adjusts the start in case there are not enough messages in the list to fill the screen
    while(start < content->size()-1 && !checkMessageHeights(start,20,content) ) start++;

    std::string author;
    bool left;

    for(int i=start; i >=0 && i > selectedMessage - 20; i--){//&& i > selectedMessage - 20
        author = std::get<1>(content->at(i));

        //This boolean is to determine the orientation for others messages and your own
        left = author.compare(myUser->getUsername()) != 0;

        headerInfo = author + " : " + parseTimeStamp(std::get<2>(content->at(i)));
        message = std::get<0>(content->at(i));
        messageHeight = 1 + (int) message.size()/maxMessageWidth;
        currentHeight -= messageHeight;

        if(inConvo && i==selectedMessage) attrset(A_STANDOUT);

        mvprintw(currentHeight, (left ? 20 : 28), headerInfo.c_str());

        //Prints the message parts
        for(int j=0; j<messageHeight; j++){
            messagePart = message.substr(j*maxMessageWidth,maxMessageWidth);
            mvprintw(currentHeight + j+1, (left ? 20 : 28), messagePart.c_str());
        }
        if(inConvo && i==selectedMessage) standend();

        //shift up based on vertical buffer
        currentHeight -= offset;
    }

    for(int i=conversationPanelWidth+3; i<80; i++) mvprintw(adjustedStart + offset,i,"_");
    if(selectedMessage > 0) mvprintw(adjustedStart + offset + 1, 22, "/\\");
    if(selectedMessage < messageList.size()-1) mvprintw(23, 22, "\\/");
}

void Messaging::printConversationPanel(int width, std::vector<std::tuple<int,std::string>> *content){
    int currentHeight = 0;
    int messageHeight;
    std::string messagePart;

    int start = activeGroup;

    //Same idea as the previous method!
    while(!checkGroupHeights(start,currentHeight,24,content) && start>0) start--;

    for(int i=start; i<content->size(); i++){ // && currentHeight<24
        std::string message = std::get<1>(content->at(i));
        if((inConvo && i==activeGroup) || (!inConvo && i==selectedGroup)) attrset(A_STANDOUT);
        if(message.size() > width) messagePart = message.substr(0,width-3) + "...";
        else messagePart = message;
        mvprintw(currentHeight, 2, messagePart.c_str());
        if((inConvo && i==activeGroup) || (!inConvo && i==selectedGroup)) attroff(A_STANDOUT);
        currentHeight += offset;
    }
    for(int i=0; i<24; i++) mvprintw(i,2+width,"|");
}

void Messaging::printPanels(){
    clear();
    refresh();
    printMessagePanel(18,&messageList);
    printConversationPanel(conversationPanelWidth,&groupList);
}

void Messaging::getHelp(){
    std::vector<std::tuple<int, int, std::string>> *content = new std::vector<std::tuple<int, int, std::string>>();

    std::tuple<int, int, std::string> newTup (7,8,"Hello World");
    content->push_back(newTup);
    showHelpScreen(content);
    display();
}

void Messaging::reloadMessenger(){
    populateGroups();
    populateMessages(activeGroup);
    updateMe = false;
}

void Messaging::startTimer(Messaging* m){
    while(true){
        std::this_thread::sleep_for(std::chrono::seconds(5));
        //We only wanna set the update signal to be true if the app didnt just update itself
        if(!m->getUpdateMe()) m->setUpdateMe(true);
    }
}

bool Messaging::getUpdateMe(){
    return updateMe;
}

void Messaging::setUpdateMe(bool set){
    updateMe = set;
}

std::string Messaging::parseTimeStamp(std::string timestamp){
    return timestamp.substr(0,4) + "-" + timestamp.substr(4,2) + "-" + timestamp.substr(6,2) + " " +
            timestamp.substr(8,2) + ":" + timestamp.substr(10,2) + ":" + timestamp.substr(12,2);
}
