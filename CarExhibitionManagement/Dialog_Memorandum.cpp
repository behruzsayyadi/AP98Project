#include "Dialog_Memorandum.h"
#include "ui_Dialog_Memorandum.h"

Dialog_Memorandum::Dialog_Memorandum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Memorandum)
{
    ui->setupUi(this);
}

Dialog_Memorandum::~Dialog_Memorandum()
{
    delete ui;
}

void Dialog_Memorandum::on_radioButton_mngr_yes_clicked()
{
//    ui->groupBox_customer->hide();
    ui->groupBox_customer->setEnabled(false);
    ui->groupBox_customer->setTitle("Manager");
}

void Dialog_Memorandum::on_radioButton_mngr_no_clicked()
{
//    ui->groupBox_customer->show();
    ui->groupBox_customer->setEnabled(true);
    ui->groupBox_customer->setTitle("Customer");
}

void Dialog_Memorandum::on_radioButton_check_yes_clicked()
{
//    ui->groupBox_check->show();
    ui->groupBox_check->setEnabled(true);
}

void Dialog_Memorandum::on_radioButton_check_no_clicked()
{
    ui->groupBox_check->setEnabled(false);
//    ui->groupBox_check->hide();
}

void Dialog_Memorandum::on_buttonBox_accepted()
{

}

void Dialog_Memorandum::getNewChecks()
{
    Dialog_Check * d = new Dialog_Check(this);
    if(d->exec() == Dialog_Check::Accepted)
    {

    }
}

