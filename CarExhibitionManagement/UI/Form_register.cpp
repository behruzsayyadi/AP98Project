#include "Form_register.h"
#include "ui_Form_register.h"

Form_register::Form_register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_register)
{
    ui->setupUi(this);
}

Form_register::~Form_register()
{
    delete ui;
}
