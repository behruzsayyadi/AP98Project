#include "Car.h"
int Car::last_shomare_sanad = 0;
Car::Car( QString status,
          QString model,
          QString brand,
          QString year,
          QString color,
          QString inside_color,
          QString shomare_shasi,
          int shomare_sanad,
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
void Car::setShomareSanad(int shomare_sanad) { this->shomare_sanad = shomare_sanad; }
void Car::setBrand(QString brand) { this->brand = brand; }
void Car::setGheymat(quint64 gheymat) { this->gheymat = gheymat; }
void Car::setYear(QString year) { this->year = year; }

QString Car::getStatus() const { return this->status; }
QString Car::getModel() const { return this->model; }
QString Car::getColor() const { return this->color; }
QString Car::getInsideColor() const { return this->inside_color; }
QString Car::getShomareShasi() const { return this->shomare_shasi; }
QString Car::getBrand() const { return this->brand; }
quint64 Car::getGheymat() const { return this->gheymat; }
QString Car::getYear() const { return this->year; }

quint64 Car::getPoorsant()
{
    return this->poorsant * gheymat;
}
int Car::getShomareSanad() const { return this->shomare_sanad; }

void Car::loadFromJson(QJsonObject o)
{
    setStatus(o["status"].toString());
    setModel(o["model"].toString());
    setBrand(o["brand"].toString());
    setYear(o["year"].toString());
    setColor(o["color"].toString());
    setInsideColor(o["inside color"].toString());
    setShomareShasi(o["shomare shasi"].toString());
    setShomareSanad(o["shomare sanad"].toInt());
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
void Car::addCar(QString availableCarsAddress)
{
    int ss = this->getShomareSanad();
    if(ss == 0)
    {
        qDebug() << "shomare sanad is needed for adding car";
        return;
    }
    else if( findCar(ss).getShomareSanad() == ss )
    {//if we can find a car with shomare sanad as this car's:
        qDebug() << "Car with this shomare sanad already exists: " << ss;
        return;
    }
    else
    {
        QFile file(availableCarsAddress);
        QJsonObject t = this->toJson();

        if(file.exists())
        {
            if(file.open(QIODevice::ReadOnly))
            {
                QJsonObject o (QJsonDocument::fromJson(file.readAll()).object());
                file.close();
                file.open(QIODevice::WriteOnly);
                QJsonArray a = o["Car"].toArray();
                a.append(t);
                o["Car"] = a;
                file.write( QJsonDocument(o).toJson() );
                file.close();
            }
            else
            {
                qDebug() << "Couldn\'t open file: " + availableCarsAddress ;
            }
        }
        else
        {
            qDebug() << "No such file: " + availableCarsAddress
                     << "Creating a new one ...";

            if(file.open(QIODevice::WriteOnly))
            {
                QJsonObject o;
                QJsonArray a;
                a.append(t);
                o["Car"] = a;
                file.write(QJsonDocument(o).toJson());
                file.close();
                qDebug() << "File created successfuly: " + availableCarsAddress;
            }
            else
            {
                qDebug() << "Couldn\'t open file: " + availableCarsAddress ;
            }
        }
    }
}
QJsonArray loadAvailableCars_jsonArray(QString availableCarsAddress)
{
    QFile file(availableCarsAddress);
    if(!file.exists())
    {
        qDebug() << "No such file: " + availableCarsAddress
                 << "Creating a new one ...";

        if( file.open(QIODevice::WriteOnly))
        {
            QJsonObject o;
            QJsonArray a;
            o["Car"] = a;
            file.write(QJsonDocument(o).toJson());
            qDebug() << "File created successfuly: " + availableCarsAddress;
        }
        else
        {
            qDebug() << "Problem making and writing to file: " + availableCarsAddress;
        }
        return QJsonArray();
    }
    else
    {
        if(file.open(QIODevice::ReadOnly))
        {
            QByteArray ba = file.readAll();
            file.close();

            QJsonObject o = QJsonDocument::fromJson(ba).object();
            QJsonArray a = o["Car"].toArray();
            return a;
        }
        else
        {
             qDebug() << "Couldn\'t open file: " + availableCarsAddress ;
        }
    }
    return QJsonArray();

}
Car findCar(int shomare_sanad, QString availableCarsAddress)
{
    Car c;
    QJsonArray a = loadAvailableCars_jsonArray(availableCarsAddress);
    if(a.isEmpty())
    {
        qDebug() << "List of cars is empty."
                 << "file address:" + availableCarsAddress;
    }
    else
    {
        foreach(QJsonValue v, a)
        {
            QJsonObject o = v.toObject();
            if(o["shomare sanad"].toInt() == shomare_sanad)
            {
                c.loadFromJson(o);
            }
        }
    }

    return c;
}
