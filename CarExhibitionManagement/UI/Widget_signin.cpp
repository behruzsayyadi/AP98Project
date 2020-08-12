#include "Widget_signin.h"
#include "ui_Widget_signin.h"

Widget_signin::Widget_signin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_signin)
{
    ui->setupUi(this);

}

Widget_signin::~Widget_signin()
{
    delete ui;
}

void Widget_signin::signin()
{

}
