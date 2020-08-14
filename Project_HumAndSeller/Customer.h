#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QObject>

#include "Human.h"

class Customer : public Human
{

private:
    QDate birth_date;
    QString ID;
    QString shomare_shenasname;
    QString phone_number;
    QString job;
    QString job_phone;

public:
    Customer(QString name,
           QString family,
           QDate birth_date,
           QString ID,
           QString shomare_shenasname,
           QString phone_number,
           QString job,
           QString job_phone);
    Customer()
        : birth_date(QDate(0,0,0))
        ,ID("")
        ,shomare_shenasname("")
        ,job("")
        ,job_phone("")
    {}

    Customer (Customer& a);
    Customer (Customer&& a);

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

    void addCustomer(QString CustomersFileAddress = "Documents/Customers.json");



};

Customer findCustomer(QString ID,QString customersFileAddress = "Documents/customers.json");

#endif // CUSTOMER_H
