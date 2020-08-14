#include "Widget_signin.h"
#include "ui_Widget_signin.h"
#include <QDebug>

Widget_signin::Widget_signin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_signin),
    username_regExp{ "^[a-z]{4,10}\\d{0,6}$" },
    password_regExp{ "^$" }
{
    ui->setupUi(this);
    connect(ui->pushButton_signin, &QPushButton::clicked,
            [this]{
                    QString username = ui->lineEdit_username->text(),
                            password = ui->lineEdit_password->text();

                    switch( validateSigninInfo(username, password) )
                    {
                    case 0://ok
                        if( signin(username, password) )
                            emit signinSuccessful();
                        else;
                        break;
                    case 1://username problem;
                        break;
                    case 2://password problem
                        break;
                    }
                });

}

Widget_signin::~Widget_signin()
{
    delete ui;
}

bool Widget_signin::signin(QString username, QString password)
{
    return true;
}
int Widget_signin::validateSigninInfo(QString username, QString password)
{
    //DEBUG:
    return 0;
    //
    if( username_regExp.exactMatch( username ) )
    {
        if( password_regExp.exactMatch( password ) )
        {
            return 0;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }

}
