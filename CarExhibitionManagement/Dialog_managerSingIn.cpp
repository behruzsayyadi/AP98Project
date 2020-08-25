#include "Dialog_managerSingIn.h"
#include "ui_Dialog_managerSingIn.h"
#include "Manager.h"
#include <QMessageBox>
#include <QRegExp>
QString Dialog_managerSingIn::getName()
{
    return  ui->lineEdit_name->text();
}

QString Dialog_managerSingIn::getFamily()
{
    return  ui->lineEdit_family->text();
}

QString Dialog_managerSingIn::getID()
{
    return  ui->lineEdit_ID->text();
}

QString Dialog_managerSingIn::getShShenas()
{
    return  ui->lineEdit_shShenas->text();
}

QString Dialog_managerSingIn::getPhoneNum()
{
    return  ui->lineEdit_phoneNum->text();
}

QString Dialog_managerSingIn::getJob()
{
    return  ui->lineEdit_job->text();
}

QString Dialog_managerSingIn::getJobPhone()
{
    return  ui->lineEdit_jobPhone->text();
}

QString Dialog_managerSingIn::getUsername()
{
    return  ui->lineEdit_username->text();
}

QString Dialog_managerSingIn::getPassword()
{
    return  ui->lineEdit_password->text();
}

QDate Dialog_managerSingIn::getBirthDate()
{
    return  ui->dateEdit->date();
}

Dialog_managerSingIn::Dialog_managerSingIn(QString title, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_managerSingIn)
{
    ui->setupUi(this);
    this->setWindowTitle( title );

}

Dialog_managerSingIn::~Dialog_managerSingIn()
{
    delete ui;
}

void Dialog_managerSingIn::on_buttonBox_accepted()
{
    QStringList errors = validate();
    if(errors.isEmpty()){
        Manager mngr(getName(),getFamily(),getBirthDate(),getID(),getShShenas(),getPhoneNum(),getJob(),getJobPhone());
        mngr.setUsername(getUsername());
        mngr.setPassword(getPassword());
        mngr.addManager();
        accept();
    }
    else
    {
        QString error;
        for(auto s : errors)
        {
            error += s + '\n';
        }
        QMessageBox::warning(this, "خطا", error);
    }
//    reject();
}

void Dialog_managerSingIn::on_buttonBox_rejected()
{
    QMessageBox msg_box_signFaild(this);
    msg_box_signFaild.warning(this,"WARNING","Sign in Faild!");
    msg_box_signFaild.show();
    reject();
}
QStringList Dialog_managerSingIn::validate()
{
    QString username = getUsername(), password = getPassword(), name = getName(), family = getFamily(), id = getID();
    QStringList error_list;
    if(username.isEmpty())
    {
        ui->lineEdit_username->setStyleSheet("border-color : red");
        error_list << "نام کاربری نمیتواند خالی باشد";
    }
    if(username.length() < 2 || username.length() > 30)
    {
        ui->lineEdit_username->setStyleSheet("border-color : red");
        error_list << "نام کاربری باید بین دو تا سی کاراکتر باشد";
    }
    if(password.isEmpty())
    {
        ui->lineEdit_password->setStyleSheet("border-color : red");
        error_list << "رمز عبور نمیتواند خالی باشد";
    }
    if(password.length() < 2 || password.length() > 30)
    {
        ui->lineEdit_password->setStyleSheet("border-color : red");
        error_list << "رمز عبور باید بین دو تا سی کاراکتر باشد";
    }
    if(id.isEmpty())
    {
        ui->lineEdit_ID->setStyleSheet("border-color : red");
        error_list << "شماره شناسنامه نمیتواند خالی باشد";
    }
    if(name.isEmpty())
    {
        ui->lineEdit_name->setStyleSheet("border-color : red");
        error_list << "نام نمیتواند خالی باشد";
    }
    if(family.isEmpty())
    {
        ui->lineEdit_family->setStyleSheet("border-color : red");
        error_list << "نام خانوادگی نمیتواند خالی باشد";
    }
}
