#include "mainwindow.h"
#include "ui_mainwindow.h"

QSqlDatabase MainWindow::database;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setBackground();
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_QuitButton_clicked()
{
    //make sure to quit
    if(QMessageBox::question(this, "Quit", "Are you sure to quit?") == QMessageBox::Yes){
        QString connection;
        connection = database.connectionName();
        database.close();
        database = QSqlDatabase();
        database.removeDatabase(connection);
        QSqlDatabase::database().removeDatabase("default");
        this->close();
    }
}

void MainWindow::on_SignInButton_clicked()
{
    username = ui->UsernameDisplay->text(); //input username
    password = ui->PasswordDisplay->text(); //input password

    QSqlDatabase *db = &database;

    //check database if the combination of username and password is correct
    std::tuple<bool, bool> loginVerify = Command::loginVerification(username.toStdString(), password.toStdString());
    if(std::get<0>(loginVerify)){//check if the account exists
        if(std::get<1>(loginVerify)){
            //admin login
            Admin * admin = new Admin(*db,username.toStdString(), password.toStdString());
            AdminMainMenu* adminMenu = new AdminMainMenu(NULL, admin);
            subscreen = adminMenu;
            delete this;
            subscreen->show();

        }
        else{
            //User login
            User *newUser = new User(*db, username.toStdString(), password.toStdString());
            HomePage* newHomePage = new HomePage(NULL, newUser);
            subscreen = newHomePage;
            delete this;
            subscreen->show();
        }
    }
    else{
        QMessageBox::critical(this, "Error", "The Username of Password Not Found!");
    }
}

void MainWindow::setBackground(){
    QPixmap bkgnd("/auto/bunter_usr11/cs205_2016_Grp00/setupFiles_HarveyRanch/test1.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
