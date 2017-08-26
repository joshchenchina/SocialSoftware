#include "Homepage.h"
#include "ui_homepage.h"

HomePage::HomePage(QWidget *parent, User* u) :
    QMainWindow(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    this->user = u;
    this->setBackground();
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::on_LogoutButton_clicked()
{
    //make sure to quit
    if(QMessageBox::question(this, "Logout", "Are you sure to logout") == QMessageBox::Yes)
    {
        this->close();
        MainWindow* mw = new MainWindow();
        subscreen = mw;
        subscreen->show();
    }
}

void HomePage::on_TweetButton_clicked()
{
    Tweet* tw = new Tweet(NULL, user);
    subscreen = tw;
    subscreen->show();
}

void HomePage::on_MessageButton_clicked()
{
    Messaging* ms = new Messaging(NULL, user);
    subscreen = ms;
    subscreen->show();
}

void HomePage::on_viewProfile_clicked()
{
    std::string userName = (ui->userNameEdit->text()).toStdString();
    if(userName == "" || !Command::exists(userName)){//If invalid username, return error
        QMessageBox::warning(this,"ERROR","Username entered is invalid.");

    }else{//else open the profil of the user
        ViewUserProfile* vp = new ViewUserProfile(NULL,ui->userNameEdit->text());
        subscreen = vp;
        subscreen->show();
    }
}

void HomePage::on_BlogButton_clicked()
{
    BlogEditor *be = new BlogEditor(NULL, user);
    subscreen = be;
    subscreen->show();
}

void HomePage::on_profileEdit_clicked()
{
    ProfileEdit *pe = new ProfileEdit(NULL,user);
    subscreen = pe;
    subscreen->show();
}

void HomePage::setBackground(){
    QPixmap bkgnd("/auto/bunter_usr11/cs205_2016_Grp00/setupFiles_HarveyRanch/test2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

void HomePage::on_WebsiteButton_clicked()
{
    Website::createWebsite();
}
