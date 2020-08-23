#include "Data.h"



        QDir Data::dir_root, Data::dir_documents("Documents"), Data::dir_memorandums("Documents/Memorandums");

        QString Data::default_car_path = "Documents/Car.json";
        QString Data::default_suv_path = "Documents/SUV.json";
        QString Data::default_citycar_path =  "Documents/CityCar.json";
        QString Data::default_coupe_path =  "Documents/Coupe.json";
        QString Data::default_vanet_path =  "Documents/Vanet.json";
        QString Data::default_crook_path =  "Documents/Crook.json";

        QString Data::default_car_array_name = "cars";
        QString Data::default_suv_array_name = "suvs";
        QString Data::default_citycar_array_name = "city car";
        QString Data::default_coupe_array_name = "coupe";
        QString Data::default_vanet_array_name = "vanet";
        QString Data::default_crook_array_name = "crook";


    QJsonArray Data::load_jsonArray(QString arrayName, QString filePath)
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
                file.close();
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
    void Data::save_jsonArray(QJsonArray array, QString arrayName, QString filePath)
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

    QJsonObject Data::find(QString primary_key, QJsonValue value, QString arrayName, QString filePath)
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


        }
        return QJsonObject();
    }
    void Data::add(QJsonObject object, QString primary_key, QJsonValue unique_value, QString array_name, QString filePath)
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
//    bool Data::jsonObjectExists(){}
    void Data::changeIncomeInfo(int poorsant,int sood, int index)
    {
        if(index < 1 || index > 12) return;
        QJsonArray income =  load_jsonArray("income", "Documents/Income.json");
        if(income.empty())
        {
            for(int i = 0; i <12; i++)
            {
                QJsonObject O;
                O["poorsant"] = 0;
                O["sood"] = 0;
                income.append(O);
            }
        }
        QJsonObject o;
        o["poorsant"] = poorsant;
        o["sood"] = sood;
        income[index - 1] = o;
        save_jsonArray(income, "income", "Documents/Income.json");
    }
    QJsonArray Data::getIncomeInfo()
    {
        return load_jsonArray("income", "Documents/Income.json");
    }
    void Data::addIncome(int poorsant, int sood, int index)
    {
        if(index < 1 || index > 12) return;
        QJsonObject obj = Data::getIncomeInfo()[index - 1].toObject();
        Data::changeIncomeInfo(
                    obj["poorsant"].toInt() + poorsant,
                obj["sood"].toInt() + sood,
                index );

    }

