#include "Car.h"
Car::Car( QString status,
          QString model,
          QString brand,
          QString year,
          QString color,
          QString inside_color,
          QString shomare_shasi,
          QString shomare_sanad,
          quint64 gheymat )
{
    this->status = status;
    this->model = model;
    this->brand = brand;
    this->year = year;
    this->color = color;
    this->inside_color = inside_color;
    this->shomare_sanad =shomare_sanad ;
    this->shomare_shasi = shomare_shasi;
    this->gheymat = gheymat;
}
Car::~Car(){}
void Car::setStatus(QString status) { this->status = status; }
void Car::setModel(QString model) { this->model = model; }
void Car::setColor(QString color) { this->color = color; }
void Car::setInsideColor(QString inside_color) { this->inside_color = inside_color; }
void Car::setShomareShasi(QString shomare_shasi) { this->shomare_shasi = shomare_shasi; }
void Car::setShomareSanad(QString shomare_sanad) { this->shomare_sanad = shomare_sanad; }
void Car::setBrand(QString brand) { this->brand = brand; }
void Car::setGheymat(quint64 gheymat) { this->gheymat = gheymat; }
void Car::setYear(QString year) { this->year = year; }

QString Car::getStatus() const { return this->status; }
QString Car::getModel() const { return this->model; }
QString Car::getColor() const { return this->color; }
QString Car::getInsideColor() const { return this->inside_color; }
QString Car::getShomareShasi() const { return this->shomare_shasi; }
QString Car::getShomareSanad() const { return this->shomare_sanad; }
QString Car::getBrand() const { return this->brand; }
quint64 Car::getGheymat() const { return this->gheymat; }
QString Car::getYear() const { return this->year; }

quint64 Car::getPoorsant()
{
    return this->poorsant * gheymat;
}

void Car::loadFromJson(QJsonObject o)
{
    setStatus(o["status"].toString());
    setModel(o["model"].toString());
    setBrand(o["brand"].toString());
    setYear(o["year"].toString());
    setColor(o["color"].toString());
    setInsideColor(o["inside color"].toString());
    setShomareShasi(o["shomare shasi"].toString());
    setShomareSanad(o["shomare sanad"].toString());
    setGheymat(static_cast<quint64>((o["gheymat"].toString()).toULongLong()));
}
QJsonObject Car::toJson()
{
    QJsonObject o;
    o["status"] = getStatus();
    o["model"] = getModel();
    o["brand"] = getBrand();
    o["year"] = getYear();
    o["color"] = getColor();
    o["inside color"] = getInsideColor();
    o["shomare shasi"] = getShomareShasi();
    o["shomare sanad"] = getShomareSanad();
    o["gheymat"] = QString::number(getGheymat());
    return o;
}
void Car::addCar()
{
    Data::add(this->toJson(), "shomare sanad", this->getShomareSanad(), Data::default_car_array_name, Data::default_car_path);

}
QJsonArray loadAvailableCars_jsonArray()
{
    return Data::load_jsonArray(Data::default_car_array_name, Data::default_car_path);
}
Car findCar(QString shomare_sanad)
{
    Car c;
    c.loadFromJson(Data::find("shomare sanad", shomare_sanad, Data::default_car_array_name, Data::default_car_path));
    return c;
}
