#include "Dialog_AddCheck.h"
#include "ui_Dialog_AddCheck.h"

Dialog_AddCheck::Dialog_AddCheck(QWidget *parent) :
    QDialog(parent) ,
    ui(new Ui::Dialog_AddCheck) ,
    check()
{
    ui->setupUi(this);
}

Dialog_AddCheck::~Dialog_AddCheck()
{
    delete ui;
}
bool Dialog_AddCheck::validate()
{
    bool result = true;
    if (!QRegExp("^\\d+$").exactMatch(ui->lineEdit_Money->text()))
    {
        result = false;
    }
//    if (!QRegExp("").exactMatch(ui->lineEdit_Bank->text()))
//    {
//        result = false;
//    }
//    if (!QRegExp("").exactMatch(ui->lineEdit_Shobe->text()))
//    {
//        result = false;
//    }
    if (!QRegExp("^\\d+$").exactMatch(ui->lineEdit_Shenase->text()))
    {
        result = false;
    }
//    if (ui->dateEdit->date())
//    {
//        result = false;
//    }
    return result;
}
void Dialog_AddCheck::onAcceptClicked()
{
    if(validate())
    {
        check = new Checkinfo(ui->lineEdit_Money->text(),
                              ui->lineEdit_Bank->text(),
                              ui->lineEdit_Shobe->text(),
                              ui->dateEdit->date(),
                              ui->lineEdit_Shenase->text());
//        check->setMoney(ui->lineEdit_Money->text());
//        check->setBank(ui->lineEdit_Bank->text());
//        check->setShobeBank(ui->lineEdit_Shobe->text());
//        check->setShenase(ui->lineEdit_Shenase->text());
//        check->setDate(ui->dateEdit->date());
        accept();
    }
    else
    {
        qDebug() << "failed to get check";
        reject();
    }
}
Checkinfo * Dialog_AddCheck::getCheck()
{
    return check;
}
