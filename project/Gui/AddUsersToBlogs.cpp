#include "AddUsersToBlogs.h"
#include "ui_AddUsersToBlogs.h"

AddUsersToBlogs::AddUsersToBlogs(QWidget *parent, Admin * a) :
    QMainWindow(parent),
    ui(new Ui::AddUsersToBlogs)
{
    ui->setupUi(this);
    this->admin = a;
    this->updateList();
    this->setBackground();
}

AddUsersToBlogs::~AddUsersToBlogs()
{
    delete ui;
}

void AddUsersToBlogs::on_cancelButton_clicked()
{
    this->close();
}

void AddUsersToBlogs::on_GroupList_itemDoubleClicked(QListWidgetItem *item)
{
    //select the group and place the group on the label. Store that group id
    QVariant v = item->data(Qt::UserRole);
    currentGroupID = v.value<int>();

    //reset the name of the active group
    ui->GroupName->clear();
    ui->GroupName->setText( item->text());


}

void AddUsersToBlogs::on_addUserButton_clicked()
{
    //if clicked with no group selected, give error.
    if(currentGroupID != -1){
        std::string userName = (ui->username->text()).toStdString();
        if(admin->addUsers(currentGroupID,userName)){//iff successfully added user
            //clear username space and print message
            ui->username->clear();
            std::string error0 = "User added successfully! Add another?";
            ui->errorBox->clear();
            ui->errorBox->setText(error0.c_str());

        }else{//else print error that user is invalid
            std::string error1 = "Username does not exist";
            ui->errorBox->clear();
            ui->errorBox->setText(error1.c_str());
        }

    }else{
        //error for no group selected
        std::string error2 = "Please selecet a group";
        ui->errorBox->clear();
        ui->errorBox->setText(error2.c_str());
    }

}

void AddUsersToBlogs::on_pushButton_clicked()
{
    //make sure to delete
    if(currentGroupID !=-1){
        if(QMessageBox::question(this, "Quit", "Are you sure to delete this group?") == QMessageBox::Yes){
            admin->leaveGroup(currentGroupID);
            ui->GroupList->clear();
            this->updateList();
        }
    }else{
        QMessageBox::information(this,"Invlaid Group", "Please select a group to delete");
    }
}

void AddUsersToBlogs::updateList(){
    //update the group list shown in the group ist widget
    std::vector<std::tuple<int,std::string>> groupList = Group::getGroups("Blog", admin->getID());
    for(int i = 0; i < groupList.size(); i++){
        std::string name = (std::get<1>(groupList.at(i)));
        //store the data in an item data = groupID
        auto *item = new QListWidgetItem(name.c_str());
        QVariant v;
        v.setValue(std::get<0>(groupList.at(i)));
        item->setData(Qt::UserRole, v);
        //add item to the group list widget
        ui->GroupList->addItem(item);
    }
}

void AddUsersToBlogs::setBackground(){
    QPixmap bkgnd("/auto/bunter_usr11/cs205_2016_Grp00/setupFiles_HarveyRanch/test3.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
