#include "Dialog_AddIncome.h"
#include "ui_Dialog_AddIncome.h"

Dialog_AddIncome::Dialog_AddIncome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddIncome)
{
    ui->setupUi(this);
    QLocale c(QLocale::English);
    for( int i = 1, max_months = QDate::currentDate().month(); i <= max_months; i++ )
    {
        ui->comboBox_Month->addItem(c.monthName(i));
    }
}

Dialog_AddIncome::~Dialog_AddIncome()
{
    delete ui;
}
void Dialog_AddIncome::onAcceptClicked()
{
    month_index = ui->comboBox_Month->currentIndex();
    poorsant = ui->lineEdit_Poorsant->text().toInt();
    sood = ui->lineEdit_Sood->text().toInt();
    accept();
}
int Dialog_AddIncome::getSood()
{
    return sood;
}
int Dialog_AddIncome::getPoorsant()
{
    return  poorsant;
}
int Dialog_AddIncome::getMonthIndex()
{
    return month_index;
}
