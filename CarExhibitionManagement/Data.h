#ifndef DATA_H
#define DATA_H
#include <QString>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>

namespace Data
{
    QDir dir_root, dir_documents("Documents"), dir_memorandums("Documents/Memorandums");

    QString default_car_path = "Documents/Car.json";
    QString default_suv_path = "Documents/SUV.json";
    QString default_citycar_path =  "Documents/CityCar.json";
    QString default_coupe_path =  "Documents/Coupe.json";
    QString default_vanet_path =  "Documents/Vanet.json";
    QString default_crook_path =  "Documents/Crook.json";

    QString default_car_array_name = "cars";
    QString default_suv_array_name = "suvs";
    QString default_citycar_array_name = "city car";
    QString default_coupe_array_name = "coupe";
    QString default_vanet_array_name = "vanet";
    QString default_crook_array_name = "crook";

    QJsonArray load_jsonArray(QString arrayName, QString filePath)
    {
        QJsonArray result;
        QJsonObject object;
        QFile file(filePath);
        if(!file.exists())
        {
            qDebug() << "File doesn\'t exist: " + file.fileName()
                     << "Creating file...";
            if( file.open(QIODevice::WriteOnly))
            {
                object[ arrayName ] = result;
                file.write(QJsonDocument( object ).toJson());
                qDebug() << "File created successfuly.";
            }
            else
            {
                qDebug() << "Problem making or writing to file: " + file.fileName();
            }
        }
        else
        {
            if(file.open(QIODevice::ReadOnly))
            {
                object = QJsonDocument::fromJson(file.readAll()).object();
                file.close();
                result = object[ arrayName ].toArray();
            }
            else
            {
                 qDebug() << "Couldn\'t open file: " + file.fileName();
            }
        }
        return result;
    }
    void save_jsonArray(QJsonArray array, QString arrayName, QString filePath)
    {
        QJsonObject object;
        object[arrayName] = array;
        QFile file(filePath);
        if(file.exists())
        {
            if( file.open(QIODevice::WriteOnly))
            {
                file.write(QJsonDocument( object ).toJson());
            }
            else
            {
                qDebug() << "Problem making or writing to file: " + file.fileName();
            }
        }
    }

    QJsonObject find(QString primary_key, QJsonValue value, QString arrayName, QString filePath)
    {
        QJsonArray array = load_jsonArray(arrayName, filePath);
        if(array.isEmpty())
        {
            qDebug() << "No objects found in file:" + filePath;
        }
        else
        {
            QJsonObject object;
            foreach(QJsonValue v, array)
            {
                object = v.toObject();
                if(object[ primary_key ] == value)
                {
                    return object;
                }
            }
            1234

        }
        return QJsonObject();
    }
    void add(QJsonObject object, QString primary_key, QJsonValue unique_value, QString array_name, QString filePath)
    {
        if( !find(primary_key, unique_value, array_name, filePath).isEmpty() )
        {//if we can find an object with the value for key as same as this object:
            return;
        }
        else
        {
            QJsonArray a = load_jsonArray(array_name, filePath);
            a.append(object);
            save_jsonArray(a,array_name,filePath);
        }
    }
//    void changeJsonArrayItem(QString key, QString newValue, QString keyToFind, QString valueToFind, QString array_name, QString filePath)
//    {
//        find(key, value, array_name, filePath);
//    }
    bool jsonObjectExists();
    QJsonArray getIncomeInfo();
    void changeIncomeInfo(int poorsant,int sood, int index);
}
#endif //DATA_H
