#include "Dialog_managerSingIn.h"
#include "ui_Dialog_managerSingIn.h"
#include "Manager.h"
#include <QMessageBox>
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

    ui->lineEdit_ID->setValidator(new QRegularExpressionValidator(this));
}

Dialog_managerSingIn::~Dialog_managerSingIn()
{
    delete ui;
}

void Dialog_managerSingIn::on_buttonBox_accepted()
{
    Manager mngr(getName(),getFamily(),getBirthDate(),getID(),getShShenas(),getPhoneNum(),getJob(),getJob());
    mngr.setUsername(getUsername());
    mngr.setPassword(getPassword());
    mngr.addManager();
    QMessageBox msg_box_signedIn(this);
    msg_box_signedIn.information(this,"Done","Signed In!");
    msg_box_signedIn.show();
    accept();

}

void Dialog_managerSingIn::on_buttonBox_rejected()
{
    QMessageBox msg_box_signFaild(this);
    msg_box_signFaild.warning(this,"WARNING","Sign in Faild!");
    msg_box_signFaild.show();
    reject();
}
