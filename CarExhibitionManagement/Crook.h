#ifndef CROOK_H
#define CROOK_H

#include "Car.h"

class Crook : public Car
{
public:
    Crook( QString status = "",
         QString model = "",
         QString brand = "",
         QString year = "",
         QString color = "",
         QString inside_color = "",
         QString shomare_shasi = "",
         int shomare_sanad = ++last_shomare_sanad,
         QString gheymat = "" );
    ~Crook();
//    QJsonObject toJson() override;
//    void loadFromJson(QJsonObject) override;
    void addCar(QString availableCarsAddress = "Documents/Crook.json") override;
};
QJsonArray loadCrooks_jsonArray(QString availableCarsAddress = "Documents/Crook.json");
Crook findCrook(int shomare_sanad, QString availableCarsAddress = "Documents/Crook.json");
#endif // CROOK_H
