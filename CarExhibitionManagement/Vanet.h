#ifndef VANET_H
#define VANET_H



#include "Car.h"

class Vanet : public Car
{
public:
    Vanet( QString status = "",
         QString model = "",
         QString brand = "",
         QString year = "",
         QString color = "",
         QString inside_color = "",
         QString shomare_shasi = "",
         int shomare_sanad = ++last_shomare_sanad,
         QString gheymat = "" );
    ~Vanet();
//    QJsonObject toJson() override;
//    void loadFromJson(QJsonObject) override;
    void addCar(QString availableCarsAddress = "Documents/Vanet.json") override;
};
QJsonArray loadVanets_jsonArray(QString availableCarsAddress = "Documents/Vanet.json");
Vanet findVanet(int shomare_sanad, QString availableCarsAddress = "Documents/Vanet.json");
#endif // VANET_H
