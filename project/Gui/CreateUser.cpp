#include "CreateUser.h"
#include "ui_CreateUser.h"

CreateUser::CreateUser(QWidget *parent, Admin *a) :
    QMainWindow(parent),
    ui(new Ui::CreateUser)
{
    ui->setupUi(this);
    this->admin = a;

    this->setBackground();
}

CreateUser::~CreateUser()
{
    delete ui;
}

void CreateUser::on_cancel_clicked()
{
    this->close();
}

void CreateUser::on_OK_clicked()
{
    //get the values entered by the admin
    std::string name = (ui->nameEdit->text()).toStdString();
    std::string username = (ui->usernameEdit->text()).toStdString();
    std::string password = (ui->passwordEdit->text()).toStdString();

    //first check if any field is null
    if(name !="" && username!= "" && password != "" ){
        if(admin->createNewUser(name,username,password)){//if no error from creation, then exit
            std::string error0 = "Successful! Add more users?";
            //clear all boxes
            ui->errorBox->clear();
            ui->nameEdit->clear();
            ui->usernameEdit->clear();
            ui->passwordEdit->clear();

            ui->errorBox->setText(error0.c_str());



        }
        else{//else print error message
            std::string error1 = "Username is not unique";
            ui->errorBox->clear();
            ui->errorBox->setText(error1.c_str());
        }

    }
    else{
        std::string error2 = "All fields have not been properly set";
        ui->errorBox->clear();

        ui->errorBox->setText(error2.c_str());
    }

}

void CreateUser::setBackground(){
    QPixmap bkgnd("/auto/bunter_usr11/cs205_2016_Grp00/setupFiles_HarveyRanch/test3.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
