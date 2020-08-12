#include "Form_login.h"
#include "ui_Form_login.h"

Form_login::Form_login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_login)
{
    ui->setupUi(this);
}

Form_login::~Form_login()
{
    delete ui;
}
