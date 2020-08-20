#include "SUV.h"

SUV::SUV( QString status,
          QString model,
          QString brand,
          QString year,
          QString color,
          QString inside_color,
          QString shomare_shasi,
          QString shomare_sanad,
          quint64 gheymat ,
              double poorsant) :
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
    this->poorsant = poorsant;
}

quint64 SUV::getPoorsant()
{
    return static_cast<quint64>(this->poorsant*getGheymat()) ;
}
SUV::~SUV()
{}
void SUV::loadFromJson(QJsonObject o)
{
    Car::loadFromJson(o);
    //add codes specific to this class
}
QJsonObject SUV::toJson()
{
    QJsonObject o = Car::toJson();
    //add codes specific to this class
    return o;
}
void SUV::addCar()
{
    Data::add(this->toJson(), "shomare sanad", this->getShomareSanad(), Data::default_suv_array_name, Data::default_suv_path);

}
QJsonArray loadSUVs_jsonArray()
{

    return Data::load_jsonArray(Data::default_suv_array_name, Data::default_suv_path);
}
SUV findSUV(QString shomare_sanad)
{
    SUV c;
    c.loadFromJson(Data::find("shomare sanad", shomare_sanad, Data::default_suv_array_name, Data::default_suv_path));
    return c;
}
