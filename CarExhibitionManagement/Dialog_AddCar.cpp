#include "Dialog_AddCar.h"
#include "ui_Dialog_AddCar.h"

Dialog_AddCar::Dialog_AddCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddCar)
{
    ui->setupUi(this);
}

Dialog_AddCar::~Dialog_AddCar()
{
    delete ui;
}

Car Dialog_AddCar::getCar()
{
    return Car( "available",
                ui->lineEdit_Model->text(),
                ui->lineEdit_Brand->text(),
                ui->lineEdit_Year->text(),
                ui->lineEdit_Color->text(),
                ui->lineEdit_InsideColor->text(),
                ui->lineEdit_ShomareShasi->text(),
                ui->lineEdit_ShomareSanad->text().toInt(),
                ui->lineEdit_Gheymat->text());
}
