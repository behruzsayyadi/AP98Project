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
