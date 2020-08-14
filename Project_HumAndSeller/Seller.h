#ifndef SELLER_H
#define SELLER_H
#include "Human.h"

class Seller : public Human
{
private:
    QDate birth_date;
    QString ID;
    QString shomare_shenasname;
    QString phone_number;
    QString job;
    QString job_phone;

public:
    Seller(QString name,
           QString family,
           QDate birth_date,
           QString ID,
           QString shomare_shenasname,
           QString phone_number,
           QString job,
           QString job_phone);
    Seller()
        : birth_date(QDate(0,0,0))
        ,ID("")
        ,shomare_shenasname("")
        ,job("")
        ,job_phone("")
    {}


    Seller (Seller& a);
    Seller (Seller&& a);

    void setBirthDate(QDate birth_date);
    QDate getBirthDate() const;


    void setID(QString ID);
    QString getID() const;


    void setShShenasname(QString shomare_shenasname);
    QString getShShenasname() const;


    void setPhoneNum(QString phone_number);
    QString getPhoneNum() const;


    void setJob(QString job);
    QString getJob() const;


    void setJobPhone(QString job_phone);
    QString getJobPhone() const;

    void addSeller(QString sellersFileAddress = "Documents/Sellers.json");



};
Seller findSeller(QString ID,QString sellersFileAddress = "Documents/Sellers.json");
#endif // SELLER_H
