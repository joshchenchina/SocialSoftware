#include "Tweet.h"
#include "ui_tweet.h"

Tweet::Tweet(QWidget *parent, User* u) :
    QMainWindow(parent),
    ui(new Ui::Tweet)
{
    ui->setupUi(this);
    this->user = u;
    this->setBackground();
}

Tweet::~Tweet()
{
    delete ui;
}

void Tweet::on_pushButton_clicked()
{
    //make sure to quit
    if(QMessageBox::question(this, "Quit", "Are you sure to quit Tweet Post?") == QMessageBox::Yes){
        this->close();
    }
}

//https://contingencycoder.wordpress.com/2013/07/05/quick-tip-limit-character-count-in-a-qtextedit/
void Tweet::on_tweetEdit_textChanged()
{
    if(ui->tweetEdit->toPlainText().length() > 250){
        QString text = ui->tweetEdit->toPlainText();
        text.chop(text.length() - 250); // Cut off at 250 characters
        ui->tweetEdit->setPlainText(text); // Reset text

        // This code just resets the cursor back to the end position
        // If you don't use this, it moves back to the beginning.
        // This is helpful for really long text edits where you might
        // lose your place.
        QTextCursor cursor = ui->tweetEdit->textCursor();
        cursor.setPosition(ui->tweetEdit->document()->characterCount() - 1);
        ui->tweetEdit->setTextCursor(cursor);

        // This is your "action" to alert the user. I'd suggest something more
        // subtle though, or just not doing anything at all.
        QMessageBox::critical(this,
                              "Error",
                              "Please be sure that you keep the description under 250 characters.");
    }
}

void Tweet::on_enterButton_clicked()
{
    tweetPosted = ui->tweetEdit->toPlainText();
    if(tweetPosted.toStdString() != ""){
        bool success = true;
        std::vector<std::tuple<int,std::string>> groupList = Group::getGroups("Blog", user->getID());//get grouplist
        for(int i = 0; i < groupList.size() && success; i++){
            int groupID = std::get<0>(groupList.at(i));//get id
//            user->writeContent(groupID, "Blog", tweetPosted.toStdString());
            if(user->writeContent(groupID, "Blog", tweetPosted.toStdString()) != -1){
                //works fine
                ui->tweetEdit->clear();
            }
            else{//the group is invalid
                success = false;
                QMessageBox::critical(this,"Error","A Group does not exist.");
            }
        }
    }
    else    //submit nothing as new post
    {
        QMessageBox::critical(this,"Error","Please Enter Valid Tweet.");
    }
}

void Tweet::setBackground(){
    QPixmap bkgnd("/auto/bunter_usr11/cs205_2016_Grp00/setupFiles_HarveyRanch/test3.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

