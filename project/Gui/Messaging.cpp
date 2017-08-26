#include "Messaging.h"
#include "ui_messaging.h"

Messaging::Messaging(QWidget *parent, User* u) :
    QMainWindow(parent),
    ui(new Ui::Messaging)
{
    ui->setupUi(this);
    this->user = u;
    this->updateGroupList();
    myThread = new Thread();
    connect(myThread,SIGNAL(update()),this,SLOT(onupdate()));
    myThread->start();
    this->setBackground();
}

Messaging::~Messaging()
{
    delete ui;
}

void Messaging::on_pushButton_clicked()
{
    //make sure to quit
    if(QMessageBox::question(this, "Quit", "Are you sure to quit Message?") == QMessageBox::Yes){
        myThread->terminate();//end the thread first and then delete. VERY IMPORTANT
        this->close();
    }
}

void Messaging::on_pushButton_2_clicked()
{
    //Open the Screen of Create a new Group
    CreateNewGroup* cng = new CreateNewGroup(NULL, user, currentGroupID);
    subscreen = cng;
    subscreen->show();
    ui->GrouplistWidget->clear();
}

//http://stackoverflow.com/questions/25452125/is-it-possible-to-add-a-hidden-value-to-every-item-of-qlistwidget
void Messaging::updateGroupList(){

    ui->GrouplistWidget->clear();

    //get the group list of the user
    std::vector<std::tuple<int,std::string>> groupList = Group::getGroups("Message", user->getID());
    for(int i = 0; i < groupList.size(); i++){ //go through the group list
        std::string name = (std::get<1>(groupList.at(i))); //get each group name
        auto *item = new QListWidgetItem(name.c_str()); //get each group id
        QVariant v;
        v.setValue(std::get<0>(groupList.at(i)));
        item->setData(Qt::UserRole, v);
        ui->GrouplistWidget->addItem(item);
    }

}

//http://stackoverflow.com/questions/25452125/is-it-possible-to-add-a-hidden-value-to-every-item-of-qlistwidget
void Messaging::on_GrouplistWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QVariant v = item->data(Qt::UserRole);
    currentGroupID = v.value<int>();
    this->updateMessages();
    this->updateUserList();
}

void Messaging::on_EnterButton_clicked()
{
    QString messageEntered;
    messageEntered = ui->newMessageEdit->toPlainText();//input new message
    if(messageEntered.toStdString() != "" && currentGroupID != -1){ //input valid message to valid group
        user->writeContent(currentGroupID, "Message", messageEntered.toStdString());//write contents
        ui->newMessageEdit->clear();
        this->updateMessages(); //update group message
    }
    else{//input into an invalid Group
        ui->errorBox->clear();
        ui->errorBox->setText("Please Select Group First");
    }


}

void Messaging::updateMessages(){
    if(currentGroupID !=-1){
    std::string messageDisplay="";
    std::vector<std::tuple<std::string, std::string, std::string>> groupMessages = Group::getGroupMessages(currentGroupID);//get all message history of a selected group
    for(int i = 0; i < groupMessages.size(); i++){
        std::string author = std::get<1>(groupMessages.at(i));//get the name of the message author
        std::string content = std::get<0>(groupMessages.at(i));//get the content of the message
        messageDisplay = messageDisplay + author + "::" +content + "\n \n";//Display of each message
    }
    ui->pastMessageView->clear();
    ui->pastMessageView->setPlainText(messageDisplay.c_str());
    ui->pastMessageView->verticalScrollBar()->setSliderPosition(maximumHeight());

    //ui->pastMessageView->textCursor().movePosition(QTextCursor::Start);



//    QScrollBar * qsb = ui->pastMessageView->verticalScrollBar();
//    qsb->setValue(max);
    }else{
        ui->pastMessageView->clear();
    }
}


void Messaging::on_DeleteButton_clicked()
{
    if(currentGroupID != -1){ //check if a valid group is selected
        user->leaveGroup(currentGroupID);
        ui->GrouplistWidget->clear();
        currentGroupID = -1;
        this->updateGroupList();

    }
    else{
        ui->errorBox->clear();
        ui->errorBox->setText("Please select a group to leave");
    }
}

void Messaging::on_AddUserButton_clicked()
{
    if(currentGroupID != -1){ //check if a valid group is selected
    AddNewUsertoMessageGroup *anu = new AddNewUsertoMessageGroup(NULL, currentGroupID, user); //create a screen of adding a new member into the group
    subscreen = anu;
    subscreen->show();
    }
    else{
        ui->errorBox->clear();
        ui->errorBox->setText("Please select a group to add users to");

    }
}

void Messaging::onupdate(){
    this->updateMessages();
    this->updateGroupList();
    this->updateUserList();
}

void Messaging::setBackground(){
    QPixmap bkgnd("/auto/bunter_usr11/cs205_2016_Grp00/setupFiles_HarveyRanch/test3.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

void Messaging::updateUserList(){
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
