#include "TabWidget_login_register.h"
#include "ui_TabWidget_login_register.h"

TabWidget_login_register::TabWidget_login_register(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabWidget_login_register)
{
    ui->setupUi(this);
}

TabWidget_login_register::~TabWidget_login_register()
{
    delete ui;
}
