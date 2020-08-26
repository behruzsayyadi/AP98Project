#ifndef CROOK_H
#define CROOK_H

#include "Data.h"
#include "Car.h"
class Crook : public Car
{
private:
public:
    Crook( QString status = "",
         QString model = "",
         QString brand = "",
         QString year = "",
         QString color = "",
         QString inside_color = "",
         QString shomare_shasi = "",
         QString shomare_sanad = "",
         quint64 gheymat = 0);


    virtual quint64 getPoorsant() override;
    ~Crook();
    QJsonObject toJson() override;
    void loadFromJson(QJsonObject) override;
    void addCar() override;
};
QJsonArray loadCrooks_jsonArray();
Crook findCrook(QString shomare_sanad);
#endif // CROOK_H
