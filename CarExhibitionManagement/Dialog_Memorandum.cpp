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

Dialog_Memorandum::~Dialog_Memorandum()
{
    delete ui;
}

void Dialog_Memorandum::on_radioButton_mngr_yes_clicked()
{
//    ui->groupBox_customer->hide();

    Manager m = loadManager();
    ui->lineEdit_ID_4->setText(m.getID());
    ui->lineEdit_name_4->setText(m.getName());
    ui->lineEdit_job_4->setText(m.getJob());
    ui->lineEdit_family_4->setText(m.getFamily());
    ui->lineEdit_job_phone_4->setText(m.getJobPhone());
    ui->lineEdit_sh_shenasname_4->setText(m.getShShenasname());
    ui->lineEdit_phone_4->setText(m.getPhoneNum());
    ui->dateEdit_birth_date4->setDate(m.getBirthDate());

    ui->groupBox_customer->setEnabled(false);
    ui->groupBox_customer->setTitle("Manager");
}

void Dialog_Memorandum::on_radioButton_mngr_no_clicked()
{
//    ui->groupBox_customer->show();
    ui->groupBox_customer->setEnabled(true);
    ui->groupBox_customer->setTitle("Customer");

    ui->lineEdit_ID_4->clear();
    ui->lineEdit_name_4->clear();
    ui->lineEdit_job_4->clear();
    ui->lineEdit_family_4->clear();
    ui->lineEdit_job_phone_4->clear();
    ui->lineEdit_sh_shenasname_4->clear();
    ui->lineEdit_phone_4->clear();
    ui->dateEdit_birth_date4->setDate(QDate(2000,1,1));
}

void Dialog_Memorandum::on_radioButton_check_yes_clicked()
{
//    ui->groupBox_check->show();
    ui->groupBox_check->setEnabled(true);
}

void Dialog_Memorandum::on_radioButton_check_no_clicked()
{
    ui->groupBox_check->setEnabled(false);
//    ui->groupBox_check->hide();
}

void Dialog_Memorandum::on_buttonBox_accepted()
{
    QString
//            seller_first_name,
//            seller_last_name,
//            seller_ID,
//            seller_job,
//            seller_job_phone,
//            seller_phone_number,
//            seller_shenasname,

//            buyer_first_name,
//            buyer_last_name,
//            buyer_ID,
//            buyer_job,
//            buyer_job_phone,
//            buyer_phone_number,
//            buyer_shenasname,

//            date_time_of_purchase,

            car_model = ui->lineEdit_model->text(),
            car_brand = ui->lineEdit_brand->text(),
            car_year = ui->lineEdit_production_year->text(),
            car_color = ui->lineEdit_color->text(),
            car_inside_color = ui->lineEdit_inside_color->text(),
            car_shomare_sanad = ui->lineEdit_sh_sanad->text(),
            car_shomare_shasi = ui->lineEdit_sh_shasi->text(),
            car_gheymat = ui->lineEdit_gheymat->text()
            ;

//    QDate seller_dob, buyer_dob;
    Seller seller(ui->lineEdit_name->text(),
                  ui->lineEdit_family->text(),
                  ui->dateEdit_birth_date->date(),
                  ui->lineEdit_ID->text(),
                  ui->lineEdit_sh_shenasname->text(),
                  ui->lineEdit_phone->text(),
                  ui->lineEdit_job->text(),
                  ui->lineEdit_job_phone->text());
    Customer customer(ui->lineEdit_name_4->text(),
                  ui->lineEdit_family_4->text(),
                  ui->dateEdit_birth_date4->date(),
                  ui->lineEdit_ID_4->text(),
                  ui->lineEdit_sh_shenasname_4->text(),
                  ui->lineEdit_phone_4->text(),
                  ui->lineEdit_job_4->text(),
                  ui->lineEdit_job_phone_4->text());
    QDateTime date_time_of_purchase = ui->dateTimeEdit_purchase->dateTime();
    Car * car = nullptr;
    if(ui->comboBox->currentText() == "Coupe")
    {
        car = new Coupe();
    }
    else if(ui->comboBox->currentText() == "SUV")
    {
        car = new SUV();
    }
    else if(ui->comboBox->currentText() == "CityCar")
    {
        car = new CityCar();
    }
    else if(ui->comboBox->currentText() == "Crook")
    {
        car = new Crook();
    }
    else if(ui->comboBox->currentText() == "Vanet")
    {
        car = new Vanet();
    }
    else
    {
        qDebug() << "cannot recognize type of car";
        reject();
        return;
    }

    Memorandum(car, seller, customer, date_time_of_purchase.date(), "sdaf", checks_vector);
    delete car;
//    Seller seller;
//    Customer customer;
//    QDate date ;
//    date = ui->dateEdit->date();
//    QString time;
//    time = ui->lineEdit_hour->text()+":"+ui->lineEdit_minute->text()+":"+ui->lineEdit_second->text();

//        if(ui->radioButton_mngr_no)
//        {
//            seller.setName(ui->lineEdit_name->text());
//            seller.setFamily(ui->lineEdit_family->text());
//            seller.setID(ui->lineEdit_ID->text());
//            seller.setJob(ui->lineEdit_job->text());
//            seller.setJobPhone(ui->lineEdit_job_phone->text());
//            seller.setPhoneNum(ui->lineEdit_phone->text());
//            seller.setBirthDate(ui->dateEdit_birth_date->date());
//            seller.setShShenasname(ui->lineEdit_sh_shenasname->text());

//            customer.setName(ui->lineEdit_name_4->text());
//            customer.setFamily(ui->lineEdit_family_4->text());
//            customer.setID(ui->lineEdit_ID_4->text());
//            customer.setJob(ui->lineEdit_job_4->text());
//            customer.setJobPhone(ui->lineEdit_job_phone_4->text());
//            customer.setPhoneNum(ui->lineEdit_phone_4->text());
//            customer.setBirthDate(ui->dateEdit_birth_date4->date());
//            customer.setShShenasname(ui->lineEdit_sh_shenasname_4->text());

//            if(ui->comboBox->currentText()=="CityCar")
//            {
//                CityCar car;
//                car.setBrand(ui->lineEdit_brand->text());
//                car.setModel(ui->lineEdit_model->text());
//                car.setYear(ui->lineEdit_production_year->text());
//                car.setColor(ui->lineEdit_color->text());
//                car.setInsideColor(ui->lineEdit_inside_color->text());
//                car.setShomareSanad(ui->lineEdit_sh_sanad->text());
//                car.setShomareShasi(ui->lineEdit_sh_shasi->text());
//                car.setGheymat(static_cast<quint64>(ui->lineEdit_gheymat->text().toULongLong()));
//                Memorandum(&car,seller,customer,date,time,this->checks_vector);
//                accept();
//            }
//            else if(ui->comboBox->currentText()=="SUV")
//            {
//                SUV car;
//                car.setBrand(ui->lineEdit_brand->text());
//                car.setModel(ui->lineEdit_model->text());
//                car.setYear(ui->lineEdit_production_year->text());
//                car.setColor(ui->lineEdit_color->text());
//                car.setInsideColor(ui->lineEdit_inside_color->text());
//                car.setShomareSanad(ui->lineEdit_sh_sanad->text());
//                car.setShomareShasi(ui->lineEdit_sh_shasi->text());
//                car.setGheymat(static_cast<quint64>(ui->lineEdit_gheymat->text().toULongLong()));
//                Memorandum(&car,seller,customer,date,time,this->checks_vector);
//                accept();
//            }
//            else if(ui->comboBox->currentText()=="Coupe")
//            {
//                Coupe car;
//                car.setBrand(ui->lineEdit_brand->text());
//                car.setModel(ui->lineEdit_model->text());
//                car.setYear(ui->lineEdit_production_year->text());
//                car.setColor(ui->lineEdit_color->text());
//                car.setInsideColor(ui->lineEdit_inside_color->text());
//                car.setShomareSanad(ui->lineEdit_sh_sanad->text());
//                car.setShomareShasi(ui->lineEdit_sh_shasi->text());
//                car.setGheymat(static_cast<quint64>(ui->lineEdit_gheymat->text().toULongLong()));
//                Memorandum(&car,seller,customer,date,time,this->checks_vector);
//                accept();
//            }
//            else if(ui->comboBox->currentText()=="Vanet")
//            {
//                Vanet car;
//                car.setBrand(ui->lineEdit_brand->text());
//                car.setModel(ui->lineEdit_model->text());
//                car.setYear(ui->lineEdit_production_year->text());
//                car.setColor(ui->lineEdit_color->text());
//                car.setInsideColor(ui->lineEdit_inside_color->text());
//                car.setShomareSanad(ui->lineEdit_sh_sanad->text());
//                car.setShomareShasi(ui->lineEdit_sh_shasi->text());
//                car.setGheymat(static_cast<quint64>(ui->lineEdit_gheymat->text().toULongLong()));
//                Memorandum(&car,seller,customer,date,time,this->checks_vector);
//                accept();
//            }
//            else if(ui->comboBox->currentText()=="Crook")
//            {
//                Crook car;
//                car.setBrand(ui->lineEdit_brand->text());
//                car.setModel(ui->lineEdit_model->text());
//                car.setYear(ui->lineEdit_production_year->text());
//                car.setColor(ui->lineEdit_color->text());
//                car.setInsideColor(ui->lineEdit_inside_color->text());
//                car.setShomareSanad(ui->lineEdit_sh_sanad->text());
//                car.setShomareShasi(ui->lineEdit_sh_shasi->text());
//                car.setGheymat(static_cast<quint64>(ui->lineEdit_gheymat->text().toULongLong()));
//                Memorandum(&car,seller,customer,date,time,this->checks_vector);
//                accept();
//            }

//        }
//        else if(ui->radioButton_mngr_yes)
//        {
//            customer.setName(ui->lineEdit_name_4->text());
//            customer.setFamily(ui->lineEdit_family_4->text());
//            customer.setID(ui->lineEdit_ID_4->text());
//            customer.setJob(ui->lineEdit_job_4->text());
//            customer.setJobPhone(ui->lineEdit_job_phone_4->text());
//            customer.setPhoneNum(ui->lineEdit_phone_4->text());
//            customer.setBirthDate(ui->dateEdit_birth_date4->date());
//            customer.setShShenasname(ui->lineEdit_sh_shenasname_4->text());

//            Manager m = loadManager();
//            seller.setName(m.getName());
//            seller.setFamily(m.getFamily());
//            seller.setID(m.getID());
//            seller.setJob(m.getJob());
//            seller.setJobPhone(m.getJobPhone());
//            seller.setPhoneNum(m.getPhoneNum());
//            seller.setBirthDate(m.getBirthDate());
//            seller.setShShenasname(m.getShShenasname());

//            if(ui->comboBox->currentText()=="CityCar")
//            {
//                CityCar car;
//                car.setBrand(ui->lineEdit_brand->text());
//                car.setModel(ui->lineEdit_model->text());
//                car.setYear(ui->lineEdit_production_year->text());
//                car.setColor(ui->lineEdit_color->text());
//                car.setInsideColor(ui->lineEdit_inside_color->text());
//                car.setShomareSanad(ui->lineEdit_sh_sanad->text());
//                car.setShomareShasi(ui->lineEdit_sh_shasi->text());
//                car.setGheymat(static_cast<quint64>(ui->lineEdit_gheymat->text().toULongLong()));

//                Memorandum(&car,seller,customer,date,time,this->checks_vector);
//                accept();
//            }
//            else if(ui->comboBox->currentText()=="SUV")
//            {
//                SUV car;
//                car.setBrand(ui->lineEdit_brand->text());
//                car.setModel(ui->lineEdit_model->text());
//                car.setYear(ui->lineEdit_production_year->text());
//                car.setColor(ui->lineEdit_color->text());
//                car.setInsideColor(ui->lineEdit_inside_color->text());
//                car.setShomareSanad(ui->lineEdit_sh_sanad->text());
//                car.setShomareShasi(ui->lineEdit_sh_shasi->text());
//                car.setGheymat(static_cast<quint64>(ui->lineEdit_gheymat->text().toULongLong()));
//                Memorandum(&car,seller,customer,date,time,this->checks_vector);
//                accept();
//            }
//            else if(ui->comboBox->currentText()=="Coupe")
//            {
//                Coupe car;
//                car.setBrand(ui->lineEdit_brand->text());
//                car.setModel(ui->lineEdit_model->text());
//                car.setYear(ui->lineEdit_production_year->text());
//                car.setColor(ui->lineEdit_color->text());
//                car.setInsideColor(ui->lineEdit_inside_color->text());
//                car.setShomareSanad(ui->lineEdit_sh_sanad->text());
//                car.setShomareShasi(ui->lineEdit_sh_shasi->text());
//                car.setGheymat(static_cast<quint64>(ui->lineEdit_gheymat->text().toULongLong()));
//                Memorandum(&car,seller,customer,date,time,this->checks_vector);
//                accept();
//            }
//            else if(ui->comboBox->currentText()=="Vanet")
//            {
//                Vanet car;
//                car.setBrand(ui->lineEdit_brand->text());
//                car.setModel(ui->lineEdit_model->text());
//                car.setYear(ui->lineEdit_production_year->text());
//                car.setColor(ui->lineEdit_color->text());
//                car.setInsideColor(ui->lineEdit_inside_color->text());
//                car.setShomareSanad(ui->lineEdit_sh_sanad->text());
//                car.setShomareShasi(ui->lineEdit_sh_shasi->text());
//                car.setGheymat(static_cast<quint64>(ui->lineEdit_gheymat->text().toULongLong()));
//                Memorandum(&car,seller,customer,date,time,this->checks_vector);
//                accept();
//            }
//            else if(ui->comboBox->currentText()=="Crook")
//            {
//                Crook car;
//                car.setBrand(ui->lineEdit_brand->text());
//                car.setModel(ui->lineEdit_model->text());
//                car.setYear(ui->lineEdit_production_year->text());
//                car.setColor(ui->lineEdit_color->text());
//                car.setInsideColor(ui->lineEdit_inside_color->text());
//                car.setShomareSanad(ui->lineEdit_sh_sanad->text());
//                car.setShomareShasi(ui->lineEdit_sh_shasi->text());
//                car.setGheymat(static_cast<quint64>(ui->lineEdit_gheymat->text().toULongLong()));
//                Memorandum(&car,seller,customer,date,time,this->checks_vector);
//                accept();
//            }
//        }



}

void Dialog_Memorandum::getNewChecks()
{
    Dialog_Check * d = new Dialog_Check(this);
    if(d->exec() == Dialog_Check::Accepted)
    {
        this->checks_vector = d->getChecks();
    }

}

