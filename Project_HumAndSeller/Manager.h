#ifndef MANAGER_H
#define MANAGER_H


#include "Human.h"

class Manager : public Human
{
private:
    QDate birth_date;
    QString ID;
    QString shomare_shenasname;
    QString phone_number;
    QString job;
    QString job_phone;
    QString username;
    QString password;
public:
    Manager(QString name,
           QString family,
           QDate birth_date,
           QString ID,
           QString shomare_shenasname,
           QString phone_number,
           QString job,
           QString job_phone);
    Manager()
        : birth_date(QDate(0,0,0))
        ,ID("")
        ,shomare_shenasname("")
        ,job("")
        ,job_phone("")
    {}


    Manager (Manager& a);
    Manager (Manager&& a);

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


    void setUsername(QString username);
    QString getUsername();


    void setPassword(QString password);
    QString getPassword();

    void addManager(QString managersFileAddress = "Documents/Managers.json");

};


bool managerLogin(QString username,QString password,QString managersFileAddress = "Documents/Managers.json");
Manager loadManager(QString managersFileAddress = "Documents/Managers.json");

#endif // MANAGER_H
