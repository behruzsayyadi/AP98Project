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

Dialog_ManagerLogin::Dialog_ManagerLogin(QString title,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ManagerLogin)
{
    ui->setupUi(this);
    this->setWindowTitle(title);
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
        QMessageBox::warning(this, "خطا", "اطلاعات ورودی صحیح نمی باشد");
        return;
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
