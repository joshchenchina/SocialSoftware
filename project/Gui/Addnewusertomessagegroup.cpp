#include "Addnewusertomessagegroup.h"
#include "ui_addnewusertomessagegroup.h"

AddNewUsertoMessageGroup::AddNewUsertoMessageGroup(QWidget *parent, int groupID, User *user) :
    QMainWindow(parent),
    ui(new Ui::AddNewUsertoMessageGroup)
{
    ui->setupUi(this);
    this->currentGroupID = groupID;
    this->u = user;
    this->setBackground();//setting background

}

AddNewUsertoMessageGroup::~AddNewUsertoMessageGroup()
{
    delete ui;
}


void AddNewUsertoMessageGroup::on_cancelButton_2_clicked()
{
    this->close();
}

void AddNewUsertoMessageGroup::on_okButton_2_clicked()
{
    username = ui->usernameEdit_2->text();
    if(u->addUsers(currentGroupID,username.toStdString())){//if username is there, add user and delete the current window
        delete this;
    }
    else{
        ui->errorBox->setText("Please enter a valid username");
    }
}

void AddNewUsertoMessageGroup::setBackground(){
    QPixmap bkgnd("/auto/bunter_usr11/cs205_2016_Grp00/setupFiles_HarveyRanch/test3.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
