#include "Page_Cars.h"
#include "ui_Page_Cars.h"

Page_Cars::Page_Cars(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Cars)
{
    ui->setupUi(this);
}

Page_Cars::~Page_Cars()
{
    delete ui;
}
