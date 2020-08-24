#ifndef MEMORANDUM_H
#define MEMORANDUM_H
#include <QMessageBox>

#include "Data.h"

#include "Human.h"
#include "Manager.h"
#include "Customer.h"
#include "Seller.h"

#include "Car.h"

#include "SUV.h"
#include "Crook.h"
#include "CityCar.h"
#include "Coupe.h"
#include "Vanet.h"
#include "CheckInfo.h"

void Memorandum(Car * car,Seller seller,Customer customer,QDateTime date,QVector<Checkinfo*> checks_vector)
{

    QString path = "Documents/Memorandums/" + car->getShomareSanad() + ".json";
    qDebug() << "created file : " + path;


    QJsonObject memorandum_object;
    QJsonObject seller_object;
    QJsonObject customer_object;
    QJsonObject car_object;
    QJsonArray checks_array;

    QFile memorandum_file(path);
    QFile all_memorandums_file("Documents/Memorandums.json");

    seller_object["name"] = seller.getName();
    seller_object["family"] = seller.getFamily();
    seller_object["id"] = seller.getID();
    seller_object["shomare shenasname"] = seller.getShShenasname();
    seller_object["birth date"] = seller.getBirthDate().toString();
    seller_object["phone number"] = seller.getPhoneNum();
    seller_object["job"] = seller.getJob();
    seller_object["job phone"] = seller.getJobPhone();

    customer_object["name"] = customer.getName();
    customer_object["family"] = customer.getFamily();
    customer_object["id"] = customer.getID();
    customer_object["shomare shenasname"] = customer.getShShenasname();
    customer_object["birth date"] = customer.getBirthDate().toString();
    customer_object["phone number"] = customer.getPhoneNum();
    customer_object["job"] = customer.getJob();
    customer_object["job phone"] = customer.getJobPhone();

    car_object["model"] = car->getModel();
    car_object["brand"] = car->getBrand();
    car_object["year"] = car->getYear();
    car_object["color"] = car->getColor();
    car_object["inside color"] = car->getInsideColor();
    car_object["gheymat"] = QString::number(car->getGheymat());
    car_object["shomare shasi"] = car->getShomareShasi();
    car_object["shomare sanad"] = car->getShomareSanad();

    QJsonObject temp_check_object;
    for(Checkinfo * check : checks_vector)
    {
        temp_check_object["money"] = check->getMoney();
        temp_check_object["bank"] = check->getBank();
        temp_check_object["shobe bank"] = check->getShobeBank();
        temp_check_object["shenase"] = check->getShenase();
        temp_check_object["date"] = check->getDate().toString();
        checks_array.append(temp_check_object);
        check->addCheck();
        delete check;
    }

    memorandum_object["seller"] = seller_object;
    memorandum_object["customer"] = customer_object;
    memorandum_object["car"] = car_object;
    memorandum_object["date and time"] = date.toString();
    memorandum_object["checks"] = checks_array;
    if(memorandum_file.exists())
    {
        qDebug() << "memorandum with this number already exists";
    }
    else if( memorandum_file.open(QIODevice::WriteOnly) )
    {
        memorandum_file.write(QJsonDocument(memorandum_object).toJson());
        memorandum_file.close();
    }


    QJsonObject m;
    m["seller name"] = seller.getName() + ' ' + seller.getFamily();
    m["customer name"] = customer.getName() + ' ' + customer.getFamily();
    m["date and time"] = date.toString();
    m["car"] = car->getModel() + ' ' + car->getBrand() + ' ' + car->getYear() ;
    m["poorsant"] = QString::number(car->getPoorsant());
    m["shomare sanad"] = car->getShomareSanad();

    Data::add(m, "shomare sanad", m["shomare sanad"], Data::default_all_memorandums_array_name, Data::default_all_memorandums_path);

//    if(all_memorandums_file.exists())
//    {
//        all_memorandums_file.open(QIODevice::ReadOnly);
//        QJsonObject all_memorandums_object = QJsonDocument::fromJson(all_memorandums_file.readAll()).object();
//        all_memorandums_file.close();

//        QJsonArray all_memorandums_array = all_memorandums_object["memorandums"].toArray();

//        all_memorandums_array.append(m);

//        all_memorandums_object["memorandums"] = all_memorandums_array;

//        all_memorandums_file.open(QIODevice::WriteOnly);

//        all_memorandums_file.write( QJsonDocument(all_memorandums_object).toJson() );

//        all_memorandums_file.close();
//    }
//    else
//    {
//        qDebug() << "there is no file for all memorandums."
//                 << "creating a new one";
//        all_memorandums_file.open(QIODevice::WriteOnly);
//        QJsonObject all_memorandums_object;
//        QJsonArray all_memorandums_array;
//        all_memorandums_array.append(m);
//        all_memorandums_object["memorandums"] = all_memorandums_array;
//        all_memorandums_file.write(QJsonDocument(all_memorandums_object).toJson());
//        all_memorandums_file.close();
//    }
//    QFile Jfile_read(path);
//    if(Jfile_read.open(QIODevice::ReadOnly) == false)
//    {


//        Jfile_read.close();
//        QJsonObject a_memorandum_obj;
//        a_memorandum_obj["car brand"] = car->getBrand();
//        a_memorandum_obj["car model"] = car->getModel();
//        a_memorandum_obj["production year"] = car->getYear();
//        a_memorandum_obj["color"] = car->getColor();
//        a_memorandum_obj["inside color"] = car->getInsideColor();
//        a_memorandum_obj["shomare shasi"] = car->getShomareShasi();
//        a_memorandum_obj["shomare sanad"] = car->getShomareSanad();
//        a_memorandum_obj["Gheymat"] = QString::number( car->getGheymat());
//        a_memorandum_obj["poorsant"] =QString::number(car->getPoorsant());
//        a_memorandum_obj["seller name"] = seller.getName();
//        a_memorandum_obj["seller family"] = seller.getFamily();

//        QJsonObject a_seller_birth_date_obj;
//        a_seller_birth_date_obj["year"] = seller.getBirthDate().year();
//        a_seller_birth_date_obj["month"]= seller.getBirthDate().month();
//        a_seller_birth_date_obj["day"]  = seller.getBirthDate().day();
//        a_memorandum_obj["seller birthdate"] = a_seller_birth_date_obj ;
//        a_memorandum_obj["seller ID"] = seller.getID();
//        a_memorandum_obj["seller shomare shenasname"] = seller.getShShenasname();
//        a_memorandum_obj["seller job"] = seller.getJob();
//        a_memorandum_obj["seller phone number"] = seller.getPhoneNum();
//        a_memorandum_obj["seller job phone"] = seller.getJobPhone();


//        a_memorandum_obj["customer name"] = customer.getName();
//        a_memorandum_obj["customer family"] = customer.getFamily();

//        QJsonObject a_customer_birth_date_obj;
//        a_customer_birth_date_obj["year"] = customer.getBirthDate().year();
//        a_customer_birth_date_obj["month"]= customer.getBirthDate().month();
//        a_customer_birth_date_obj["day"]  = customer.getBirthDate().day();
//        a_memorandum_obj["customer birthdate"] = a_customer_birth_date_obj ;
//        a_memorandum_obj["customer ID"] = customer.getID();
//        a_memorandum_obj["customer shomare shenasname"] = customer.getShShenasname();
//        a_memorandum_obj["customer job"] = customer.getJob();
//        a_memorandum_obj["customer phone number"] = customer.getPhoneNum();
//        a_memorandum_obj["customer job phone"] = customer.getJobPhone();

//        a_memorandum_obj["date of purchase"] = date.toString("yyyy/MM/dd");
//        a_memorandum_obj["time of purchase"] = time;
//        int j = 1;

//        for(Checkinfo * c : checks_vector)
//        {
//            a_memorandum_obj["check "+QString::number(j)+" money"] = c->getMoney();
//            a_memorandum_obj["check "+QString::number(j)+" bank"]  = c->getBank();
//            a_memorandum_obj["check "+QString::number(j)+" shobe"] = c->getShobeBank();
//            a_memorandum_obj["shenase "+QString::number(j)+" check"] = c->getShenase();
//            QJsonObject a_check_date_obj;
//            a_check_date_obj["year"] = customer.getBirthDate().year();
//            a_check_date_obj["month"]= customer.getBirthDate().month();
//            a_check_date_obj["day"]  = customer.getBirthDate().day();
//            a_memorandum_obj["check"+QString::number(j)+" date"] = a_check_date_obj ;
//            c->addCheck();
//            delete c;
//            j++;
//        }

//        QJsonDocument doc_write(a_memorandum_obj);

//        QFile Jfile_write(path);
//        Jfile_write.open(QIODevice::WriteOnly);
//        Jfile_write.write(doc_write.toJson());
//        Jfile_write.close();

//    }
//    else
//    {

//    }
//    QFile Jfile__read("Documents/Memorandums.json");
//    if(Jfile__read.open(QIODevice::ReadOnly) == false)
//    {
//        Jfile__read.close();
//        QJsonObject memorandums_obj;
//        QJsonArray memorandums_array;
//        QJsonObject a_memorandum_object;
//        a_memorandum_object["seller name"] = seller.getName();
//        a_memorandum_object["customer name"] = customer.getName();
//        a_memorandum_object["money"] = QString::number( car->getGheymat() );
//        a_memorandum_object["poorsant"] = QString::number( car->getPoorsant() );
//        a_memorandum_object["car"] = car->getBrand() + " " + car->getModel() + " " + car->getYear();
//        memorandums_array.append(a_memorandum_object);
//        memorandums_obj["memorandums"] = memorandums_array;
//        QJsonDocument doc_write(memorandums_obj);
//        QFile memo_write("Documents/Memorandums.json");
//        memo_write.open(QIODevice::WriteOnly);
//        memo_write.write(doc_write.toJson());
//        memo_write.close();
//    }
//    else
//    {
//        QByteArray qbyt ;
//        qbyt = Jfile__read.readAll();
//        Jfile__read.close();
//        QJsonDocument doc_read = QJsonDocument::fromJson(qbyt);
//        QJsonObject memorandums_obj = doc_read.object();
//        QJsonArray memorandums_array = memorandums_obj["memorandums"].toArray();
//        QJsonObject a_memorandum_object;
//        a_memorandum_object["seller name"] = seller.getName();
//        a_memorandum_object["customer name"] = customer.getName();
//        a_memorandum_object["money"] = QString::number( car->getGheymat() );
//        a_memorandum_object["poorsant"] = QString::number( car->getPoorsant() );
//        a_memorandum_object["car"] = car->getBrand() + " " + car->getModel() + " " + car->getYear();
//        memorandums_array.append(a_memorandum_object);
//        memorandums_obj["memorandums"] = memorandums_array;
//        QJsonDocument doc_write(memorandums_obj);
//        QFile memo_write("Documents/Memorandums.json");
//        memo_write.open(QIODevice::WriteOnly);
//        memo_write.write(doc_write.toJson());
//        memo_write.close();

//    }



    return;
}







#endif // MEMORANDUM_H
