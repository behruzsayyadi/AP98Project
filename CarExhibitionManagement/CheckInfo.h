#ifndef CHECKINFO_H
#define CHECKINFO_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QDate>
#include <QJsonValue>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
class Checkinfo
{
private:
    QString money;
<<<<<<< HEAD
    QDate date;
    QString shenase;
public:
    Checkinfo(QString money,QDate date,QString shenase);
    Checkinfo();
=======
    QString bank;
    QString shobe_bank;
    QDate date;
    QString shenase;
public:
    Checkinfo(QString money = "",QString bank = "",QString shobe_bank = "",QDate date = QDate(),QString shenase = "");
//    Checkinfo();
>>>>>>> Development
    Checkinfo(Checkinfo &a);
    Checkinfo(Checkinfo &&a);


    void setMoney(QString money);
    QString getMoney();

<<<<<<< HEAD
=======
    void setBank(QString bank);
    QString getBank();

    void setShobeBank(QString shobe_bank);
    QString getShobeBank();

>>>>>>> Development
    void setDate(QDate date);
    QDate getDate();

    void setShenase(QString shenase);
    QString getShenase();

    void addCheck(QString checksFileAddress = "Documents/Checks.json");
};

QJsonArray loadChecks_jsonArray(QString checksFileAddress = "Documents/Checks.json");

Checkinfo findCheck(QString shenase,QString checksFileAddress = "Documents/Checks.json");

<<<<<<< HEAD
=======
QJsonArray checks_jsonArray_sort_by_date(QJsonArray a);

QDate dateFromJsonObject(QJsonObject a);
>>>>>>> Development

#endif // CHECKINFO_H
