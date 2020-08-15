#include "Customer.h"


Customer::Customer(QString name,
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

Customer::Customer(Customer &a)
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


Customer::Customer(Customer &&a)
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


void Customer::setBirthDate(QDate birth_date)
{
    this->birth_date = birth_date;
}

QDate Customer::getBirthDate() const
{
    return  this->birth_date;
}

void Customer::setID(QString ID)
{
    this->ID = ID;
}

QString Customer::getID() const
{
    return this->ID;
}

void Customer::setShShenasname(QString shomare_shenasname)
{
    this->shomare_shenasname = shomare_shenasname;
}

QString Customer::getShShenasname() const
{
    return this->shomare_shenasname;
}

void Customer::setJob(QString job)
{
    this->job = job;
}

QString Customer::getJob() const
{
    return this->job;
}

void Customer::setJobPhone(QString job_phone)
{
    this->job_phone = job_phone;
}

QString Customer::getJobPhone() const
{
    return this->job_phone;
}

void Customer::setPhoneNum(QString phone_number)
{
    this->phone_number = phone_number;
}

QString Customer::getPhoneNum() const
{
    return this->phone_number;
}


void Customer::addCustomer(QString customersFileAddress)
{
    QFile Jfile_read(customersFileAddress);
    if(Jfile_read.open(QIODevice::ReadOnly) == false)
    {
        Jfile_read.close();
        QJsonObject customers_obj;
        QJsonArray customers_array;
        QJsonObject a_customer_obj;
        a_customer_obj["name"] = this->getName();
        a_customer_obj["family"] = this->getFamily();
        QJsonObject a_customer_birth_date_obj;
        a_customer_birth_date_obj["year"] = this->getBirthDate().year();
        a_customer_birth_date_obj["month"]= this->getBirthDate().month();
        a_customer_birth_date_obj["day"]  = this->getBirthDate().day();
        a_customer_obj["date of birth"] = a_customer_birth_date_obj;
        a_customer_obj["ID"] = this->getID();
        a_customer_obj["shomare shenasname"] = this->getShShenasname();
        a_customer_obj["phone number"]       = this->getPhoneNum();
        a_customer_obj["job"]                = this->getJob();
        a_customer_obj["job phone"]          = this->getJobPhone();
        customers_array.append(a_customer_obj);
        customers_obj["customers"] = customers_array;
        QJsonDocument doc_write(customers_obj);
        QFile Jfile_write(customersFileAddress);
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

        QJsonObject customers_obj = doc_read.object();
        QJsonArray customers_array = customers_obj["customers"].toArray();
        QJsonObject a_customer_obj;
        a_customer_obj["name"] = this->getName();
        a_customer_obj["family"] = this->getFamily();
        QJsonObject a_customer_birth_date_obj;
        a_customer_birth_date_obj["year"] = this->getBirthDate().year();
        a_customer_birth_date_obj["month"]= this->getBirthDate().month();
        a_customer_birth_date_obj["day"]  = this->getBirthDate().day();
        a_customer_obj["date of birth"] = a_customer_birth_date_obj;
        a_customer_obj["ID"] = this->getID();
        a_customer_obj["shomare shenasname"] = this->getShShenasname();
        a_customer_obj["phone number"]       = this->getPhoneNum();
        a_customer_obj["job"]                = this->getJob();
        a_customer_obj["job phone"]          = this->getJobPhone();
        customers_array.append(a_customer_obj);
        customers_obj["customers"] = customers_array;
        QJsonDocument doc_write(customers_obj);


        QFile Jfile_write(customersFileAddress);
        Jfile_write.open(QIODevice::WriteOnly);
        Jfile_write.write(doc_write.toJson());
        Jfile_write.close();

    }


    return;
}


Customer findCustomer(QString ID,QString customersFileAddress)
{
    Customer found;
    QFile Jfile_read(customersFileAddress);
    Jfile_read.open(QIODevice::ReadOnly);
    QByteArray qbyt = Jfile_read.readAll();
    Jfile_read.close();
    QJsonDocument doc_read = QJsonDocument::fromJson(qbyt);
    QJsonObject customers_obj = doc_read.object();
    foreach (QJsonValue x, customers_obj["customers"].toArray())
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
