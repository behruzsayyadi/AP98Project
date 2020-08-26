#ifndef COUPE_H
#define COUPE_H

#include "Data.h"
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
         QString shomare_sanad = "",
         quint64 gheymat = 0);


    virtual quint64 getPoorsant() override;
    ~Coupe();
    QJsonObject toJson() override;
    void loadFromJson(QJsonObject) override;
    void addCar() override;
};
QJsonArray loadCoupes_jsonArray();
Coupe findCoupe(QString shomare_sanad);
#endif // COUPE_H
