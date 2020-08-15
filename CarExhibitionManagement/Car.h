#ifndef CAR_H
#define CAR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QJsonValue>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>


class Car
{
protected:
    QString name;
    QString rang;
    QString range_dakhel;
    QString shasi;
    QString sanad;
    QString brand;
    QString gheymat;
    QString sale_tolid;
    double poorsant;
public:
    Car();
    void setname(QString name);
    void setrang(QString rang);
    void setInrang(QString rang_dakhel);
    void setshasi(QString shasi);
    void setsanad(QString sanad);
    void setbrand(QString brand);
    void setgheymat(QString gheymat);
    void setsal(QString sal);
    void setpoorsant(double poorsant);//?

    QString getname();
    QString getrang();
    QString getInrang();
    QString getshasi();
    QString getsanad();
    QString getbrand();
    QString getgheymat();
    QString getsal();
    double getpoorsant();

    void addCar(QString availableCarsAddress = "Documents/Cars_Available.json");
};
QJsonArray loadAvailableCars_jsonArray(QString availableCarsAddress = "Documents/Cars_Available.json");
QJsonArray loadSoldCars_jsonArray(QString availableCarsAddress = "Documents/Cars_Sold.json");
QJsonArray loadBoughtCars_jsonArray(QString availableCarsAddress = "Documents/Cars_Bought.json");
Car findCar(QString sanad, QString availableCarsAddress = "Documents/Cars_Available.json");
#endif // CAR_H
