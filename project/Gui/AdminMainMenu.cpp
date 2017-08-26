#include "AdminMainMenu.h"
#include "ui_AdminMainMenu.h"

AdminMainMenu::AdminMainMenu(QWidget *parent, Admin *a) :
    QMainWindow(parent),
    ui(new Ui::AdminMainMenu)
{
    ui->setupUi(this);
    this->admin = a;
    this->setBackground();
}

AdminMainMenu::~AdminMainMenu()
{
    delete ui;
}

void AdminMainMenu::on_createUser_clicked()
{
    //open a new window for creating a user and show it
    CreateUser * createUser = new CreateUser(NULL, admin);
    subscreen = createUser;
    subscreen->show();
}

void AdminMainMenu::on_newBlogButton_clicked(bool checked)
{
    //open a new window for creating a blog group and show it
    CreateBlogGroup * createBlogGroup = new CreateBlogGroup(NULL, admin);
    subscreen = createBlogGroup;
    subscreen->show();
}

void AdminMainMenu::on_LogOutButton_pressed()
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

void AdminMainMenu::on_addUsersButton_clicked()
{
    //open a new window for adding new users and show it
    AddUsersToBlogs * usersToBlogs = new AddUsersToBlogs(NULL, admin);
    subscreen = usersToBlogs;
    subscreen->show();
}

void AdminMainMenu::setBackground(){
    QPixmap bkgnd("/auto/bunter_usr11/cs205_2016_Grp00/setupFiles_HarveyRanch/test2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
