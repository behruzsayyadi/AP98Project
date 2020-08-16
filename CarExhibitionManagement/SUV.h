#ifndef SUV_H
#define SUV_H

#include "Car.h"

class SUV : public Car
{
public:
    SUV( QString status = "",
         QString model = "",
         QString brand = "",
         QString year = "",
         QString color = "",
         QString inside_color = "",
         QString shomare_shasi = "",
         int shomare_sanad = ++last_shomare_sanad,
         QString gheymat = "" );
    ~SUV();
//    QJsonObject toJson() override;
//    void loadFromJson(QJsonObject) override;
    void addCar(QString availableCarsAddress = "Documents/SUV.json") override;
};
QJsonArray loadSUVs_jsonArray(QString availableCarsAddress = "Documents/SUV.json");
SUV findSUV(int shomare_sanad, QString availableCarsAddress = "Documents/SUV.json");
#endif // SUV_H
