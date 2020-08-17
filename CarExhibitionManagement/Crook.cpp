#include "Crook.h"

Crook::Crook( QString status,
          QString model,
          QString brand,
          QString year,
          QString color,
          QString inside_color,
          QString shomare_shasi,
          int shomare_sanad,
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

quint64 Crook::getPoorsant()
{
    return static_cast<quint64>(this->poorsant*getGheymat()) ;
}
Crook::~Crook()
{}
//void Crook::loadFromJson(QJsonObject o)
//{
//    Car * bp = this;
//    bp->loadFromJson(o);
//    //add codes specific to this class

//}
//QJsonObject Crook::toJson()
//{
//    Car * bp = this;
//    QJsonObject o ;
//    bp->toJson();

//    //add codes specific to this class

//    return o;
//}
void Crook::addCar(QString availableCarsAddress)
{
    int ss = this->getShomareSanad();
    if(ss == 0)
    {
        qDebug() << "shomare sanad is needed for adding car";
        return;
    }
    else if( findCrook(ss).getShomareSanad() == ss )
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
                QJsonArray a = o["Crook"].toArray();
                a.append(t);
                o["Crook"] = a;
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
                o["Crook"] = a;
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
QJsonArray loadCrooks_jsonArray(QString availableCarsAddress)
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
            o["Crook"] = a;
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
            QJsonArray a = o["Crook"].toArray();
            return a;
        }
        else
        {
             qDebug() << "Couldn\'t open file: " + availableCarsAddress ;
        }
    }
    return QJsonArray();

}
Crook findCrook(int shomare_sanad, QString availableCarsAddress)
{
    Crook c;
    QJsonArray a = loadCrooks_jsonArray(availableCarsAddress);
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
