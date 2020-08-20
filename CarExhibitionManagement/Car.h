#ifndef CAR_H
#define CAR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QJsonValue>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "Data.h"

class Car
{
private:
    QString status;
    QString model;
    QString brand;
    QString year;
    QString color;
    QString inside_color;
    QString shomare_shasi;
    QString shomare_sanad;
    quint64 gheymat;

protected:
    double poorsant;
public:
    Car( QString status = "",
         QString model = "",
         QString brand = "",
         QString year = "",
         QString color = "",
         QString inside_color = "",
         QString shomare_shasi = "",
         QString shomare_sanad = "",
         quint64 gheymat = 0 );
    virtual ~Car();
    void setStatus(QString status);
    void setModel(QString model);
    void setColor(QString color);
    void setInsideColor(QString inside_color);
    void setShomareShasi(QString shomare_shasi);
    void setShomareSanad(QString shomare_sanad);
    void setBrand(QString brand);
    void setGheymat(quint64 gheymat);
    void setYear(QString year);

    QString getStatus() const;
    QString getModel() const;
    QString getColor() const;
    QString getInsideColor() const;
    QString getShomareShasi() const;
    QString getShomareSanad() const;
    QString getBrand() const;
    quint64 getGheymat() const;
    QString getYear() const;



    virtual quint64 getPoorsant();


    virtual void loadFromJson(QJsonObject object);
    virtual QJsonObject toJson();
    virtual void addCar();
};
QJsonArray loadAvailableCars_jsonArray();
//QJsonArray loadSoldCars_jsonArray(QString availableCarsAddress = "Documents/Cars_Sold.json");
//QJsonArray loadBoughtCars_jsonArray(QString availableCarsAddress = "Documents/Cars_Bought.json");
Car findCar(QString shomare_sanad);
#endif // CAR_H
