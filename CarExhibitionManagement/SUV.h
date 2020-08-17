#ifndef SUV_H
#define SUV_H

#include "Car.h"

class SUV : public Car
{
private:
public:
    SUV( QString status = "",
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
    ~SUV();
//    QJsonObject toJson() override;
//    void loadFromJson(QJsonObject) override;
    void addCar(QString availableCarsAddress ) override;
};
QJsonArray loadSUVs_jsonArray(QString availableCarsAddress = "Documents/SUV.json");
SUV findSUV(int shomare_sanad, QString availableCarsAddress = "Documents/SUV.json");
#endif // SUV_H
