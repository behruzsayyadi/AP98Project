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

void Memorandum(Car * car,Seller seller,Customer customer,QDate date,QString time)
{



    qDebug() << car->getPoorsant();
  /*  QFile Jfile_read("Documents/Memorandums.json");
    if(Jfile_read.open(QIODevice::ReadOnly) == false)
    {
        Jfile_read.close();
        QJsonObject memorandums_obj;
        QJsonArray memorandums_array;
        QJsonObject a_memorandum_obj;


        QJsonDocument doc_write(memorandums_obj);
        QFile Jfile_write("Documents/Memorandums.json");
        Jfile_write.open(QIODevice::WriteOnly);
        Jfile_write.write(doc_write.toJson());
        Jfile_write.close();
    }
    else
    {
        QByteArray qbyt_read ;
        qbyt_read = Jfile_read.readAll();
        Jfile_read.close();
        QJsonDocument doc_read = QJsonDocument::fromJson(qbyt_read);

        QJsonObject memorandums_obj = doc_read.object();


        QJsonDocument doc_write(memorandums_obj);


        QFile Jfile_write("Documents/Memorandums.json");
        Jfile_write.open(QIODevice::WriteOnly);
        Jfile_write.write(doc_write.toJson());
        Jfile_write.close();

    }*/


    return;
}







