#ifndef COUPE_H
#define COUPE_H

#include "Car.h"

class Coupe : public Car
{
private:
public:
    Coupe( QString status = "",
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
    ~Coupe();
//    QJsonObject toJson() override;
//    void loadFromJson(QJsonObject) override;
    void addCar(QString availableCarsAddress) override;
};
QJsonArray loadCoupes_jsonArray(QString availableCarsAddress = "Documents/Coupe.json");
Coupe findCoupe(int shomare_sanad, QString availableCarsAddress = "Documents/Coupe.json");
#endif // COUPE_H
