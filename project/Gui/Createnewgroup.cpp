#include "Createnewgroup.h"
#include "ui_createnewgroup.h"

CreateNewGroup::CreateNewGroup(QWidget *parent, User* u, int id) :
    QMainWindow(parent),
    ui(new Ui::CreateNewGroup)
{
    ui->setupUi(this);
    this->user = u;
    this->groupID = id;
    this->setBackground();
}

CreateNewGroup::~CreateNewGroup()
{
    delete ui;
}

void CreateNewGroup::on_OKButton_clicked()
{
    groupname = ui->GroupNameEdit->text();
    if(groupname.toStdString() != "" && user->createMessageGroup(groupname.toStdString().c_str())){
        this->close();
    }
    else{
        //show up "Enter Valid groupName"
        ui->errorBox->setText("Please enter a valide group name");

    }
}

void CreateNewGroup::on_CancelButton_clicked()
{
    delete this;
}

void CreateNewGroup::setBackground(){
    QPixmap bkgnd("/auto/bunter_usr11/cs205_2016_Grp00/setupFiles_HarveyRanch/test3.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
