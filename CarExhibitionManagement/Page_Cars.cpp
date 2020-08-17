#include "Page_Cars.h"
#include "ui_Page_Cars.h"

Page_Cars::Page_Cars(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Cars)
{
    ui->setupUi(this);
    populateCarsTable();
}

Page_Cars::~Page_Cars()
{
    delete ui;
}
void Page_Cars::populateCarsTable()
{
    QTableWidget * table = ui->tableWidget_Cars;
    table->setDisabled(true);

    int row_count ;
    Car c;

    foreach(QJsonValue v, loadSUVs_jsonArray())
    {
        c.loadFromJson(v.toObject());
        row_count = ui->tableWidget_Cars->rowCount();
        table->insertRow(row_count);
        table->setItem(row_count, 0,new QTableWidgetItem("شاسی بلند"));
        table->setItem(row_count, 1,new QTableWidgetItem(c.getBrand()) );
        table->setItem(row_count, 2,new QTableWidgetItem(c.getModel()) );
        table->setItem(row_count, 3,new QTableWidgetItem(c.getYear()) );
        table->setItem(row_count, 4,new QTableWidgetItem(c.getColor()) );
        table->setItem(row_count, 5,new QTableWidgetItem(c.getInsideColor()) );
        table->setItem(row_count, 6,new QTableWidgetItem(c.getGheymat()) );
        table->setItem(row_count, 7,new QTableWidgetItem(c.getStatus()) );
    }
    foreach(QJsonValue v, loadCoupes_jsonArray())
    {
        c.loadFromJson(v.toObject());
        row_count = ui->tableWidget_Cars->rowCount();
        table->insertRow(row_count);
        table->setItem(row_count, 0,new QTableWidgetItem("کوپه"));
        table->setItem(row_count, 1,new QTableWidgetItem(c.getBrand()) );
        table->setItem(row_count, 2,new QTableWidgetItem(c.getModel()) );
        table->setItem(row_count, 3,new QTableWidgetItem(c.getYear()) );
        table->setItem(row_count, 4,new QTableWidgetItem(c.getColor()) );
        table->setItem(row_count, 5,new QTableWidgetItem(c.getInsideColor()) );
        table->setItem(row_count, 6,new QTableWidgetItem(c.getGheymat()) );
        table->setItem(row_count, 7,new QTableWidgetItem(c.getStatus()) );
    }
    foreach(QJsonValue v, loadCityCars_jsonArray())
    {
        c.loadFromJson(v.toObject());
        row_count = ui->tableWidget_Cars->rowCount();
        table->insertRow(row_count);
        table->setItem(row_count, 0,new QTableWidgetItem("شهری"));
        table->setItem(row_count, 1,new QTableWidgetItem(c.getBrand()) );
        table->setItem(row_count, 2,new QTableWidgetItem(c.getModel()) );
        table->setItem(row_count, 3,new QTableWidgetItem(c.getYear()) );
        table->setItem(row_count, 4,new QTableWidgetItem(c.getColor()) );
        table->setItem(row_count, 5,new QTableWidgetItem(c.getInsideColor()) );
        table->setItem(row_count, 6,new QTableWidgetItem(c.getGheymat()) );
        table->setItem(row_count, 7,new QTableWidgetItem(c.getStatus()) );
    }
    foreach(QJsonValue v, loadCrooks_jsonArray())
    {
        c.loadFromJson(v.toObject());
        row_count = ui->tableWidget_Cars->rowCount();
        table->insertRow(row_count);
        table->setItem(row_count, 0,new QTableWidgetItem("کوروک"));
        table->setItem(row_count, 1,new QTableWidgetItem(c.getBrand()) );
        table->setItem(row_count, 2,new QTableWidgetItem(c.getModel()) );
        table->setItem(row_count, 3,new QTableWidgetItem(c.getYear()) );
        table->setItem(row_count, 4,new QTableWidgetItem(c.getColor()) );
        table->setItem(row_count, 5,new QTableWidgetItem(c.getInsideColor()) );
        table->setItem(row_count, 6,new QTableWidgetItem(c.getGheymat()) );
        table->setItem(row_count, 7,new QTableWidgetItem(c.getStatus()) );
    }
    foreach(QJsonValue v, loadVanets_jsonArray())
    {
        c.loadFromJson(v.toObject());
        row_count = ui->tableWidget_Cars->rowCount();
        table->insertRow(row_count);
        table->setItem(row_count, 0,new QTableWidgetItem("وانت"));
        table->setItem(row_count, 1,new QTableWidgetItem(c.getBrand()) );
        table->setItem(row_count, 2,new QTableWidgetItem(c.getModel()) );
        table->setItem(row_count, 3,new QTableWidgetItem(c.getYear()) );
        table->setItem(row_count, 4,new QTableWidgetItem(c.getColor()) );
        table->setItem(row_count, 5,new QTableWidgetItem(c.getInsideColor()) );
        table->setItem(row_count, 6,new QTableWidgetItem(c.getGheymat()) );
        table->setItem(row_count, 7,new QTableWidgetItem(c.getStatus()) );
    }
}
void Page_Cars::addNewCar()
{
    Dialog_AddCar * d = new Dialog_AddCar(this);
    if(d->exec() == Dialog_AddCar::Accepted)
    {
        d->getCar().addCar();
    }
    else
    {

    }
}
