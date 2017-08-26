#include "Blog.h"
#include "ui_blog.h"

Blog::Blog(QWidget *parent, User* u, int groupID) :
    QMainWindow(parent),
    ui(new Ui::Blog)
{
    ui->setupUi(this);
    this->user = u;
    this->currentGroupID = groupID;
    this->setBackground();
}

Blog::~Blog()
{
    delete ui;
}


void Blog::on_cancelButton_clicked()
{
    //make sure to quit
    if(QMessageBox::question(this, "Quit", "Are you sure to quit Blog Post?") == QMessageBox::Yes){
        this->close();
    }
}

void Blog::on_blogEdit_textChanged()
{
    if(ui->blogEdit->toPlainText().length() > 500){
        QString text = ui->blogEdit->toPlainText();
        text.chop(text.length() - 500); // Cut off at 500 characters
        ui->blogEdit->setPlainText(text); // Reset text

        // This code just resets the cursor back to the end position
        // If you don't use this, it moves back to the beginning.
        // This is helpful for really long text edits where you might
        // lose your place.
        QTextCursor cursor = ui->blogEdit->textCursor();
        cursor.setPosition(ui->blogEdit->document()->characterCount() - 1);
        ui->blogEdit->setTextCursor(cursor);

        // This is your "action" to alert the user. I'd suggest something more
        // subtle though, or just not doing anything at all.
        QMessageBox::critical(this,
                              "Error",
                              "Please be sure that you keep the description under 500 characters.");
    }
}

void Blog::on_enterButton_clicked()
{
    blogPosted = ui->blogEdit->toPlainText();
    if(blogPosted.toStdString() != ""){
        bool success = true;
        if(user->writeContent(currentGroupID, "Blog", blogPosted.toStdString()) != -1){
            //works fine
            ui->blogEdit->clear();
        }
        else{
            success = false;
            QMessageBox::critical(this,"Error","A Group does not exist.");
        }
    }
    else
    {
        QMessageBox::critical(this,
                              "Error",
                              "Please Enter Valid Tweet.");
    }
}

void Blog::on_pathButton_clicked()
{
    filePath = ui->filePathEdit->text();
    blogPosted = ui->blogEdit->toPlainText();
    //check if file is valid and exists
    if((filePath.toStdString() != "" ) && std::ifstream(filePath.toStdString().c_str()))
    {

        //This blog post/tweet swhould only be added to that specific group.
        //creating a tweet from the homepage directly adds to all groups
        std::vector<std::tuple<int,std::string>> groupList = Group::getGroups("Blog", user->getID());
        bool success = true;
        std::string extension = this->getExtension(filePath.toStdString());
        std::string contentID = std::to_string(user->writeContent(currentGroupID, "Media",blogPosted.toStdString(), extension));
        if(contentID !="-1")
        {
            //works fine
            system(("cp " + filePath.toStdString() + " /auto/bunter_usr11/cs205_2016_Grp00/mediaContent_HarveyRanch/" + contentID + extension).c_str());
            ui->blogEdit->clear();
            ui->filePathEdit->clear();
        }
        else{
            QMessageBox::critical(this,"Error","Please Enter Valid File Path.");
        }
    }
    else{
        QMessageBox::critical(this,"Error","Please Enter Valid File Path.");
    }
}

std::string Blog::getExtension(std::string mediaPath){
    for(int i = mediaPath.length()-1; i>=0; i--){
        if(mediaPath.substr(i,1).compare(".")==0) return mediaPath.substr(i);
    }
}

void Blog::setBackground(){
    QPixmap bkgnd("/auto/bunter_usr11/cs205_2016_Grp00/setupFiles_HarveyRanch/test3.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
