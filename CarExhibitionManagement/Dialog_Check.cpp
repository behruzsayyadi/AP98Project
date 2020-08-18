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
//    ui->horizontalLayout_1->setEnabled(false);
//    ui->horizontalLayout_2->setEnabled(false);
}

Dialog_Check::~Dialog_Check()
{
    delete ui;
}

void Dialog_Check::on_buttonBox_accepted()
{

    accept();
}

void Dialog_Check::on_buttonBox_rejected()
{
    reject();
}
QVector<Checkinfo> Dialog_Check::getChecks()
{
//    return checks;
}
#include <QDebug>
void Dialog_Check::check_1_available(bool b)
{
    ui->horizontalLayout_1->setEnabled(b);
    qDebug() << ui->horizontalLayout_1->isEnabled();
}
void Dialog_Check::check_2_available(bool b)
{ ui->horizontalLayout_2->setEnabled(b); }
void Dialog_Check::check_3_available(bool b)
{ ui->horizontalLayout_3->setEnabled(b); }
void Dialog_Check::check_4_available(bool b)
{ ui->horizontalLayout_4->setEnabled(b); }
void Dialog_Check::check_5_available(bool b)
{ ui->horizontalLayout_5->setEnabled(b); }
