#include "Vanet.h"

Vanet::Vanet( QString status,
          QString model,
          QString brand,
          QString year,
          QString color,
          QString inside_color,
          QString shomare_shasi,
          QString shomare_sanad,
          quint64 gheymat ) :
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

quint64 Vanet::getPoorsant()
{
//    return static_cast<quint64>(this->poorsant*getGheymat()) ;
    return static_cast<quint64>(0.015 * getGheymat());
}
Vanet::~Vanet()
{}
void Vanet::loadFromJson(QJsonObject o)
{
    Car::loadFromJson(o);
    //add codes specific to this class
}
QJsonObject Vanet::toJson()
{
    QJsonObject o = Car::toJson();
    //add codes specific to this class
    return o;
}
void Vanet::addCar()
{
    Data::add(this->toJson(), "shomare sanad", this->getShomareSanad(), Data::default_vanet_array_name, Data::default_vanet_path);
}
QJsonArray loadVanets_jsonArray()
{
    return Data::load_jsonArray(Data::default_vanet_array_name, Data::default_vanet_path);
}
Vanet findVanet(QString shomare_sanad)
{

    Vanet c;
    c.loadFromJson(Data::find("shomare sanad", shomare_sanad, Data::default_vanet_array_name, Data::default_vanet_path));
    return c;
}
