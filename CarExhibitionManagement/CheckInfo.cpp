#include "CheckInfo.h"
#include<QString>
Checkinfo::Checkinfo()
    : money("")
    , date(QDate(0,0,0))
    , shenase("")
{

}

Checkinfo::Checkinfo(Checkinfo &a)
{
    this->date  = a.getDate();
    this->money = a.getMoney();
    this->date  = a.getDate();

}

Checkinfo::Checkinfo(Checkinfo &&a)
{
    this->date  = a.getDate();
    this->money = a.getMoney();
    this->date  = a.getDate();

}

Checkinfo::Checkinfo(QString money,QDate date,QString shenase)
{
    this->money=money;
    this->date=date;
    this->shenase=shenase;
}

void Checkinfo::setMoney(QString money)
{
    this->money=money;
}

void Checkinfo:: setDate(QDate date)
{
    this->date=date;
}

void Checkinfo:: setShenase(QString shenase)
{
    this->shenase=shenase;
}

QString Checkinfo::getMoney()
{
    return this->money;
}

QDate Checkinfo::getDate()
{
    return this->date;
}

QString Checkinfo::getShenase()
{
    return this->shenase;
}

void Checkinfo::addCheck(QString checksFileAddress)
{
    QFile Jfile_read(checksFileAddress);
    if(Jfile_read.open(QIODevice::ReadOnly) == false)
    {
        Jfile_read.close();
        QJsonObject checks_obj;
        QJsonArray checks_array;
        QJsonObject a_check_obj;
        a_check_obj["money"] = this->getMoney();
        a_check_obj["shenase check"] = this->getShenase();
        QJsonObject a_check_date_obj;
        a_check_date_obj["year"] = this->getDate().year();
        a_check_date_obj["month"]= this->getDate().month();
        a_check_date_obj["day"]  = this->getDate().day();
        a_check_obj["date"] = a_check_date_obj;
        checks_array.append(a_check_obj);
        checks_obj["checks"] = checks_array;
        QJsonDocument doc_write(checks_obj);
        QFile Jfile_write(checksFileAddress);
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



        QJsonObject checks_obj = doc_read.object();
        QJsonArray checks_array = checks_obj["checks"].toArray();
        QJsonObject a_check_obj;
        a_check_obj["money"] = this->getMoney();
        a_check_obj["shenase check"] = this->getShenase();
        QJsonObject a_check_date_obj;
        a_check_date_obj["year"] = this->getDate().year();
        a_check_date_obj["month"]= this->getDate().month();
        a_check_date_obj["day"]  = this->getDate().day();
        a_check_obj["date"] = a_check_date_obj;
        checks_array.append(a_check_obj);
        checks_obj["checks"] = checks_array;
        QJsonDocument doc_write(checks_obj);



        QFile Jfile_write(checksFileAddress);
        Jfile_write.open(QIODevice::WriteOnly);
        Jfile_write.write(doc_write.toJson());
        Jfile_write.close();

    }


    return;
}

QJsonArray loadChecks_jsonArray(QString checksFileAddress)
{
    QFile checks_read(checksFileAddress);
    checks_read.open(QIODevice::ReadOnly);
    QByteArray qbyt = checks_read.readAll();
    checks_read.close();


    QJsonDocument checks_doc = QJsonDocument::fromJson(qbyt);
    QJsonObject checks_obj = checks_doc.object();
    QJsonArray checks_array = checks_obj["checks"].toArray();
    return checks_array;
}

Checkinfo findCheck(QString shenase, QString checksFileAddress)
{
    Checkinfo found;
    QJsonArray checks_array = loadChecks_jsonArray(checksFileAddress);
    foreach(QJsonValue x,checks_array)
    {
        if(x.toObject()["shenase check"] == shenase)
        {
            found.setMoney(x.toObject()["money"].toString());
            found.setShenase(x.toObject()["shenase check"].toString());
            QJsonObject date_obj = x.toObject()["date"].toObject();
            int year,month,day;
            year = date_obj["year"].toInt();
            month = date_obj["month"].toInt();
            day   = date_obj["day"].toInt();
            found.setDate(QDate(year,month,day));
            return found;

        }
    }
    return found;
}
