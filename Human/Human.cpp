#include "Human.h"

Human::Human(QString name,QString family,QString birth_date,QString code_melli,QString phone_number,QString address)
{
    this->name = name;
    this->family = family;
    this->address = address;
    this->birth_date = birth_date;
    this->code_melli = code_melli;
    this->phone_number = phone_number;
}

void Human::setName(QString name)
{
    this->name = name;
}

QString Human::getName()
{
    return this->name;
}

void Human::setFamily(QString family)
{
    this->family = family;
}

QString Human::getFamily()
{
    return this->family;
}

void Human::setBirthDate(QString birth_date)
{
    this->birth_date = birth_date;
}

QString Human::getBirthDate()
{
    return  this->birth_date;
}

void Human::setCodeMelli(QString code_melli)
{
    this->code_melli = code_melli;
}

QString Human::getCodeMelli()
{
    return this->code_melli;
}

void Human::setAddress(QString address)
{
    this->address = address;
}

QString Human::getAddress()
{
    return this->address;
}

void Human::setPhoneNum(QString phone_number)
{
    this->phone_number = phone_number;
}

QString Human::getPhoneNum()
{
    return this->phone_number;
}
