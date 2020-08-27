#include "Dialog_AddCheck.h"
#include "ui_Dialog_AddCheck.h"
#include <QMessageBox>
Dialog_AddCheck::Dialog_AddCheck(QWidget *parent) :
    QDialog(parent) ,
    ui(new Ui::Dialog_AddCheck) ,
    check()
{
    ui->setupUi(this);
    this->setWindowTitle("چک جدید");

}

Dialog_AddCheck::~Dialog_AddCheck()
{
    delete ui;
}
QStringList Dialog_AddCheck::validate()
{
    QStringList errors;
    if (!QRegExp("^\\d+$").exactMatch(ui->lineEdit_Money->text()))
    {
        ui->lineEdit_Money->setStyleSheet("border: 2px solid red");
        errors << "مبلغ چک باید به عدد وارد شود و نباید هالی باشد";
    }
    if (!QRegExp("^\\d+$").exactMatch(ui->lineEdit_Shenase->text()))
    {
        ui->lineEdit_Shenase->setStyleSheet("border: 2px solid red");
        errors << "شناسه ی چک باید به عدد وارد شود و نباید خالی باشد";
    }
    return errors;
}
void Dialog_AddCheck::onAcceptClicked()
{
    QString error;
    for(auto s : validate())
    {
        error += s + '\n';
    }
    if(error.isEmpty())
    {
        check = new Checkinfo(ui->lineEdit_Money->text(),
                              ui->lineEdit_Bank->text(),
                              ui->lineEdit_Shobe->text(),
                              ui->dateEdit->date(),
                              ui->lineEdit_Shenase->text());
        accept();
    }
    else
    {
        QMessageBox::warning(this, "خطای کاربر", error);
        return;
    }
}
Checkinfo * Dialog_AddCheck::getCheck()
{
    return check;
}
