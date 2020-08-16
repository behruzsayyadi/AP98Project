#ifndef COUPE_H
#define COUPE_H



#include "Car.h"

class Coupe : public Car
{
public:
    Coupe( QString status = "",
         QString model = "",
         QString brand = "",
         QString year = "",
         QString color = "",
         QString inside_color = "",
         QString shomare_shasi = "",
         int shomare_sanad = ++last_shomare_sanad,
         QString gheymat = "" );
    ~Coupe();
//    QJsonObject toJson() override;
//    void loadFromJson(QJsonObject) override;
    void addCar(QString availableCarsAddress = "Documents/Coupe.json") override;
};
QJsonArray loadCoupes_jsonArray(QString availableCarsAddress = "Documents/Coupe.json");
Coupe findCoupe(int shomare_sanad, QString availableCarsAddress = "Documents/Coupe.json");
#endif // COUPE_H
