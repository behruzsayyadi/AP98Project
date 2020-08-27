#include "Dialog_Memorandum.h"
#include "ui_Dialog_Memorandum.h"



Dialog_Memorandum::Dialog_Memorandum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Memorandum)
{
    ui->setupUi(this);
    this->setWindowTitle("قولنامه ی جدید");
    ui->dateTimeEdit_dateTime_of_purchase->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_dateTime_of_purchase->setMaximumDateTime(QDateTime::currentDateTime());
    ui->label_money_income->setText("پورسانت");
}

Dialog_Memorandum::Dialog_Memorandum(Car * car, Manager manager, QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog_Memorandum)
{
    ui->setupUi(this);
    this->setWindowTitle("قولنامه ی جدید");

    ui->label_money_income->setText("درآمد");


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
    ui->dateTimeEdit_dateTime_of_purchase->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_dateTime_of_purchase->setMaximumDateTime(QDateTime::currentDateTime());
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

Dialog_Memorandum::Dialog_Memorandum(QJsonObject memorandum, QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog_Memorandum)
{
    ui->setupUi(this);

    ui->buttonBox->hide();
    ui->pushButton_add_check->hide();
    ui->groupBox_buyer->setEnabled(false);
    ui->groupBox_seller->setEnabled(false);
    ui->groupBox_car_info->setEnabled(false);
    ui->groupBox_memorandum_info->setEnabled(false);

    QJsonObject seller = memorandum["seller"].toObject(),
            buyer = memorandum["customer"].toObject(),
            car = memorandum["car"].toObject();
    QJsonArray checks = memorandum["checks"].toArray();
    QDateTime dateTime = QDateTime::fromString(memorandum["date and time"].toString());
    QJsonObject check_object;
    for (QJsonValue v : checks)
    {
        check_object = v.toObject();
        Checkinfo check( check_object["money"].toString(),
                         check_object["bank"].toString(),
                         check_object["money"].toString(),
                         QDate::fromString(check_object["date"].toString()),
                         check_object["shenase"].toString() );
        addNewCheck(check);
    }
    ui->dateTimeEdit_dateTime_of_purchase->setDateTime(dateTime);

    ui->lineEdit_seller_name->setText(seller["name"].toString());
    ui->lineEdit_seller_family->setText(seller["family"].toString());
    ui->lineEdit_seller_id->setText(seller["id"].toString());
    ui->lineEdit_seller_shomare_shenasname->setText(seller["shomare shenasname"].toString());
    ui->lineEdit_seller_phone_number->setText(seller["phone number"].toString());
    ui->lineEdit_seller_job->setText(seller["job"].toString());
    ui->lineEdit_seller_job_phone_number->setText(seller["job phone"].toString());

    ui->dateEdit_seller_date_of_birth->setDate(QDate::fromString(seller["birth date"].toString()));

    ui->lineEdit_buyer_name->setText(buyer["name"].toString());
    ui->lineEdit_buyer_family->setText(buyer["family"].toString());
    ui->lineEdit_buyer_id->setText(buyer["id"].toString());
    ui->lineEdit_buyer_shomare_shenasname->setText(buyer["shomare shenasname"].toString());
    ui->lineEdit_buyer_phone_number->setText(buyer["phone number"].toString());
    ui->lineEdit_buyer_job->setText(buyer["job"].toString());
    ui->lineEdit_buyer_job_phone_number->setText(buyer["job phone"].toString());

    ui->dateEdit_buyer_date_of_birth->setDate(QDate::fromString(buyer["birth date"].toString()));

    ui->lineEdit_car_model->setText(car["model"].toString());
    ui->lineEdit_car_brand->setText(car["brand"].toString());
    ui->lineEdit_car_year->setText(car["year"].toString());
    ui->lineEdit_car_color->setText(car["color"].toString());
    ui->lineEdit_car_inside_color->setText(car["inside color"].toString());
    ui->lineEdit_car_shomare_sanad->setText(car["shomare sanad"].toString());
    ui->lineEdit_car_shomare_shasi->setText(car["shomare shasi"].toString());
    ui->lineEdit_car_gheymat->setText(car["gheymat"].toString());

}

Dialog_Memorandum::~Dialog_Memorandum()
{
    delete ui;
}

void Dialog_Memorandum::on_buttonBox_accepted()
{
    if(ui->lineEdit_car_shomare_sanad->text().isEmpty())
    {
        ui->lineEdit_car_shomare_sanad->setStyleSheet("border: 2px solid red");
        QMessageBox::warning(this, "خطا", "شماره سند برای ثبت اطلاعات ماشین ضروری است");
        return;
    }
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
    emit memorandumCreated( seller.getName() + ' ' + seller.getFamily(),
                            customer.getName() + ' ' + customer.getFamily(),
                            car->getModel() + ' ' + car->getBrand() + ' ' + car->getYear(),
                            QString::number(car->getPoorsant()),
                            date_time_of_purchase,
                            car->getShomareSanad() );
    if(date_time_of_purchase.date().year() == QDate::currentDate().year())
    {
        if(ui->label_money_income->text() == "درآمد")
        {
            emit newIncome(0, ui->lineEdit_money_income->text(), date_time_of_purchase.date().month());
        }
        else
        {
            emit newIncome(ui->lineEdit_money_income->text(), 0, date_time_of_purchase.date().month());
        }
    }


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
        addNewCheck(*new_check);
    }

}

void Dialog_Memorandum::addNewCheck(Checkinfo check)
{
    QTableWidget * table = ui->tableWidget_checks;
    int row_count = table->rowCount();
    table->insertRow(row_count);
    table->setItem(row_count, 0, new QTableWidgetItem(check.getMoney()));
    table->setItem(row_count, 1, new QTableWidgetItem(check.getDate().toString("yyyy/M/d")));
    table->setItem(row_count, 2, new QTableWidgetItem(check.getShenase()));
}

void Dialog_Memorandum::showIncome()
{
    QString newGheymat = ui->lineEdit_car_gheymat->text();
    QString income = "0";
    if(ui->comboBox_car_type->currentText() == "کوپه")
    {
        Coupe c;
        c.setGheymat(newGheymat.toULongLong());
        income = QString::number(c.getPoorsant());
    }
    else if(ui->comboBox_car_type->currentText() == "شاسی بلند")
    {
        SUV c;
        c.setGheymat(newGheymat.toULongLong());
        income = QString::number(c.getPoorsant());
    }
    else if(ui->comboBox_car_type->currentText() == "شهری")
    {
        CityCar c;
        c.setGheymat(newGheymat.toULongLong());
        income = QString::number(c.getPoorsant());
    }
    else if(ui->comboBox_car_type->currentText() == "کروک")
    {
        Crook c;
        c.setGheymat(newGheymat.toULongLong());
        income = QString::number(c.getPoorsant());
    }
    else if(ui->comboBox_car_type->currentText() == "وانت")
    {
        Vanet c;
        c.setGheymat(newGheymat.toULongLong());
        income = QString::number(c.getPoorsant());
    }
    else
    {

    }

    ui->lineEdit_money_income->setText(income);
    ui->lineEdit_money_total->setText( QString::number(newGheymat.toULongLong() + income.toULongLong()) );

    if(ui->label_money_income->text() == "درآمد")
    {
        ui->lineEdit_money_income->setText(newGheymat);
        ui->lineEdit_money_total->setText(newGheymat);
    }
}
void Dialog_Memorandum::setMaxCkeckMoney()
{
    quint64 cash = ui->lineEdit_money_cash->text().toULongLong(),
            total = ui->lineEdit_money_total->text().toULongLong();
    if(cash > total)
    {
        ui->lineEdit_money_cash->setText(ui->lineEdit_money_total->text());
        return;
    }
    ui->lineEdit_money_check->setText(QString::number(total - cash));
}

