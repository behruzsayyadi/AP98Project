#ifndef CITYCAR_H
#define CITYCAR_H

#include "Data.h"
#include "Car.h"

#include "Data.h"
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
         QString shomare_sanad = "",
         quint64 gheymat = 0
         );


    virtual quint64 getPoorsant() override;
    ~CityCar();
    QJsonObject toJson() override;
    void loadFromJson(QJsonObject) override;
    void addCar() override;
};
QJsonArray loadCityCars_jsonArray();
CityCar findCityCar(QString shomare_sanad);
#endif // CITYCAR_H
