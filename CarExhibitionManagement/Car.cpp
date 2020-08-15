#include "Car.h"

Car::Car()
{

}
void Car::setpoorsant(double poorsant)
{
    this->poorsant = poorsant;
}
void Car:: setName(QString name){
    this->name=name;
}
void Car::setrang(QString rang){
    this->rang=rang;
}
void Car::setInrang(QString rang_dakhel){
    this->range_dakhel=rang_dakhel;
}
void Car::setshasi(QString shasi){
    this->shasi=shasi;
}
void Car::setsanad(QString sanad){
    this->sanad=sanad;
}
void Car::setbrand(QString brand){
    this->brand=brand;
}
void Car::setgheymat(QString gheymat){
    this->gheymat=gheymat;
}
void Car::setsal(QString sal){
    this->sale_tolid=sal;
}
QString Car::getName(){
    return name;
}
QString Car::getrang(){
    return  rang;
}
QString Car::getInrang(){
    return  range_dakhel;
}
QString Car::getshasi(){
    return shasi;
}
QString Car::getsanad(){
    return sanad;
}
QString Car::getbrand(){
    return  brand;
}
QString Car::getgheymat(){
    return  gheymat;
}
QString Car::getsal(){
    return  sale_tolid;
}
double Car::getpoorsant(){
    return poorsant;
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
            o["available cars"] = a;
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
            QJsonArray a = o["available cars"].toArray();
            qDebug() << a << o;
            return a;
        }
        else
        {
             qDebug() << "Couldn\'t open file: " + availableCarsAddress ;
        }
    }
    return QJsonArray();

}
//QJsonArray loadSoldCars_jsonArray(QString availableCarsAddress)
//{

//}
//QJsonArray loadBoughtCars_jsonArray(QString availableCarsAddress)
//{
//}
Car findCar(QString sanad, QString availableCarsAddress)
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
            if(o["sanad"] == sanad)
            {
                c.setName(o["name"].toString());
                c.setbrand(o["brand"].toString());
                c.setrang(o["rang"].toString());
                c.setsal(o["sal"].toString());
                c.setsanad(o["sanad"].toString());
                c.setshasi(o["shasi"].toString());
                c.setInrang(o["in rang"].toString());
                c.setgheymat(o["gheymat"].toString());
                c.setpoorsant(o["poorsant"].toDouble());
            }
        }
    }

    return c;
}
void Car::addCar(QString availableCarsAddress)
{
    if(findCar(getsanad()).getsanad() == getsanad())
    {
        qDebug() << "Car with this sanad already exists: " + getsanad();
    }
    else
    {
        QFile file(availableCarsAddress);
        QJsonObject t;
        t["name"] = getName();
        t["brand"] = getbrand();
        t["rang"] = getrang();
        t["sal"] = getsal();
        t["sanad"] = getsanad();
        t["shasi"] = getshasi();
        t["in rang"] = getInrang();
        t["gheymat"] = getgheymat();
        t["poorsant"] = getpoorsant();

        if(file.exists())
        {
            if(file.open(QIODevice::ReadOnly))
            {
                QJsonObject o (QJsonDocument::fromJson(file.readAll()).object());
                file.close();
                file.open(QIODevice::WriteOnly);
                QJsonArray a = o["available cars"].toArray();
                a.append(t);
                o["available cars"] = a;
                file.write(QJsonDocument(o).toJson());
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
                o["available cars"] = a;
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
