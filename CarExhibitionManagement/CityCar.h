#ifndef CITYCAR_H
#define CITYCAR_H

#include "Car.h"

class CityCar : public Car
{
private:
public:
    CityCar( QString status = "",
         QString model = "",
         QString brand = "",
         QString year = "",
         QString color = "",
         QString inside_color = "",
         QString shomare_shasi = "",
         int shomare_sanad = ++last_shomare_sanad,
         quint64 gheymat = 0,
         double poorsant = 0);


    virtual quint64 getPoorsant() override;
    ~CityCar();
//    QJsonObject toJson() override;
//    void loadFromJson(QJsonObject) override;
    void addCar(QString availableCarsAddress ) override;
};
QJsonArray loadCityCars_jsonArray(QString availableCarsAddress = "Documents/CityCar.json");
CityCar findCityCar(int shomare_sanad, QString availableCarsAddress = "Documents/CityCar.json");
#endif // CITYCAR_H
