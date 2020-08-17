#include "MainWindow.h"

#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QCalendar>
#include <QDir>

#include "Human.h"
#include "Manager.h"
#include "Customer.h"
#include "Seller.h"

#include "Car.h"

#include "SUV.h"
#include "Crook.h"
#include "CityCar.h"
#include "Coupe.h"
#include "Vanet.h"


namespace Data
{
    QString default_car_path;
    QString default_suv_path;

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

//    template <typename T>
//    T find(QString value,QString arrayName, QString filePath)
//    {
//        T result;
//        QJsonArray array = load_jsonArray(arrayName, filePath);
//        if(array.isEmpty())
//        {
//            qDebug() << "No objects found in file:" + filePath;
//        }
//        else
//        {
//            QJsonObject object;
//            foreach(QJsonValue v, array)
//            {
//                object = v.toObject();
//                if(object[ "id" ].toString() == value)
//                {
//                    result.loadFromJson( object );
//                }
//            }
//        }
//        return result;
//    }

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    system("IF NOT exist Documents mkdir Documents");
    if( !QDir("Documents").exists() )
        QDir().mkdir("Documents");
    SUV s ("موجود","سوناتا","هیوندای","2000","مشکی","خاکستری","61325613");
    s.setGheymat("500000000");

    s.addCar();
    MainWindow w;
    w.show();
    return a.exec();
}
