#include "Coupe.h"

Coupe::Coupe( QString status,
          QString model,
          QString brand,
          QString year,
          QString color,
          QString inside_color,
          QString shomare_shasi,
          QString shomare_sanad,
          quint64 gheymat) :
    Car( status,
         model,
         brand,
         year,
         color,
         inside_color,
         shomare_shasi,
         shomare_sanad,
         gheymat )
{
//    this->poorsant = poorsant;
}

quint64 Coupe::getPoorsant()
{
//    return static_cast<quint64>(this->poorsant*getGheymat()) ;
    return static_cast<quint64>(0.005 * getGheymat());

}
Coupe::~Coupe()
{}
void Coupe::loadFromJson(QJsonObject o)
{
    Car::loadFromJson(o);
    //add codes specific to this class
}
QJsonObject Coupe::toJson()
{
    QJsonObject o = Car::toJson();
    //add codes specific to this class
    return o;
}
void Coupe::addCar()
{
    Data::add(this->toJson(), "shomare sanad", this->getShomareSanad(), Data::default_coupe_array_name, Data::default_coupe_path);

}
QJsonArray loadCoupes_jsonArray()
{

    return Data::load_jsonArray(Data::default_coupe_array_name, Data::default_coupe_path);

}
Coupe findCoupe(QString shomare_sanad)
{
    Coupe c;
    c.loadFromJson(Data::find("shomare sanad", shomare_sanad, Data::default_coupe_array_name, Data::default_coupe_path));

    return c;
}
