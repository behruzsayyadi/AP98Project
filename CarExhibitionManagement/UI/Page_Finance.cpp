#include "Page_Finance.h"
#include "ui_Page_Finance.h"

Page_Finance::Page_Finance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Finance)
{
    ui->setupUi(this);


}

Page_Finance::~Page_Finance()
{
    delete ui;
}
