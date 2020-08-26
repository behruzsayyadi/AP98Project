#ifndef SUV_H
#define SUV_H

#include "Data.h"
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
         QString shomare_sanad = "",
         quint64 gheymat = 0);


    virtual quint64 getPoorsant() override;
    ~SUV();
    QJsonObject toJson() override;
    void loadFromJson(QJsonObject) override;
    void addCar() override;
};
QJsonArray loadSUVs_jsonArray();
SUV findSUV(QString shomare_sanad);
#endif // SUV_H
