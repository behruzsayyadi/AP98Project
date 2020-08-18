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
    Coupe cp;
    CityCar cc;
    Crook ck;
    SUV s;
    Vanet va;
    foreach(QJsonValue v, loadSUVs_jsonArray())
    {
        s.loadFromJson(v.toObject());
        addNewRow(&s, "شاسی بلند");
    }
    foreach(QJsonValue v, loadCoupes_jsonArray())
    {
        cp.loadFromJson(v.toObject());
        addNewRow(&cp, "کوپه");
    }
    foreach(QJsonValue v, loadCityCars_jsonArray())
    {
        cc.loadFromJson(v.toObject());
        addNewRow(&cc, "شهری");
    }
    foreach(QJsonValue v, loadCrooks_jsonArray())
    {
        ck.loadFromJson(v.toObject());
        addNewRow(&ck, "کوروک");
    }
    foreach(QJsonValue v, loadVanets_jsonArray())
    {
        va.loadFromJson(v.toObject());
        addNewRow(&va, "وانت");
    }
}
void Page_Cars::addNewCar()
{
    //TODO: save added car
    Dialog_AddCar * d = new Dialog_AddCar(this);
    if(d->exec() == Dialog_AddCar::Accepted)
    {
        Car * c = d->getCar();
        Crook * ck;
        Coupe * cp;
        CityCar * cc;
        SUV * s;
        Vanet * v;

        if( (ck = dynamic_cast<Crook*>(c)) )
        {
            addNewRow(ck, "کروک");
        }
        else if((cp = dynamic_cast<Coupe*>(c)))
        {
            addNewRow(cp, "کوپه");
        }
        else if((cc = dynamic_cast<CityCar*>(c)))
        {
            addNewRow(ck, "کوروک");
        }
        else if((s = dynamic_cast<SUV*>(c)))
        {
            addNewRow(s, "شاسی بلند");
        }
        else if((v = dynamic_cast<Vanet*>(c)))
        {
            addNewRow(v, "وانت");
        }
        else {}
        delete c;
    }
    else
    {}
}
void Page_Cars::addNewMemorandum()
{
    Dialog_Memorandum * d = new Dialog_Memorandum(this);
    if(d->exec() == Dialog_Memorandum::Accepted)
    {

    }
}
void Page_Cars::addNewRow( Car* c, QString type)
{
    int row_count ;
    QTableWidget * table = ui->tableWidget_Cars;

    row_count = ui->tableWidget_Cars->rowCount();
    table->insertRow(row_count);
    table->setItem(row_count, 0,new QTableWidgetItem(type));
    table->setItem(row_count, 1,new QTableWidgetItem(c->getBrand()) );
    table->setItem(row_count, 2,new QTableWidgetItem(c->getModel()) );
    table->setItem(row_count, 3,new QTableWidgetItem(c->getYear()) );
    table->setItem(row_count, 4,new QTableWidgetItem(c->getColor()) );
    table->setItem(row_count, 5,new QTableWidgetItem(c->getInsideColor()) );
    table->setItem(row_count, 6,new QTableWidgetItem(c->getGheymat()) );
    table->setItem(row_count, 7,new QTableWidgetItem(c->getStatus()) );
}
