#include "Dialog_Check.h"
#include "ui_Dialog_Check.h"


//QVector<Checkinfo> Dialog_Check::getChecksVector()
//{
//    return this->check_vector;
//}

Dialog_Check::Dialog_Check(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Check)
{
    ui->setupUi(this);
}

Dialog_Check::~Dialog_Check()
{
    delete ui;
}

void Dialog_Check::on_buttonBox_accepted()
{
    if(ui->check1->isEnabled())
    {
        checks << new Checkinfo(ui->lineEdit_money->text(),
                                ui->lineEdit_bank->text(),
                                ui->lineEdit_shobe->text(),
                                ui->dateEdit->date(),
                                ui->lineEdit_shenase->text());
    }
    if(ui->check2->isEnabled())
    {
        checks << new Checkinfo(ui->lineEdit_money_2->text(),
                                ui->lineEdit_bank_2->text(),
                                ui->lineEdit_shobe_2->text(),
                                ui->dateEdit_2->date(),
                                ui->lineEdit_shenase_2->text());
    }
    if(ui->check3->isEnabled())
    {
        checks << new Checkinfo(ui->lineEdit_money_3->text(),
                                ui->lineEdit_bank_3->text(),
                                ui->lineEdit_shobe_3->text(),
                                ui->dateEdit_3->date(),
                                ui->lineEdit_shenase_3->text());
    }
    if(ui->check4->isEnabled())
    {
        checks << new Checkinfo(ui->lineEdit_money_4->text(),
                                ui->lineEdit_bank_4->text(),
                                ui->lineEdit_shobe_4->text(),
                                ui->dateEdit_4->date(),
                                ui->lineEdit_shenase_4->text());
    }
    if(ui->check5->isEnabled())
    {
        checks << new Checkinfo(ui->lineEdit_money_5->text(),
                                ui->lineEdit_bank_5->text(),
                                ui->lineEdit_shobe_5->text(),
                                ui->dateEdit_5->date(),
                                ui->lineEdit_shenase_5->text());
    }
    accept();
}

void Dialog_Check::on_buttonBox_rejected()
{
    reject();
}
QVector<Checkinfo* > Dialog_Check::getChecks()
{

    return checks;
}

