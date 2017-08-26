#ifndef BLOGEDITOR_H
#define BLOGEDITOR_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "../model/User.h"
#include "Tweet.h"
#include "Blog.h"
#include "Thread.h"
#include <QScrollBar>

namespace Ui {
class BlogEditor;
}

class BlogEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit BlogEditor(QWidget *parent = 0, User* user = NULL);
    ~BlogEditor();
    Thread *myThread;
private slots:

    /**
     * @brief Quit Message
     */
    void on_returnButton_clicked();

    /**
     * @brief Create a new Tweet post
     */
    void on_tweetButton_clicked();

    /**
     * @brief Select a group
     */
    void on_groupListWidget_itemDoubleClicked(QListWidgetItem *item);

    /**
     * @brief Select a blog or tweet
     */
    void on_bloglistWidget_itemDoubleClicked(QListWidgetItem *item);

    /**
     * @brief Submit a Comment to a blog or tweet
     */
    void on_okButton_clicked();

    /**
     * @brief Delete an existing Blog or Tweet
     */
    void on_blogdeletionButton_clicked();

    /**
     * @brief Select a Comment
     */
    void on_commentlistWidget_itemDoubleClicked(QListWidgetItem *item);

    /**
     * @brief Delete a Comment
     */
    void on_commentDeletionButton__clicked();

    /**
     * @brief Create a new Blog post
     */
    void on_blogButton_clicked();

    /**
     * @brief Download certain file from selected group
     */
    void on_downloadButton_clicked();

    /**
     * @brief Select posted file
     */
    void on_mediaPosts_itemDoubleClicked(QListWidgetItem *item);


public slots:
    void onupdate();


private:
    Ui::BlogEditor *ui;
    User *user;
    void updateGroupList();
    QMainWindow* subscreen;


    void updateMediaList();

    /**
     * @brief Update the tweets and blogs
     */
    void updateBlogs();

    /**
     * @brief Update Comments
     */
    void updateComments();

    /**
     * @brief updateUserList lists the users in that blog group
     */
    void updateUserList();

    void setBackground();

    int currentGroupID = -1;
    int currentBlogID = -1;
    int currentCommentID = -1;
    int currentMediaID = -1;
};

#endif // BLOGEDITOR_H
