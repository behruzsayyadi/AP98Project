#include "Human.h"

Human::Human(QString name,QString family,QString birth_date,QString code_melli,QString shomare_shenasname,QString phone_number,QString job,QString job_phone)
{
    this->name = name;
    this->family = family;
    this->job = job;
    this->birth_date = birth_date;
    this->code_melli = code_melli;
    this->shomare_shenasname = shomare_shenasname;
    this->phone_number = phone_number;
    this->job_phone = job_phone;
}

void Human::setName(QString name)
{
    this->name = name;
}

QString Human::getName() const
{
    return this->name;
}

void Human::setFamily(QString family)
{
    this->family = family;
}

QString Human::getFamily() const
{
    return this->family;
}

void Human::setBirthDate(QString birth_date)
{
    this->birth_date = birth_date;
}

QString Human::getBirthDate() const
{
    return  this->birth_date;
}

void Human::setCodeMelli(QString code_melli)
{
    this->code_melli = code_melli;
}

QString Human::getCodeMelli() const
{
    return this->code_melli;
}

void Human::setJob(QString job)
{
    this->job = job;
}

QString Human::getJob() const
{
    return this->job;
}

void Human::setJobPhone(QString job_phone)
{
    this->job_phone = job_phone;
}

QString Human::getJobPhone() const
{
    return this->job_phone;
}

void Human::setPhoneNum(QString phone_number)
{
    this->phone_number = phone_number;
}

QString Human::getPhoneNum() const
{
    return this->phone_number;
}
