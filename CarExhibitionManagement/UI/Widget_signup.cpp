#include "Widget_signup.h"
#include "ui_Widget_signup.h"

Widget_signup::Widget_signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_signup)
{
    ui->setupUi(this);
    connect(ui->pushButton_signup, &QPushButton::clicked,
            []{//validate form here

                });
}

Widget_signup::~Widget_signup()
{
    delete ui;
}

bool Widget_signup::signup(QString username, QString password)
{
    return false;
}

int Widget_signup::validateSignupInfo(QString username, QString password)
{

}

