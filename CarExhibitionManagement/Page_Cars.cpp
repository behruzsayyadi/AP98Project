#include "Page_Cars.h"
#include "ui_Page_Cars.h"

Page_Cars::Page_Cars(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Cars)
{
    ui->setupUi(this);
    populateCarsTable();
    populateMemorandumsTable();
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

void Page_Cars::populateMemorandumsTable()
{
    QJsonObject o;
    for(QJsonValue v : loadMemorandums())
    {
        o = v.toObject();
        addNewMemorandumRow(o["seller name"].toString(),
                o["customer name"].toString(), o["car"].toString(),
                o["poorsant"].toString(),
                QDateTime::fromString(o["date and time"].toString()),
                o["shomare sanad"].toString());
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
            addNewRow(cc, "شهری");
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
        c->addCar();
        delete c;
    }
    else
    {}
}
void Page_Cars::addNewMemorandum()
{
    Dialog_Memorandum * d = new Dialog_Memorandum(this);
    connect(d, SIGNAL(memorandumCreated(QString, QString, QString, QString, QDateTime, QString)),
            this, SLOT(addNewMemorandumRow(QString, QString, QString, QString, QDateTime, QString)));
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

void Page_Cars::addNewMemorandumRow(QString seller_name, QString buyer_name, QString car_info, QString poorsant, QDateTime time, QString shomare_sanad)
{
    QTableWidget * table = ui->tableWidget_Memorandums;
    int row_count = table->rowCount();
    table->insertRow(row_count);
    table->setItem(row_count, 0,new QTableWidgetItem(seller_name));
    table->setItem(row_count, 1,new QTableWidgetItem(buyer_name));
    table->setItem(row_count, 2,new QTableWidgetItem(car_info));
    table->setItem(row_count, 3,new QTableWidgetItem(poorsant));
    table->setItem(row_count, 4,new QTableWidgetItem(time.toString()));
    table->setItem(row_count, 5,new QTableWidgetItem(shomare_sanad));
}

void Page_Cars::showMemorandum(QTableWidgetItem * item)
{
    QTableWidget * table = ui->tableWidget_Memorandums;
    int row = item->row();
    QString shomare_sanad = table->item(row, 5 )->text();
    Dialog_Memorandum * d = new Dialog_Memorandum(findMemorandum(shomare_sanad), this);
    d->exec();
}
