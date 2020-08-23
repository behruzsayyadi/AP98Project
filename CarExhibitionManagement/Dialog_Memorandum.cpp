#include "Dialog_Memorandum.h"
#include "ui_Dialog_Memorandum.h"

#include "Memorandum.h"
#include "Seller.h"
#include "Customer.h"
#include "QTime"
#include "Manager.h"

Dialog_Memorandum::Dialog_Memorandum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Memorandum)
{
    ui->setupUi(this);
}

Dialog_Memorandum::Dialog_Memorandum(Car * car, Manager manager, QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog_Memorandum)
{
    ui->lineEdit_seller_name->setText(manager.getName());
    ui->lineEdit_seller_family->setText(manager.getFamily());
    ui->lineEdit_seller_id->setText(manager.getID());
    ui->lineEdit_seller_shomare_shenasname->setText(manager.getShShenasname());
    ui->lineEdit_seller_job->setText(manager.getJob());
    ui->lineEdit_seller_job_phone_number->setText(manager.getJobPhone());
    ui->lineEdit_seller_phone_number->setText(manager.getPhoneNum());
    ui->dateEdit_seller_date_of_birth->setDate(manager.getBirthDate());
    ui->lineEdit_car_model->setText(car->getModel());
    ui->lineEdit_car_brand->setText(car->getBrand());
    ui->lineEdit_car_year->setText(car->getYear());
    ui->lineEdit_car_color->setText(car->getColor());
    ui->lineEdit_car_inside_color->setText(car->getInsideColor());
    ui->lineEdit_car_shomare_shasi->setText(car->getShomareShasi());
    ui->lineEdit_car_shomare_sanad->setText(car->getShomareSanad());
    ui->lineEdit_car_gheymat->setText( QString::number( car->getGheymat() ) );

    if (dynamic_cast<CityCar*>(car))
    {
        ui->comboBox_car_type->setCurrentText("شهری");
    }
    if (dynamic_cast<Coupe*>(car))
    {
        ui->comboBox_car_type->setCurrentText("کوپه");
    }
    if (dynamic_cast<SUV*>(car))
    {
        ui->comboBox_car_type->setCurrentText("شاسی بلند");
    }
    if (dynamic_cast<Crook*>(car))
    {
        ui->comboBox_car_type->setCurrentText("کروک");
    }
    if (dynamic_cast<Vanet*>(car))
    {
        ui->comboBox_car_type->setCurrentText("وانت");
    }
    else
    {
        qDebug() << "failed to recognize car type";
    }
    ui->groupBox_seller->setEnabled(false);
    ui->groupBox_car_info->setEnabled(false);
}

Dialog_Memorandum::~Dialog_Memorandum()
{
    delete ui;
}

void Dialog_Memorandum::on_buttonBox_accepted()
{
    QString car_model = ui->lineEdit_car_model->text(),
            car_brand = ui->lineEdit_car_brand->text(),
            car_year = ui->lineEdit_car_year->text(),
            car_color = ui->lineEdit_car_color->text(),
            car_inside_color = ui->lineEdit_car_inside_color->text(),
            car_shomare_sanad = ui->lineEdit_car_shomare_sanad->text(),
            car_shomare_shasi = ui->lineEdit_car_shomare_shasi->text()
            ;
    quint64 car_gheymat = ui->lineEdit_car_gheymat->text().toULongLong();
    Seller seller(ui->lineEdit_seller_name->text(),
                  ui->lineEdit_seller_family->text(),
                  ui->dateEdit_seller_date_of_birth->date(),
                  ui->lineEdit_seller_id->text(),
                  ui->lineEdit_seller_shomare_shenasname->text(),
                  ui->lineEdit_seller_phone_number->text(),
                  ui->lineEdit_seller_job->text(),
                  ui->lineEdit_seller_job_phone_number->text());

    Customer customer(ui->lineEdit_buyer_name->text(),
                      ui->lineEdit_buyer_family->text(),
                      ui->dateEdit_buyer_date_of_birth->date(),
                      ui->lineEdit_buyer_id->text(),
                      ui->lineEdit_buyer_shomare_shenasname->text(),
                      ui->lineEdit_buyer_phone_number->text(),
                      ui->lineEdit_buyer_job->text(),
                      ui->lineEdit_buyer_job_phone_number->text());
    QDateTime date_time_of_purchase = ui->dateTimeEdit_dateTime_of_purchase->dateTime();
    Car * car = nullptr;
    if(ui->comboBox_car_type->currentText() == "کوپه")
    {
        car = new Coupe("sold", car_model, car_brand, car_year, car_color, car_inside_color, car_shomare_shasi, car_shomare_sanad, car_gheymat);
    }
    else if(ui->comboBox_car_type->currentText() == "شاسی بلند")
    {
        car = new SUV("sold", car_model, car_brand, car_year, car_color, car_inside_color, car_shomare_shasi, car_shomare_sanad, car_gheymat);
    }
    else if(ui->comboBox_car_type->currentText() == "شهری")
    {
        car = new CityCar("sold", car_model, car_brand, car_year, car_color, car_inside_color, car_shomare_shasi, car_shomare_sanad, car_gheymat);
    }
    else if(ui->comboBox_car_type->currentText() == "کروک")
    {
        car = new Crook("sold", car_model, car_brand, car_year, car_color, car_inside_color, car_shomare_shasi, car_shomare_sanad, car_gheymat);
    }
    else if(ui->comboBox_car_type->currentText() == "وانت")
    {
        car = new Vanet("sold", car_model, car_brand, car_year, car_color, car_inside_color, car_shomare_shasi, car_shomare_sanad, car_gheymat);
    }
    else
    {
        qDebug() << "cannot recognize type of car";
        reject();
        return;
    }

    Memorandum(car, seller, customer, date_time_of_purchase, checks_vector);
    delete car;

    accept();
}

void Dialog_Memorandum::getNewCheck()
{
//    Dialog_Check * d = new Dialog_Check(this);
//    if(d->exec() == Dialog_Check::Accepted)
//    {
//        this->checks_vector = d->getChecks();
//    }
    Dialog_AddCheck * d = new Dialog_AddCheck(this);
    if(d->exec() == Dialog_AddCheck::Accepted)
    {
        Checkinfo * new_check = d->getCheck();
        this->checks_vector << new_check;

        QTableWidget * table = ui->tableWidget_checks;
        int row_count = table->rowCount();
        table->insertRow(row_count);
        table->setItem(row_count, 0, new QTableWidgetItem(new_check->getMoney()));
        table->setItem(row_count, 1, new QTableWidgetItem(new_check->getDate().toString("yyyy/M/d")));
        table->setItem(row_count, 2, new QTableWidgetItem(new_check->getShenase()));
    }

}

