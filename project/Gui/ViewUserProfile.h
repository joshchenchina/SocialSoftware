#ifndef VIEWUSERPROFILE_H
#define VIEWUSERPROFILE_H

#include <QWidget>
#include <QString>
#include <QMainWindow>

#include <QApplication>
#include <QCoreApplication>
#include <QtSql>
#include "mainwindow.h"
#include "Thread.h"
#include "../model/User.h"
#include "../model/Group.h"
#include "../model/Command.h"

namespace Ui {
class ViewUserProfile;
}

class ViewUserProfile : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewUserProfile(QWidget *parent = 0,QString userName = "");
    ~ViewUserProfile();
    Thread *myThread;

private slots:
    /**
     * @brief Return to previous screen
     */
    void on_cancelButton_clicked();

public slots:
    void onupdate();

private:
    Ui::ViewUserProfile *ui;
    QString userName;

};

#endif // VIEWUSERPROFILE_H
