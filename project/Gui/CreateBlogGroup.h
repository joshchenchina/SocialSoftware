#ifndef CREATEBLOGGROUP_H
#define CREATEBLOGGROUP_H

#include <QMainWindow>
#include "../model/User.h"
#include "../model/Admin.h"

namespace Ui {
class CreateBlogGroup;
}

class CreateBlogGroup : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateBlogGroup(QWidget *parent = 0,Admin * a = NULL );
    ~CreateBlogGroup();

private slots:
    /**
     * @brief Return to AdminMainMenu Screen
     */
    void on_cancelButton_clicked();

    /**
     * @brief Create new Blog group
     */
    void on_OKButton_clicked();

private:
    Ui::CreateBlogGroup *ui;
    Admin* admin;
    void setBackground();
};

#endif // CREATEBLOGGROUP_H
