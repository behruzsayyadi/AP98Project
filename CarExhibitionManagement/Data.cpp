#include "Data.h"



        QDir Data::dir_root, Data::dir_documents("Documents"), Data::dir_memorandums("Documents/Memorandums/"), Data::dir_vitrine("Documents/Vitrine/");

        QString Data::default_car_path = "Documents/Car.json";
        QString Data::default_suv_path = "Documents/SUV.json";
        QString Data::default_citycar_path =  "Documents/CityCar.json";
        QString Data::default_coupe_path =  "Documents/Coupe.json";
        QString Data::default_vanet_path =  "Documents/Vanet.json";
        QString Data::default_crook_path =  "Documents/Crook.json";

        QString Data::default_all_memorandums_path = "Documents/Memorandums.json" ;
        QString Data::default_important_customers_path = "Documents/important customers.json";

        QString Data::default_car_array_name = "cars";
        QString Data::default_suv_array_name = "suvs";
        QString Data::default_citycar_array_name = "city car";
        QString Data::default_coupe_array_name = "coupe";
        QString Data::default_vanet_array_name = "vanet";
        QString Data::default_crook_array_name = "crook";

        QString Data::default_all_memorandums_array_name = "memorandums";
        QString Data::default_important_customers_array_name = "important customers";

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
                file.close();
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
    void Data::changeJsonArrayItem(QString key, QString newValue, QString keyToFind, QString valueToFind, QString array_name, QString filePath)
    {
        int i = findIndex(keyToFind, valueToFind, array_name, filePath);
        QJsonArray arr = load_jsonArray(array_name, filePath);
        QJsonObject o = arr.takeAt(i).toObject();
        o[key] = newValue;
        arr.insert(i, o);
        save_jsonArray(arr, array_name, filePath);

    }


    int Data::findIndex(QString primary_key, QJsonValue value, QString arrayName, QString filePath)
    {
        QJsonArray array = load_jsonArray(arrayName, filePath);
        if(array.isEmpty())
        {
            qDebug() << "No objects found in file:" + filePath;
        }
        else
        {
            int result = 0;
            QJsonObject object;
            foreach(QJsonValue v, array)
            {
                object = v.toObject();
                if(object[ primary_key ] == value)
                {
                       return result;
                }
                result ++;
            }
        }
        return -1;
    }
//    bool Data::jsonObjectExists(){}
    void Data::changeIncomeInfo(quint64 poorsant,quint64 sood, int index)
    {
        if(index < 0 || index > 11) return;
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
        o["poorsant"] = QString::number(poorsant);
        o["sood"] = QString::number(sood);
        income[index] = o;
        save_jsonArray(income, "income", "Documents/Income.json");
    }
    QJsonArray Data::getIncomeInfo()
    {
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
            save_jsonArray(income, "income", "Documents/Income.json");
        }

        return income;
    }
    void Data::addIncome(quint64 poorsant, quint64 sood, int index)
    {
        if(index < 0 || index > 11) return;
        QJsonObject obj = Data::getIncomeInfo()[index].toObject();
        Data::changeIncomeInfo(
                    obj["poorsant"].toString().toULongLong() + poorsant,
                obj["sood"].toString().toULongLong() + sood,
                index );

    }
    bool Data::areAllIncomesEmpty()
    {
        bool result = true;
        for( auto x : getIncomeInfo())
        {
            QJsonObject o = x.toObject();
            if(o["poorsant"].toString().toULongLong() != 0 )
            {
                result = false;
            }
            if(o["sood"].toString().toULongLong() != 0 )
            {
                result = false;
            }
        }

        return result;
    }

