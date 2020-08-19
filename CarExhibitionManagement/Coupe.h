#ifndef COUPE_H
#define COUPE_H

#include "Car.h"

namespace Data
{
    extern QString default_coupe_path;
    extern QString default_coupe_array_name;
    QJsonArray load_jsonArray(QString arrayName, QString filePath);
    void save_jsonArray(QJsonArray array, QString arrayName, QString filePath);
}

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
         quint64 gheymat = 0,
         double poorsant = 0.005);


    virtual quint64 getPoorsant() override;
    ~Coupe();
//    QJsonObject toJson() override;
//    void loadFromJson(QJsonObject) override;
    void addCar() override;
};
QJsonArray loadCoupes_jsonArray();
Coupe findCoupe(QString shomare_sanad);
#endif // COUPE_H
