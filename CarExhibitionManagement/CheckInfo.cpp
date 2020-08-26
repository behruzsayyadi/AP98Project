#include "CheckInfo.h"
#include<QString>
//Checkinfo::Checkinfo()
//    : money("")
//    , date(QDate(0,0,0))
//    , shenase("")
//{}

Checkinfo::Checkinfo(Checkinfo &other) :
    money(other.money),
    bank(other.bank),
    shobe_bank(other.shobe_bank),
    date(other.date),
    shenase(other.shenase)
{}

Checkinfo::Checkinfo(Checkinfo &&other):
    money(other.money),
    bank(other.bank),
    shobe_bank(other.shobe_bank),
    date(other.date),
    shenase(other.shenase)
{}

Checkinfo::Checkinfo(QString money,QString bank,QString shobe_bank,QDate date,QString shenase) :
    money(money),
    bank(bank),
    shobe_bank(shobe_bank),
    date(date),
    shenase(shenase)
{}

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

void Checkinfo::setBank(QString bank)
{
    this->bank = bank;
}

QString Checkinfo::getBank()
{
    return this->bank;
}

void Checkinfo::setShobeBank(QString shobe_bank)
{
    this->shobe_bank = shobe_bank;
}

QString Checkinfo::getShobeBank()
{
    return this->shobe_bank;
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
        a_check_obj["bank"] = this->getBank();
        a_check_obj["shobe bank"] = this->getShobeBank();
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
        a_check_obj["bank"] = this->getBank();
        a_check_obj["shobe bank"] = this->getShobeBank();
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
            found.setBank(x.toObject()["bank"].toString());
            found.setShobeBank(x.toObject()["shobe bank"].toString());
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

QJsonArray checks_jsonArray_sort_by_date(QJsonArray a)
{
    QJsonArray b = a;
//    int size_of_array = a.size();
    for(int i = 0; i < b.size() ; i++)
    {
        int swaps = 0;
        for(int j = 0;j < b.size()-i-1;j++)
        {
            QJsonObject j_date_obj = (b[j].toObject())["date"].toObject();
            QJsonObject jnext_date_obj = (b[j+1].toObject())["date"].toObject();
//            qDebug() << b[i].toObject() << endl << b[j].toObject();
            QJsonObject temp;
            int i_year,i_month,i_day,j_year,j_month,j_day;
            i_year = j_date_obj["year"].toInt();
            i_month = j_date_obj["month"].toInt();
            i_day = j_date_obj["day"].toInt();


            j_year = jnext_date_obj["year"].toInt();
            j_month = jnext_date_obj["month"].toInt();
            j_day = jnext_date_obj["day"].toInt();

            if(QDate(i_year,i_month,i_day) > QDate(j_year,j_month,j_day))
            {
//                qDebug() << b << endl << "**********************" << endl;
                temp = b[j].toObject();
                b.replace(j,b[j+1].toObject());
                b.replace(j+1,temp);
                swaps = 1;
//                qDebug() << b;

            }
            if(!swaps)
                break;


        }
    }
    return b;
}

QDate dateFromJsonObject(QJsonObject a)
{
    int year,month,day;
    year = a["year"].toInt();
    month = a["month"].toInt();
    day = a["day"].toInt();
    return QDate(year,month,day);

}
