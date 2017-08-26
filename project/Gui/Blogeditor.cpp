#include "Blogeditor.h"
#include "ui_blogeditor.h"

BlogEditor::BlogEditor(QWidget *parent, User* u) :
    QMainWindow(parent),
    ui(new Ui::BlogEditor)
{
    ui->setupUi(this);

    myThread = new Thread();
    connect(myThread,SIGNAL(update()),this,SLOT(onupdate()));
    myThread->start();
    this->user = u;
    this->updateGroupList();
    this->setBackground();
}

BlogEditor::~BlogEditor()
{
    delete ui;
}
void BlogEditor::updateGroupList()
{
    ui->groupListWidget->clear();
    std::vector<std::tuple<int,std::string>> groupList = Group::viewAllBlogGroups();//get the group list
    for(int i = 0; i < groupList.size(); i++){
        std::string name = (std::get<1>(groupList.at(i)));//get name of each group
        auto *item = new QListWidgetItem(name.c_str());
        QVariant v;
        v.setValue(std::get<0>(groupList.at(i)));
        item->setData(Qt::UserRole, v);
        ui->groupListWidget->addItem(item);
    }

    ui->groupListWidget->verticalScrollBar()->setSliderPosition(maximumHeight());
}

void BlogEditor::on_returnButton_clicked()
{
    //make sure to quit
    if(QMessageBox::question(this, "Quit", "Are you sure to Quit") == QMessageBox::Yes)
    {
        myThread->terminate();//end the thread first and then delete. VERY IMPORTANT

        this->close();
    }
}

void BlogEditor::on_tweetButton_clicked()
{
    //did not select a valid blog group
    if(currentGroupID == -1){
        QMessageBox::critical(this,
                              "Error",
                              "Choose a Valid Blog Group.");
    }
    else
    {
        //check to see if the user is in the group
        std::vector<int> groups  = user->getGHist()->viewGroups();
        bool found = false;
        for(int x=0; x<groups.size() && !found; x++){
            if(groups.at(x)== currentGroupID) {found = true;}
        }

        if(found){//if the user is int he group, he can write a tweet

        Tweet *t = new Tweet(NULL, user);
        subscreen = t;
        subscreen->show();
        }else{
            QMessageBox::information(this, "Error", "You cannot write to this group");
        }
    }
}

void BlogEditor::on_groupListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QVariant v = item->data(Qt::UserRole);
    currentGroupID = v.value<int>();
    this->updateBlogs();
    this->updateMediaList();
    this->updateUserList();
}

void BlogEditor::updateBlogs()
{
    ui->bloglistWidget->clear();
    std::string blogsDisplay="";
    std::vector<std::tuple<int, std::string, std::string, std::string>> blogInfo = Group::getBlogPosts(currentGroupID);//get all Blog posts of a group
    for(int i = 0; i < blogInfo.size(); i++){
        std::string author = std::get<3>(blogInfo.at(i));//get the name of the blog author
        std::string content = std::get<2>(blogInfo.at(i));//get the content of the blog
        std::string timestamp = std::get<1>(blogInfo.at(i));//get the timestamp of a blog or tweet
        blogsDisplay = blogsDisplay + author + "::" + "\n" +content + "\n" + timestamp +  "\n \n";

        auto *item = new QListWidgetItem(blogsDisplay.c_str()); //get each group id
        QVariant v;
        v.setValue(std::get<0>(blogInfo.at(i)));
        item->setData(Qt::UserRole, v);
        ui->bloglistWidget->addItem(item);
        blogsDisplay="";
    }

    ui->bloglistWidget->verticalScrollBar()->setSliderPosition(maximumHeight());

}


void BlogEditor::updateMediaList(){
    ui->mediaPosts->clear();

    std::string mediaDisplay = "";

    std::vector<std::tuple<int, std::string, std::string, std::string, std::string>> mediaInfo = Group::getMediaPosts(currentGroupID);//get all Blog posts of a group
    for(int i = 0; i < mediaInfo.size(); i++){
        std::string author = std::get<3>(mediaInfo.at(i));//get the name of the media author
        std::string content = std::get<2>(mediaInfo.at(i));//get the content of the media
        std::string timestamp = std::get<1>(mediaInfo.at(i));//get the timestamp of a media
        mediaDisplay = mediaDisplay + author + "::" + "\n" +content + "\n" + timestamp +  "\n \n";

        auto *item = new QListWidgetItem(mediaDisplay.c_str()); //get each group id
        QVariant v;
        v.setValue(std::get<0>(mediaInfo.at(i)));
        item->setData(Qt::UserRole, v);
        ui->mediaPosts->addItem(item);
        mediaDisplay="";
    }
    ui->mediaPosts->verticalScrollBar()->setSliderPosition(maximumHeight());


}

void BlogEditor::on_bloglistWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->commentlistWidget->clear();
    QVariant v = item->data(Qt::UserRole);
    currentBlogID = v.value<int>();
    this->updateComments();
}

void BlogEditor::updateComments()
{
    ui->commentlistWidget->clear();
    std::string comments = "";
    std::vector<std::tuple<int, std::string, std::string, std::string>> commentInfo = Group::getBlogComments(currentGroupID,currentBlogID);
    for(int i = 0; i < commentInfo.size(); i++){
        std::string author = std::get<3>(commentInfo.at(i));//get the name of the blog author
        std::string content = std::get<2>(commentInfo.at(i));//get the content of the blog
        std::string timestamp = std::get<1>(commentInfo.at(i));//get the timestamp of a blog or tweet
        comments = comments + author + "::" + "\n" +content + "\n" + timestamp +  "\n \n";
        //ui->commentlistWidget->addItem(setPlainText(comments.c_str());

        auto *item = new QListWidgetItem(comments.c_str()); //get each comment id
        QVariant v;
        v.setValue(std::get<0>(commentInfo.at(i)));
        item->setData(Qt::UserRole, v);
        ui->commentlistWidget->addItem(item);
        comments="";
    }
    ui->commentlistWidget->verticalScrollBar()->setSliderPosition(maximumHeight());

}

void BlogEditor::on_okButton_clicked()
{
    QString commentMessage = ui->CommentEdit->toPlainText();

    //did not select a valid blog or tweet
    if(currentBlogID == -1){
        QMessageBox::critical(this,
                              "Error",
                              "Choose a Valid Blog or Tweet.");
    }

    //Submit nothing as comment
    else if(commentMessage.toStdString() == "")
    {
        QMessageBox::critical(this,
                              "Error",
                              "Enter a Valid Comment.");
    }
    else
    {
        user->writeComment(currentGroupID, currentBlogID, commentMessage.toStdString());
        ui->CommentEdit->clear();
        this->updateComments();
    }

}

void BlogEditor::on_blogdeletionButton_clicked()
{
    if(user->deleteBlogPost("Blog", currentBlogID)){
        this->updateBlogs();
        ui->commentlistWidget->clear();
    }else{
        //error for not being author
        QMessageBox::critical(this, "Error", "You have no Authority to delete.");
    }

}

void BlogEditor::on_commentlistWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QVariant v = item->data(Qt::UserRole);
    currentCommentID = v.value<int>();
}

void BlogEditor::on_commentDeletionButton__clicked()
{
    //did not select valid comment
    if(currentCommentID == -1){
        QMessageBox::critical(this, "Error", "Please Select a Valid Comment.");
    }
    else if(user->deleteComment(currentCommentID)){//being author
        this->updateComments();
    }
    else{
        //error for not being author
        QMessageBox::critical(this, "Error", "You have no Authority to delete.");
    }
}

void BlogEditor::on_blogButton_clicked()
{
    //did not select valid group
    if(currentGroupID == -1){
        QMessageBox::critical(this, "Error", "Please Select a Valid Group.");
    }
    else{
        //check to see if the user is in the group
        std::vector<int> groups  = user->getGHist()->viewGroups();
        bool found = false;
        for(int x=0; x<groups.size() && !found; x++){
            if(groups.at(x)== currentGroupID) {found = true;}
        }

        if(found){
        Blog *b = new Blog(NULL, user,currentGroupID);
        subscreen = b;
        subscreen->show();
        }else{
            QMessageBox::critical(this, "Error", "You cannot write to this group");
        }
    }
}

void BlogEditor::on_downloadButton_clicked()
{
    //if no content selected, give an error signal.
    if(currentMediaID == -1){
        QMessageBox::critical(this, "Error", "You have not selected a Media File .");
    }else{
        //else download the file to the desktop
        std::tuple<bool,std::string> media = Group::isMedia(currentMediaID);
        if(std::get<0>(media)){//if it is a media file, copy it to the working copy
            system(("cp "+std::get<1>(media)+" ~/Downloads").c_str());
            QMessageBox::information(this, "SUCCESS", "Successfully downloaded file to Downloads folder.");



        }else{//something wrong with the path
            QMessageBox::critical(this, "Error", "Something went wrong with the file download. Please try again .");
        }




    }
}

void BlogEditor::on_mediaPosts_itemDoubleClicked(QListWidgetItem *item)
{
    QVariant v = item->data(Qt::UserRole);
    currentMediaID = v.value<int>();
}

void BlogEditor::setBackground(){
    QPixmap bkgnd("/auto/bunter_usr11/cs205_2016_Grp00/setupFiles_HarveyRanch/test3.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

void BlogEditor::onupdate(){
    if(currentGroupID !=-1){\
        ui->groupListWidget->clear();
        ui->bloglistWidget->clear();
        ui->mediaPosts->clear();
        ui->commentlistWidget->clear();

        updateGroupList();
        updateBlogs();
        updateComments();
        updateMediaList();
        updateUserList();



    }
}

void BlogEditor::updateUserList(){
    if(currentGroupID != -1){
        std::vector<std::tuple<int,std::string>> users = Group::getUsers(currentGroupID);//get all the users in that group
        std::string list = "";
        for(int i=0; i<users.size(); i++){
            list = list + std::get<1>(users.at(i)) + "\n";
        }
        ui->userList->setPlainText(list.c_str());

    }else{
        ui->userList->clear();
    }

}



