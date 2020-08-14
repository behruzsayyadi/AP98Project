#include "Dialog_managerSingIn.h"
#include "ui_Dialog_managerSingIn.h"

Dialog_managerSingIn::Dialog_managerSingIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_managerSingIn)
{
    ui->setupUi(this);
}

Dialog_managerSingIn::~Dialog_managerSingIn()
{
    delete ui;
}
