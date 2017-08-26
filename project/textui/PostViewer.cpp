#include "PostViewer.h"

int PostViewer::maxMessageWidth = 50;

//id, timeStamp, content, author
//std::vector<std::tuple<int, std::string, std::string, std::string>> tup = Group::getBlogPosts(groupList.at(selectedGroup));

PostViewer::PostViewer(){

}

PostViewer::PostViewer(User* u, QSqlDatabase *db)
{
    initialize();
    myDB = db;
    myUser = u;

    //we start in the first message group
    inMessages = true;
    offset = 2;
    options = 5;

    selectedGroup = 0;
    activeGroup = 0;

    populateGroups();
    populateBlogPosts();

    selectedBlogPost = blogPostList.size()-1;

    display();
    endwin();
}

void PostViewer::display(){
    printPanels();
    do {
        int ch = getch();

        switch (ch){
        case 269:
            getHelp();
            return;
        case KEY_UP:
            if(inMessages){
                if(selectedBlogPost > 0) selectedBlogPost--;
            }
            else{
                if(selectedGroup > 0) selectedGroup--;
            }
            break;
        case KEY_DOWN:
            if(inMessages){
                if(selectedBlogPost < blogPostList.size()-1){
                    selectedBlogPost++;
                }
            }
            else{
                if(selectedGroup < groupList.size()-1){
                    selectedGroup++;
                }
            }
            break;

        case 10: //Enter
            //switching groups
            if(!inMessages) activeGroup = selectedGroup;
            else{
                currentAuthor = std::get<3>(blogPostList.at(selectedBlogPost));
                //group ID
                int gID = std::get<0>(groupList.at(activeGroup));
                //Post ID
                int mID = std::get<0>(blogPostList.at(selectedBlogPost));

                std::vector<std::tuple<int, std::string, std::string, std::string>> mc = Group::getBlogComments(gID, mID);

                std::string header = "Post from \'" + currentAuthor + "\' on " +
                        parseTimeStamp(std::get<1>(blogPostList.at(selectedBlogPost)));

                CommentViewer *v = new CommentViewer(gID, mID, header, mc, myUser);
            }
            break;

        case 27: //Escape
            return;

        case 330: //DELETE
            deleteComment();
            break;

        case '\t': //TAB
            inMessages = !inMessages;
            break;
        }
        //We want to do this after every action because we always want to ensure
        //we don't accidentally allow for deletion of someone else's contributions
        currentAuthor = std::get<3>(blogPostList.at(selectedBlogPost));

        printPanels();
    } while(true);
}

void PostViewer::populateBlogPosts(){

    blogPostList = Group::getBlogPosts(std::get<0>(groupList.at(activeGroup)));

}

void PostViewer::populateGroups(){

    groupList = Group::getGroups("Blog",myUser->getID());

}

bool PostViewer::checkGroupHeights(int current, int yStart, int height, std::vector<std::tuple<int,std::string>> *content){
    int bottomHeight = yStart;
    std::string message;
    for(int i=current; i < content->size(); i++){
        message = std::get<1>(content->at(i));
        bottomHeight += offset;
    }
    return (bottomHeight+offset) > (yStart+height);
}

void PostViewer::printMessagePanel(int startY, std::vector<std::tuple<int, std::string, std::string, std::string>>* content){
    int currentHeight = startY+1;
    int messageHeight;
    std::string messagePart;

    std::string message = content->size()==0 ? "There haven't been any posts yet!" : std::get<2>(content->at(selectedBlogPost));
    messageHeight = (int) message.size()/maxMessageWidth;
    currentHeight -= messageHeight;

    if(selectedBlogPost > 0) mvprintw(startY-1, 20, "/\\");
    if(selectedBlogPost < content->size()-1) mvprintw(startY+messageHeight+1, 20, "\\/");

    if(content->size()>0) mvprintw(startY-2,24,("Post from : " + std::get<3>(content->at(selectedBlogPost))).c_str());

    if(inMessages) attrset(A_STANDOUT);

    for(int j=0; j<messageHeight+1; j++){
        messagePart = message.substr(j*maxMessageWidth,maxMessageWidth);
        mvprintw(startY+j, 24, messagePart.c_str());
    }

    if(inMessages) standend();

    if(content->size()>0) mvprintw(startY+messageHeight+2,24, parseTimeStamp(std::get<1>(content->at(selectedBlogPost))).c_str());
}

void PostViewer::printConversationPanel(int width, std::vector<std::tuple<int,std::string>> *content){
    int currentHeight = 0;
    int messageHeight;
    std::string messagePart;

    int start = selectedGroup;

    while(!checkGroupHeights(start,currentHeight,24,content) && start>0) start--;

    for(int i=start; i<content->size(); i++){ // && currentHeight<24
        std::string message = std::get<1>(content->at(i));
        if((inMessages && i==activeGroup) || (!inMessages && i==selectedGroup)) attrset(A_STANDOUT);
        if(message.size() > width) messagePart = message.substr(0,width-3) + "...";
        else messagePart = message;
        mvprintw(currentHeight, 2, messagePart.c_str());
        if((inMessages && i==activeGroup) || (!inMessages && i==selectedGroup)) standend();
        currentHeight += offset;
    }
    for(int i=0; i<24; i++) mvprintw(i,2+width,"|");
}

void PostViewer::printPanels(){
    clear();
    refresh();
    printMessagePanel(8,&blogPostList);
    printConversationPanel(15,&groupList);
}

void PostViewer::getHelp(){
    std::vector<std::tuple<int, int, std::string>> *content = new std::vector<std::tuple<int, int, std::string>>();

    std::tuple<int, int, std::string> newTup (7,8,"Hello World");
    content->push_back(newTup);
    showHelpScreen(content);
    display();
}

std::string PostViewer::parseTimeStamp(std::string timestamp){
    return timestamp.substr(0,4) + "-" + timestamp.substr(4,2) + "-" + timestamp.substr(6,2) + " " +
            timestamp.substr(8,2) + ":" + timestamp.substr(10,2) + ":" + timestamp.substr(12,2);
}

void PostViewer::deleteComment(){
    std::string message;
    bool isAuthor = currentAuthor.compare(myUser->getUsername())==0;
    if(isAuthor) message = "Are you sure you want to delete this post? Press Y to delete it, anything else to cancel.";
    else message = "You cannot delete someone else\'s post!";
    int responseHeight = (int) message.length()/40;

    for(int j=0; j<responseHeight+1; j++){
        mvprintw(20+j, 20, (message.substr(j*40,40)).c_str());
    }

    int ch = getch();
    if(ch=='y' || ch=='Y'){
        if(isAuthor){
            if(myUser->deleteBlogPost("Blog",std::get<0>(blogPostList.at(selectedBlogPost)))){
                populateBlogPosts();
                selectedBlogPost = blogPostList.size()-1;
            }
        }
    }
}
