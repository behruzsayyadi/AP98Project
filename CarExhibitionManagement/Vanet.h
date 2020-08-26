#ifndef VANET_H
#define VANET_H



#include "Data.h"

#include "Car.h"

class Vanet : public Car
{
private:
public:
    Vanet( QString status = "",
         QString model = "",
         QString brand = "",
         QString year = "",
         QString color = "",
         QString inside_color = "",
         QString shomare_shasi = "",
         QString shomare_sanad = "",
         quint64 gheymat = 0,
         double poorsant = 0.015);


    virtual quint64 getPoorsant() override;
    ~Vanet();
    QJsonObject toJson() override;
    void loadFromJson(QJsonObject) override;
    void addCar() override;
};
QJsonArray loadVanets_jsonArray();
Vanet findVanet(QString shomare_sanad);
#endif // VANET_H
