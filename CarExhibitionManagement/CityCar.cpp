#include "CityCar.h"

CityCar::CityCar( QString status,
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

quint64 CityCar::getPoorsant()
{
    return static_cast<quint64>(this->poorsant*getGheymat()) ;
}
CityCar::~CityCar()
{}
void CityCar::loadFromJson(QJsonObject o)
{
    Car::loadFromJson(o);
    //add codes specific to this class
}
QJsonObject CityCar::toJson()
{
    QJsonObject o = Car::toJson();
    //add codes specific to this class
    return o;
}
void CityCar::addCar()
{
    Data::add(this->toJson(), "shomare sanad", this->getShomareSanad(), Data::default_citycar_array_name, Data::default_citycar_path);

}
QJsonArray loadCityCars_jsonArray()
{

    return Data::load_jsonArray(Data::default_citycar_array_name, Data::default_citycar_path);


}
CityCar findCityCar(QString shomare_sanad)
{
    CityCar c;
    c.loadFromJson(Data::find("shomare sanad", shomare_sanad, Data::default_citycar_array_name, Data::default_citycar_path));
    return c;
}
