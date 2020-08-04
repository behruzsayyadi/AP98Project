#include "Seller.h"



Seller::Seller(QString name, QString family, QString birth_date, QString code_melli, QString phone_number, QString address)
    : Human::Human(name,family)
{
    this->address = address;
    this->birth_date = birth_date;
    this->code_melli = code_melli;
    this->phone_number = phone_number;
}
