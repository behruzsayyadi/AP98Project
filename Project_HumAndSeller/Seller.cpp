#include "Seller.h"





Seller::Seller(QString name,
               QString family,
               QDate birth_date,
               QString ID,
               QString shomare_shenasname,
               QString phone_number,
               QString job,
               QString job_phone)
{
    this->setName(name);
    this->setFamily(family);
    this->job = job;
    this->birth_date = birth_date;
    this->ID = ID;
    this->shomare_shenasname = shomare_shenasname;
    this->phone_number = phone_number;
    this->job_phone = job_phone;

}

Seller::Seller(Seller &a)
{
    this->setName(a.getName());
    this->setFamily(a.getFamily());
    this->setID(a.getID());
    this->setJob(a.getJob());
    this->setJobPhone(a.getPhoneNum());
    this->setBirthDate(a.getBirthDate());
    this->setShShenasname(a.getShShenasname());
    this->setPhoneNum(a.getPhoneNum());

}


Seller::Seller(Seller &&a)
{
    this->setName(a.getName());
    this->setFamily(a.getFamily());
    this->setID(a.getID());
    this->setJob(a.getJob());
    this->setJobPhone(a.getPhoneNum());
    this->setBirthDate(a.getBirthDate());
    this->setShShenasname(a.getShShenasname());
    this->setPhoneNum(a.getPhoneNum());
}


void Seller::setBirthDate(QDate birth_date)
{
    this->birth_date = birth_date;
}

QDate Seller::getBirthDate() const
{
    return  this->birth_date;
}

void Seller::setID(QString ID)
{
    this->ID = ID;
}

QString Seller::getID() const
{
    return this->ID;
}

void Seller::setShShenasname(QString shomare_shenasname)
{
    this->shomare_shenasname = shomare_shenasname;
}

QString Seller::getShShenasname() const
{
    return this->shomare_shenasname;
}

void Seller::setJob(QString job)
{
    this->job = job;
}

QString Seller::getJob() const
{
    return this->job;
}

void Seller::setJobPhone(QString job_phone)
{
    this->job_phone = job_phone;
}

QString Seller::getJobPhone() const
{
    return this->job_phone;
}

void Seller::setPhoneNum(QString phone_number)
{
    this->phone_number = phone_number;
}

QString Seller::getPhoneNum() const
{
    return this->phone_number;
}


void Seller::addSeller(QString sellersFileAddress)
{
    QFile Jfile_read(sellersFileAddress);
    if(Jfile_read.open(QIODevice::ReadOnly) == false)
    {
        Jfile_read.close();
        QJsonObject sellers_obj;
        QJsonArray sellers_array;
        QJsonObject a_seller_obj;
        a_seller_obj["name"] = this->getName();
        a_seller_obj["family"] = this->getFamily();
        QJsonObject a_seller_birth_date_obj;
        a_seller_birth_date_obj["year"] = this->getBirthDate().year();
        a_seller_birth_date_obj["month"]= this->getBirthDate().month();
        a_seller_birth_date_obj["day"]  = this->getBirthDate().day();
        a_seller_obj["date of birth"] = a_seller_birth_date_obj;
        a_seller_obj["ID"] = this->getID();
        a_seller_obj["shomare shenasname"] = this->getShShenasname();
        a_seller_obj["phone number"]       = this->getPhoneNum();
        a_seller_obj["job"]                = this->getJob();
        a_seller_obj["job phone"]          = this->getJobPhone();
        sellers_array.append(a_seller_obj);
        sellers_obj["sellers"] = sellers_array;
        QJsonDocument doc_write(sellers_obj);
        QFile Jfile_write(sellersFileAddress);
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

        QJsonObject sellers_obj = doc_read.object();
        QJsonArray sellers_array = sellers_obj["sellers"].toArray();
        QJsonObject a_seller_obj;
        a_seller_obj["name"] = this->getName();
        a_seller_obj["family"] = this->getFamily();
        QJsonObject a_seller_birth_date_obj;
        a_seller_birth_date_obj["year"] = this->getBirthDate().year();
        a_seller_birth_date_obj["month"]= this->getBirthDate().month();
        a_seller_birth_date_obj["day"]  = this->getBirthDate().day();
        a_seller_obj["date of birth"] = a_seller_birth_date_obj;
        a_seller_obj["ID"] = this->getID();
        a_seller_obj["shomare shenasname"] = this->getShShenasname();
        a_seller_obj["phone number"]       = this->getPhoneNum();
        a_seller_obj["job"]                = this->getJob();
        a_seller_obj["job phone"]          = this->getJobPhone();
        sellers_array.append(a_seller_obj);
        sellers_obj["sellers"] = sellers_array;
        QJsonDocument doc_write(sellers_obj);


        QFile Jfile_write(sellersFileAddress);
        Jfile_write.open(QIODevice::WriteOnly);
        Jfile_write.write(doc_write.toJson());
        Jfile_write.close();

    }


    return;
}

Seller findSeller(QString ID,QString sellersFileAddress)
{
    Seller found;
    QFile Jfile_read(sellersFileAddress);
    Jfile_read.open(QIODevice::ReadOnly);
    QByteArray qbyt = Jfile_read.readAll();
    Jfile_read.close();
    QJsonDocument doc_read = QJsonDocument::fromJson(qbyt);
    QJsonObject sellers_obj = doc_read.object();
    foreach (QJsonValue x, sellers_obj["sellers"].toArray())
    {
        if((x.toObject())["ID"] == ID)
        {

            found.setName((x.toObject())["name"].toString());
            found.setID((x.toObject())["ID"].toString());
            found.setJob((x.toObject())["job"].toString());
            found.setJobPhone((x.toObject())["job phone"].toString());
            found.setPhoneNum((x.toObject())["phone number"].toString());
            QJsonObject Jdate_obj = (x.toObject())["date of birth"].toObject();
            int year,month,day;
            year = Jdate_obj["year"].toInt();
            month = Jdate_obj["month"].toInt();
            day = Jdate_obj["day"].toInt();
            found.setBirthDate(QDate(year,month,day));
            found.setShShenasname((x.toObject())["shomare shenasname"].toString());
            found.setFamily((x.toObject())["family"].toString());
            return found;
        }

    }
    return found;

}



