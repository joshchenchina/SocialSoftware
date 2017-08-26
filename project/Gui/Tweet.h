#ifndef TWEET_H
#define TWEET_H

#include <QMainWindow>
#include <QMessageBox>
#include "../model/User.h"


namespace Ui {
class Tweet;
}

class Tweet : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tweet(QWidget *parent = 0, User* user = NULL);
    ~Tweet();

private slots:
    /**
     * @brief Return to previous screen
     */
    void on_pushButton_clicked();

    /**
     * @brief Limitation of texts
     */
    void on_tweetEdit_textChanged();

    /**
     * @brief Submit a tweet post
     */
    void on_enterButton_clicked();


private:
    Ui::Tweet *ui;
    QString tweetPosted;
    User* user;
    void setBackground();

};

#endif // TWEET_H
