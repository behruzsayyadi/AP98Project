#include "Memorandum.h"
void Memorandum(Car * car,Seller seller,Customer customer,QDateTime date,QVector<Checkinfo*> checks_vector)
{

    QString path = "Documents/Memorandums/" + car->getShomareSanad() + ".json";
    qDebug() << "created file : " + path;


    QJsonObject memorandum_object;
    QJsonObject seller_object;
    QJsonObject customer_object;
    QJsonObject car_object;
    QJsonArray checks_array;

    QFile memorandum_file(path);
    QFile all_memorandums_file("Documents/Memorandums.json");

    seller_object["name"] = seller.getName();
    seller_object["family"] = seller.getFamily();
    seller_object["id"] = seller.getID();
    seller_object["shomare shenasname"] = seller.getShShenasname();
    seller_object["birth date"] = seller.getBirthDate().toString();
    seller_object["phone number"] = seller.getPhoneNum();
    seller_object["job"] = seller.getJob();
    seller_object["job phone"] = seller.getJobPhone();

    customer_object["name"] = customer.getName();
    customer_object["family"] = customer.getFamily();
    customer_object["id"] = customer.getID();
    customer_object["shomare shenasname"] = customer.getShShenasname();
    customer_object["birth date"] = customer.getBirthDate().toString();
    customer_object["phone number"] = customer.getPhoneNum();
    customer_object["job"] = customer.getJob();
    customer_object["job phone"] = customer.getJobPhone();

    car_object["model"] = car->getModel();
    car_object["brand"] = car->getBrand();
    car_object["year"] = car->getYear();
    car_object["color"] = car->getColor();
    car_object["inside color"] = car->getInsideColor();
    car_object["gheymat"] = QString::number(car->getGheymat());
    car_object["shomare shasi"] = car->getShomareShasi();
    car_object["shomare sanad"] = car->getShomareSanad();

    QJsonObject temp_check_object;
    for(Checkinfo * check : checks_vector)
    {
        temp_check_object["money"] = check->getMoney();
        temp_check_object["bank"] = check->getBank();
        temp_check_object["shobe bank"] = check->getShobeBank();
        temp_check_object["shenase"] = check->getShenase();
        temp_check_object["date"] = check->getDate().toString();
        checks_array.append(temp_check_object);
        check->addCheck();
        delete check;
    }

    memorandum_object["seller"] = seller_object;
    memorandum_object["customer"] = customer_object;
    memorandum_object["car"] = car_object;
    memorandum_object["date and time"] = date.toString();
    memorandum_object["checks"] = checks_array;
    if(memorandum_file.exists())
    {
        qDebug() << "memorandum with this number already exists";
    }
    else if( memorandum_file.open(QIODevice::WriteOnly) )
    {
        memorandum_file.write(QJsonDocument(memorandum_object).toJson());
        memorandum_file.close();
    }


    QJsonObject m;
    m["seller name"] = seller.getName() + ' ' + seller.getFamily();
    m["customer name"] = customer.getName() + ' ' + customer.getFamily();
    m["date and time"] = date.toString();
    m["car"] = car->getModel() + ' ' + car->getBrand() + ' ' + car->getYear() ;
    m["poorsant"] = QString::number(car->getPoorsant());
    m["shomare sanad"] = car->getShomareSanad();

    Data::add(m, "shomare sanad", m["shomare sanad"], Data::default_all_memorandums_array_name, Data::default_all_memorandums_path);
    return;
}

QJsonArray loadMemorandums()
{
    return Data::load_jsonArray(Data::default_all_memorandums_array_name, Data::default_all_memorandums_path);
}
QJsonObject findMemorandum(QString shomare_sanad)
{
    QJsonObject result;
    if( Data::find("shomare sanad", shomare_sanad, Data::default_all_memorandums_array_name,Data::default_all_memorandums_path).isEmpty() )
    {
        qDebug() << "memorandum doesn't exist";
    }
    else
    {
        QFile file(Data::dir_memorandums.path() + '/' + shomare_sanad + ".json");
        if (file.open(QIODevice::ReadOnly))
        {
            result = QJsonDocument::fromJson(file.readAll()).object();
        }
        else
        {
           qDebug() << "could not open file : " + file.fileName();
        }
    }
    return result;
}
