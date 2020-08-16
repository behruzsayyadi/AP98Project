#include "Page_Cars.h"
#include "ui_Page_Cars.h"

Page_Cars::Page_Cars(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Cars)
{
    ui->setupUi(this);
    QStringList labels ;
    labels << "status" << "Model" << "Brand" << "Year" << "Color" << "Inside Color" << "Shomare Shasi" << "Shomare Sanad" << "gheymat";
    ui->tableWidget_Cars->setHorizontalHeaderLabels(labels);
    ui->tableWidget_Cars->insertRow(0);

    ui->tableWidget_Cars->insertRow(0);

    ui->tableWidget_Cars->insertRow(0);
    ui->tableWidget_Cars->insertRow(0);
    ui->tableWidget_Cars->insertRow(0);
    ui->tableWidget_Cars->insertRow(0);
    ui->tableWidget_Cars->insertRow(0);


}

Page_Cars::~Page_Cars()
{
    delete ui;
}
void Page_Cars::populateCarsTable()
{
    ui->tableWidget_Cars->insertRow(0);
}
