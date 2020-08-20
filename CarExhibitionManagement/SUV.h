#ifndef SUV_H
#define SUV_H

#include "Car.h"
//namespace Data
//{
//    extern QString default_suv_path;
//    extern QString default_suv_array_name;

//    QJsonArray load_jsonArray(QString arrayName, QString filePath);
//    void save_jsonArray(QJsonArray array, QString arrayName, QString filePath);
//}
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
         quint64 gheymat = 0,
         double poorsant = 0.02);


    virtual quint64 getPoorsant() override;
    ~SUV();
//    QJsonObject toJson() override;
//    void loadFromJson(QJsonObject) override;
    void addCar() override;
};
QJsonArray loadSUVs_jsonArray();
SUV findSUV(QString shomare_sanad);
#endif // SUV_H
