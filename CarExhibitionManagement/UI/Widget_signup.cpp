#include "Widget_signup.h"
#include "ui_Widget_signup.h"

Widget_signup::Widget_signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_signup)
{
    ui->setupUi(this);
}

Widget_signup::~Widget_signup()
{
    delete ui;
}
