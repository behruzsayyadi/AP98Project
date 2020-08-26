#include "Crook.h"

Crook::Crook( QString status,
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

quint64 Crook::getPoorsant()
{
//    return static_cast<quint64>(this->poorsant*getGheymat()) ;
    return static_cast<quint64>(0.02 * getGheymat());

}
Crook::~Crook()
{}
void Crook::loadFromJson(QJsonObject o)
{
    Car::loadFromJson(o);
    //add codes specific to this class
}
QJsonObject Crook::toJson()
{
    QJsonObject o = Car::toJson();
    //add codes specific to this class
    return o;
}
void Crook::addCar()
{
    Data::add(this->toJson(), "shomare sanad", this->getShomareSanad(), Data::default_crook_array_name, Data::default_crook_path);
}
QJsonArray loadCrooks_jsonArray()
{
    return Data::load_jsonArray(Data::default_crook_array_name, Data::default_crook_path);
}
Crook findCrook(QString shomare_sanad)
{
    Crook c;
    c.loadFromJson(Data::find("shomare sanad", shomare_sanad, Data::default_crook_array_name, Data::default_crook_path));
    return c;
}
