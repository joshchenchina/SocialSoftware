#ifndef BLOG_H
#define BLOG_H

#include <QMainWindow>
#include <QMessageBox>
#include <stdio.h>
#include "../model/Upload.h"
#include "../model/User.h"
#include <unistd.h>
namespace Ui {
class Blog;
}

class Blog : public QMainWindow
{
    Q_OBJECT

public:
    explicit Blog(QWidget *parent = 0, User* user = NULL, int groupID = -1);
    ~Blog();

private slots:

    /**
     * @brief Return to AdminMainMenu
     */
    void on_cancelButton_clicked();

    /**
     * @brief limitation of texts
     */
    void on_blogEdit_textChanged();

    /**
     * @brief Submit blog post to selected group
     */
    void on_enterButton_clicked();

    /**
     * @brief Upload files to selected group
     */
    void on_pathButton_clicked();

private:
    Ui::Blog *ui;
    QString blogPosted;
    User *user;
    QString filePath;
    std::string getExtension(std::string mediaPath);
    int currentGroupID = -1;
    void setBackground();

};

#endif // BLOG_H
