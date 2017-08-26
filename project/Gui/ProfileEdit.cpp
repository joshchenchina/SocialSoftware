#include "ProfileEdit.h"
#include "ui_ProfileEdit.h"

ProfileEdit::ProfileEdit(QWidget *parent, User *u) :
    QMainWindow(parent),
    ui(new Ui::ProfileEdit)
{
    ui->setupUi(this);
    user = u;
    this->setBackground();
}

ProfileEdit::~ProfileEdit()
{
    delete ui;
}

void ProfileEdit::on_changeName_clicked()
{
    std::string newName = ui->newName->text().toStdString();
    if(newName == ""){
        //error box
        QMessageBox::warning(this,"ERROR","Please enter a valid name");
    }else{
        user->setName(newName);
        ui->newName->clear();
        std::string nameChangeMessage= "Name change to "+newName+" successful!";
        QMessageBox::information(this,"SUCCESS!",nameChangeMessage.c_str());
        //message box for confirmation
    }
}

void ProfileEdit::on_changePassword_clicked()
{
    std::string oldPass = ui->oldPassword->text().toStdString();
    std::string newPass = ui->newPassword->text().toStdString();
    std::string confirmPass = ui->confirmPassword->text().toStdString();

    if(oldPass != user->getPassword() || newPass=="" || newPass != confirmPass){
        //error box
        QMessageBox::warning(this,"ERROR","Either your current password is not correct or your new password does not match.");

    }
    else{
        user->setPassword(newPass);
        QMessageBox::information(this,"SUCCESS!","Password Successfully changed!");
    }
    //clear the texts
    ui->confirmPassword->clear();
    ui->oldPassword->clear();
    ui->newPassword->clear();
}

//close screen
void ProfileEdit::on_pushButton_3_clicked()
{
    this->close();
}

void ProfileEdit::setBackground(){
    QPixmap bkgnd("/auto/bunter_usr11/cs205_2016_Grp00/setupFiles_HarveyRanch/test3.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
