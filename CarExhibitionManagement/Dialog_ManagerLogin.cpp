#include "Dialog_ManagerLogin.h"
#include "ui_Dialog_ManagerLogin.h"

Dialog_ManagerLogin::Dialog_ManagerLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ManagerLogin)
{
    ui->setupUi(this);
}

Dialog_ManagerLogin::~Dialog_ManagerLogin()
{
    delete ui;
}
