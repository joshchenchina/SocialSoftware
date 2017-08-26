#include "CreateBlogGroup.h"
#include "ui_CreateBlogGroup.h"

CreateBlogGroup::CreateBlogGroup(QWidget *parent, Admin *a) :
    QMainWindow(parent),
    ui(new Ui::CreateBlogGroup)
{
    ui->setupUi(this);
    this->admin = a;
    this->setBackground();
}

CreateBlogGroup::~CreateBlogGroup()
{
    delete ui;
}

void CreateBlogGroup::on_cancelButton_clicked()
{
    this->close();
}



void CreateBlogGroup::on_OKButton_clicked()
{
    std::string groupName  = (ui->groupNameEdit->text()).toStdString();
    ui->errorText->clear();

    if(groupName != ""){//if name is valid, create new blog group
        admin->createNewBlogGroup(groupName);
        delete this;
    }
    else{//otherwise display error
        std::string error = "The name you have typed is not valid";
        ui->errorText->setText(error.c_str());
    }
}

void CreateBlogGroup::setBackground(){
    QPixmap bkgnd("/auto/bunter_usr11/cs205_2016_Grp00/setupFiles_HarveyRanch/test3.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
