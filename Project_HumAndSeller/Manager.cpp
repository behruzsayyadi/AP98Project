#include "Manager.h"

Manager::Manager(QString name,
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

Manager::Manager(Manager &a)
{
    this->setName(a.getName());
    this->setFamily(a.getFamily());
    this->setID(a.getID());
    this->setJob(a.getJob());
    this->setJobPhone(a.getPhoneNum());
    this->setBirthDate(a.getBirthDate());
    this->setShShenasname(a.getShShenasname());
    this->setPhoneNum(a.getPhoneNum());
    this->setUsername(a.getUsername());
    this->setPassword(a.getPassword());
}


Manager::Manager(Manager &&a)
{
    this->setName(a.getName());
    this->setFamily(a.getFamily());
    this->setID(a.getID());
    this->setJob(a.getJob());
    this->setJobPhone(a.getPhoneNum());
    this->setBirthDate(a.getBirthDate());
    this->setShShenasname(a.getShShenasname());
    this->setPhoneNum(a.getPhoneNum());
    this->setUsername(a.getUsername());
    this->setPassword(a.getPassword());
}

void Manager::setBirthDate(QDate birth_date)
{
    this->birth_date = birth_date;
}

QDate Manager::getBirthDate() const
{
    return  this->birth_date;
}

void Manager::setID(QString ID)
{
    this->ID = ID;
}

QString Manager::getID() const
{
    return this->ID;
}

void Manager::setShShenasname(QString shomare_shenasname)
{
    this->shomare_shenasname = shomare_shenasname;
}

QString Manager::getShShenasname() const
{
    return this->shomare_shenasname;
}

void Manager::setJob(QString job)
{
    this->job = job;
}

QString Manager::getJob() const
{
    return this->job;
}

void Manager::setJobPhone(QString job_phone)
{
    this->job_phone = job_phone;
}

QString Manager::getJobPhone() const
{
    return this->job_phone;
}

void Manager::setUsername(QString username)
{
    this->username = username;
}

QString Manager::getUsername()
{
    return this->username;
}

void Manager::setPassword(QString password)
{
    this->password = password;
}

QString Manager::getPassword()
{
    return this->password;
}

void Manager::setPhoneNum(QString phone_number)
{
    this->phone_number = phone_number;
}

QString Manager::getPhoneNum() const
{
    return this->phone_number;
}


void Manager::addManager(QString managersFileAddress)
{
    QJsonObject managers_obj;
    QJsonArray managers_array;
    QJsonObject a_manager_obj;
    a_manager_obj["name"] = this->getName();
    a_manager_obj["family"] = this->getFamily();
    QJsonObject a_manager_birth_date_obj;
    a_manager_birth_date_obj["year"] = this->getBirthDate().year();
    a_manager_birth_date_obj["month"]= this->getBirthDate().month();
    a_manager_birth_date_obj["day"]  = this->getBirthDate().day();
    a_manager_obj["date of birth"] = a_manager_birth_date_obj;
    a_manager_obj["ID"] = this->getID();
    a_manager_obj["shomare shenasname"] = this->getShShenasname();
    a_manager_obj["phone number"]       = this->getPhoneNum();
    a_manager_obj["job"]                = this->getJob();
    a_manager_obj["job phone"]          = this->getJobPhone();
    a_manager_obj["username"]           = this->getUsername();
    a_manager_obj["password"]           = this->getPassword();
    managers_array.append(a_manager_obj);
    managers_obj["managers"] = managers_array;
    QJsonDocument doc_write(managers_obj);
    QFile Jfile_write(managersFileAddress);
    Jfile_write.open(QIODevice::WriteOnly);
    Jfile_write.write(doc_write.toJson());
    Jfile_write.close();
    return;
}

bool managerLogin(QString username,QString passowrd,QString managersFileAddress)
{
    QFile Jfile_read(managersFileAddress);
    Jfile_read.open(QIODevice::ReadOnly);
    QByteArray qbyt = Jfile_read.readAll();
    Jfile_read.close();
    QJsonDocument doc_read = QJsonDocument::fromJson(qbyt);
    QJsonObject managers_obj = doc_read.object();
    foreach (QJsonValue x, managers_obj["managers"].toArray())
    {
        if((x.toObject())["username"] == username)
        {

            if((x.toObject())["password"] == passowrd)
            {
                return 1;
            }
        }

    }
    return 0;
}

Manager loadManager(QString managersFileAddress)
{
    QFile Jfile_read(managersFileAddress);
    Jfile_read.open(QIODevice::ReadOnly);
    QByteArray qbyt = Jfile_read.readAll();
    Jfile_read.close();
    QJsonDocument doc_read = QJsonDocument::fromJson(qbyt);
    QJsonObject managers_obj = doc_read.object();
    QJsonArray managers_array = managers_obj["managers"].toArray();
    Manager temp;

    QJsonObject a_manager = managers_array[0].toObject();

    temp.setUsername(a_manager["username"].toString());
    temp.setPassword(a_manager["password"].toString());
    temp.setID(a_manager["ID"].toString());
    temp.setJob(a_manager["job"].toString());
    temp.setName(a_manager["name"].toString());
    temp.setFamily(a_manager["family"].toString());
    temp.setJobPhone(a_manager["job phone"].toString());
    temp.setPhoneNum(a_manager["phone number"].toString());
    temp.setShShenasname(a_manager["shomare shenasname"].toString());
    QJsonObject Jdate_obj = a_manager["date of birth"].toObject();
    int year,month,day;
    year = Jdate_obj["year"].toInt();
    month = Jdate_obj["month"].toInt();
    day = Jdate_obj["day"].toInt();
    temp.setBirthDate(QDate(year,month,day));
    return temp;
}
