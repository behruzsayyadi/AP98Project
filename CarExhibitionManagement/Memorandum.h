#ifndef MEMORANDUM_H
#define MEMORANDUM_H
#include <QMessageBox>
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

void Memorandum(Car * car,Seller seller,Customer customer,QDate date,QString time,QVector<Checkinfo*> checks_vector)
{

    QString path = "Documents/Memorandums/"+car->getShomareSanad()+".json";
    qDebug() << path;
    QFile Jfile_read(path);
    if(Jfile_read.open(QIODevice::ReadOnly) == false)
    {
        Jfile_read.close();
        QJsonObject memorandums_obj;
        QJsonArray memorandums_array;
        QJsonObject a_memorandum_obj;
        a_memorandum_obj["car brand"] = car->getBrand();
        a_memorandum_obj["car model"] = car->getModel();
        a_memorandum_obj["production year"] = car->getYear();
        a_memorandum_obj["color"] = car->getColor();
        a_memorandum_obj["inside color"] = car->getInsideColor();
        a_memorandum_obj["shomare shasi"] = car->getShomareShasi();
        a_memorandum_obj["shomare sanad"] = car->getShomareSanad();
        a_memorandum_obj["Gheymat"] = QString::number( car->getGheymat());
        a_memorandum_obj["poorsant"] =QString::number(car->getPoorsant());
        a_memorandum_obj["seller name"] = seller.getName();
        a_memorandum_obj["seller family"] = seller.getFamily();

        QJsonObject a_seller_birth_date_obj;
        a_seller_birth_date_obj["year"] = seller.getBirthDate().year();
        a_seller_birth_date_obj["month"]= seller.getBirthDate().month();
        a_seller_birth_date_obj["day"]  = seller.getBirthDate().day();
        a_memorandum_obj["seller birthdate"] = a_seller_birth_date_obj ;
        a_memorandum_obj["seller ID"] = seller.getID();
        a_memorandum_obj["seller shomare shenasname"] = seller.getShShenasname();
        a_memorandum_obj["seller job"] = seller.getJob();
        a_memorandum_obj["seller phone number"] = seller.getPhoneNum();
        a_memorandum_obj["seller job phone"] = seller.getJobPhone();


        a_memorandum_obj["customer name"] = customer.getName();
        a_memorandum_obj["customer family"] = customer.getFamily();

        QJsonObject a_customer_birth_date_obj;
        a_customer_birth_date_obj["year"] = customer.getBirthDate().year();
        a_customer_birth_date_obj["month"]= customer.getBirthDate().month();
        a_customer_birth_date_obj["day"]  = customer.getBirthDate().day();
        a_memorandum_obj["customer birthdate"] = a_customer_birth_date_obj ;
        a_memorandum_obj["customer ID"] = customer.getID();
        a_memorandum_obj["customer shomare shenasname"] = customer.getShShenasname();
        a_memorandum_obj["customer job"] = customer.getJob();
        a_memorandum_obj["customer phone number"] = customer.getPhoneNum();
        a_memorandum_obj["customer job phone"] = customer.getJobPhone();

        a_memorandum_obj["date of purchase"] = date.toString("yyyy/MM/dd");
        a_memorandum_obj["time of purchase"] = time;
        int j = 1;

        for(int i = 0; i < checks_vector.size();i++)
        {
            if(checks_vector.isEmpty()==false  )
            {
                Checkinfo * c = checks_vector.takeFirst();
                a_memorandum_obj["check "+QString::number(j)+" money"] = c->getMoney();
                a_memorandum_obj["check "+QString::number(j)+" bank"]  = c->getBank();
                a_memorandum_obj["check "+QString::number(j)+" shobe"] = c->getShobeBank();
                a_memorandum_obj["shenase "+QString::number(j)+" check"] = c->getShenase();
                QJsonObject a_check_date_obj;
                a_check_date_obj["year"] = customer.getBirthDate().year();
                a_check_date_obj["month"]= customer.getBirthDate().month();
                a_check_date_obj["day"]  = customer.getBirthDate().day();
                a_memorandum_obj["check"+QString::number(j)+" date"] = a_check_date_obj ;
                delete c;
                j++;
            }
        }
        memorandums_array.append(a_memorandum_obj);
        memorandums_obj ["memorandums"] = memorandums_array;
        QJsonDocument doc_write(memorandums_obj);
        QFile Jfile_write(path);
        Jfile_write.open(QIODevice::WriteOnly);
        Jfile_write.write(doc_write.toJson());
        Jfile_write.close();
    }
    else
    {

    }


    return;
}







#endif // MEMORANDUM_H
