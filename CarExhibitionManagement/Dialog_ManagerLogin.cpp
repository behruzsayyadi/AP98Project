#include <QMessageBox>
#include "Dialog_ManagerLogin.h"
#include "ui_Dialog_ManagerLogin.h"
#include "Manager.h"


QString Dialog_ManagerLogin::getUsername()
{
    return ui->lineEdit_userName->text();
}

QString Dialog_ManagerLogin::getPassword()
{
    return ui->lineEdit_password->text();
}

<<<<<<< HEAD
Dialog_ManagerLogin::Dialog_ManagerLogin(QWidget *parent) :
=======
Dialog_ManagerLogin::Dialog_ManagerLogin(QString title,QWidget *parent) :
>>>>>>> Development
    QDialog(parent),
    ui(new Ui::Dialog_ManagerLogin)
{
    ui->setupUi(this);
<<<<<<< HEAD
=======
    this->setWindowTitle(title);
>>>>>>> Development
}

Dialog_ManagerLogin::~Dialog_ManagerLogin()
{
    delete ui;
}

void Dialog_ManagerLogin::on_buttonBox_accepted()
{
    QString username , password;
    username = this->getUsername();
    password = this->getPassword();
    if(managerLogin(username,password) == false)
    {
<<<<<<< HEAD
        QMessageBox msg_box_loginFailed(this);
        msg_box_loginFailed.warning(this,"WARNING","Username or Password wrong!");
        msg_box_loginFailed.show();
        reject();
=======
        QMessageBox::warning(this, "خطا", "اطلاعات ورودی صحیح نمی باشد");
        return;
>>>>>>> Development
    }
    else
    {
        accept();
    }
}
void Dialog_ManagerLogin::on_buttonBox_rejected()
{
    reject();
}
