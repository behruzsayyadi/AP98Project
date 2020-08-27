#include "Page_Cars.h"
#include "ui_Page_Cars.h"
#include "QRegExp"

Page_Cars::Page_Cars(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Cars),
    selected_car_row(-1)
{
    ui->setupUi(this);
    ui->pushButton_sellCar->setEnabled(false);
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
        else
        {
            qDebug() << "could not recognize type of car.";
        }
        c->addCar();
        emit newCarAdded(*c);
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
    connect(d, SIGNAL(newIncome(QString, QString, int)), this, SIGNAL(newIncome(QString, QString, int)));
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
    table->setItem(row_count, 6,new QTableWidgetItem(QString::number(c->getGheymat())) );
    table->setItem(row_count, 7,new QTableWidgetItem(c->getShomareShasi()) );
    table->setItem(row_count, 8,new QTableWidgetItem(c->getShomareSanad()) );
    table->setItem(row_count, 9,new QTableWidgetItem(c->getStatus()) );
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


void Page_Cars::sellCar()
{

    QString status = selected_car->getStatus();
    if(status == "sold" || status == "Sold" || status == "فروخته شده" || status == "فروخته شد")
    {
        QMessageBox::warning(this, "خطای فروش", "این ماشین قیلا به فروش رفته است");
        ui->pushButton_sellCar->setEnabled(false);
        return;
    }

    Dialog_Memorandum * d = new Dialog_Memorandum(selected_car, loadManager(), this);
    connect(d, SIGNAL(memorandumCreated(QString, QString, QString, QString, QDateTime, QString)),
            this, SLOT(addNewMemorandumRow(QString, QString, QString, QString, QDateTime, QString)));
    if(d->exec() == Dialog_Memorandum::Accepted)
    {
        ui->tableWidget_Cars->item(selected_car_row, 9)->setText("فروخته شده");
        if(selected_car_type == "شاسی بلند")
        {
            Data::changeJsonArrayItem("status", "فروخته شده", "shomare sanad", selected_car_shomare_sanad, Data::default_suv_array_name, Data::default_suv_path);
        }
        else if(selected_car_type == "کروک")
        {
            Data::changeJsonArrayItem("status", "فروخته شده", "shomare sanad", selected_car_shomare_sanad, Data::default_crook_array_name, Data::default_crook_path);
        }
        else if(selected_car_type == "شهری")
        {
            Data::changeJsonArrayItem("status", "فروخته شده", "shomare sanad", selected_car_shomare_sanad, Data::default_citycar_array_name, Data::default_citycar_path);
        }
        else if(selected_car_type == "وانت")
        {
            Data::changeJsonArrayItem("status", "فروخته شده", "shomare sanad", selected_car_shomare_sanad, Data::default_vanet_array_name, Data::default_vanet_path);
        }
        else if(selected_car_type == "کوپه")
        {
            Data::changeJsonArrayItem("status", "فروخته شده", "shomare sanad", selected_car_shomare_sanad, Data::default_coupe_array_name, Data::default_coupe_path);
        }
        else
        {

        }
    }
}

void Page_Cars::onCarSelected(QTableWidgetItem * item)
{
    int row = item->row();
    QTableWidget * table = ui->tableWidget_Cars;
    QString status = table->item(row, 9)->text();
    if(status == "sold" || status == "Sold" || status == "فروخته شده" || status == "فروخته شد")
    {
        ui->pushButton_sellCar->setEnabled(false);
        return;
    }
    ui->pushButton_sellCar->setEnabled(true);
    selected_car_row = row;
    QString type = table->item(row, 0)->text();
    selected_car_type = type;
    QString shomare_sanad = table->item(row, 8)->text();
    selected_car_shomare_sanad = shomare_sanad;

    if(type == "شاسی بلند")
    {
        selected_car = new SUV(findSUV(shomare_sanad));
    }
    else if(type == "کروک")
    {
        selected_car = new Crook(findCrook(shomare_sanad));
    }
    else if(type == "شهری")
    {
        selected_car = new CityCar(findCityCar(shomare_sanad));
    }
    else if(type == "وانت")
    {
        selected_car = new Vanet(findVanet(shomare_sanad));
    }
    else if(type == "کوپه")
    {
        selected_car = new Coupe(findCoupe(shomare_sanad));
    }
    else
    {

    }

}
