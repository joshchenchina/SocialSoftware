#include "ViewUserProfile.h"
#include "ui_ViewUserProfile.h"

ViewUserProfile::ViewUserProfile(QWidget *parent, QString userName) :
    QMainWindow(parent),
    ui(new Ui::ViewUserProfile)
{
    ui->setupUi(this);
    this->userName = userName;

    myThread = new Thread();
    connect(myThread,SIGNAL(update()),this,SLOT(onupdate()));
    myThread->start();


}

ViewUserProfile::~ViewUserProfile()
{
    delete ui;
}

void ViewUserProfile::on_cancelButton_clicked()
{
    myThread->terminate();//end the thread first and then delete. VERY IMPORTANT

    this->close();
}

void ViewUserProfile::onupdate(){
    ui->uploadList->clear();

    ui->uploadList->setWordWrap(true);
    ui->uploadList->setTextElideMode(Qt::ElideNone);

    //   ui->uploadList->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);

    //display the name of the user at the top
    std::string name = Command::nameOfUser(userName.toStdString());
    ui->nameOfUser->setText(name.c_str());



    //get the posts made by the user in the blog groups
    std::vector<std::tuple<std::string,std::string>> uploads = Group::viewUserUploads(userName.toStdString());
    for(signed int i=uploads.size()-1; i>=0;i--){
        std::string timestamp = std::get<0>(uploads.at(i));
        std::string content = std::get<1>(uploads.at(i));

        std::string post = timestamp+"\n \t"+content;

        //add the timseatmp and post to the listwidget
        ui->uploadList->addItem(post.c_str());
    }
}
