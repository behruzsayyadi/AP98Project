#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>

class Data
{
public:
    static QDir dir_root, dir_documents, dir_memorandums;

    static QString default_car_path ;
    static QString default_suv_path ;
    static QString default_citycar_path ;
    static QString default_coupe_path ;
    static QString default_vanet_path ;
    static QString default_crook_path ;

    static QString default_all_memorandums_path ;
    static QString default_important_customers_path ;


    static QString default_car_array_name ;
    static QString default_suv_array_name ;
    static QString default_citycar_array_name ;
    static QString default_coupe_array_name ;
    static QString default_vanet_array_name ;
    static QString default_crook_array_name ;

    static QString default_all_memorandums_array_name ;
    static QString default_important_customers_array_name ;

    static QJsonArray load_jsonArray(QString arrayName, QString filePath);
    static void save_jsonArray(QJsonArray array, QString arrayName, QString filePath);
    static QJsonObject find(QString primary_key, QJsonValue value, QString arrayName, QString filePath);
    static void add(QJsonObject object, QString primary_key, QJsonValue unique_value, QString array_name, QString filePath);
    static void changeJsonArrayItem(QString key, QString newValue, QString keyToFind, QString valueToFind, QString array_name, QString filePath);
    static int findIndex(QString primary_key, QJsonValue value, QString arrayName, QString filePath);
//    static bool jsonObjectExists();
    static QJsonArray getIncomeInfo();
    static void changeIncomeInfo(int poorsant,int sood, int index);
    static void addIncome(int poorsant, int sood, int index);
};
#endif //DATA_H
