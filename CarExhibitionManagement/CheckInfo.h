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
    QDate date;
    QString shenase;
public:
    Checkinfo(QString money,QDate date,QString shenase);
    Checkinfo();
    Checkinfo(Checkinfo &a);
    Checkinfo(Checkinfo &&a);


    void setMoney(QString money);
    QString getMoney();

    void setDate(QDate date);
    QDate getDate();

    void setShenase(QString shenase);
    QString getShenase();

    void addCheck(QString checksFileAddress = "Documents/Checks.json");
};

QJsonArray loadChecks_jsonArray(QString checksFileAddress = "Documents/Checks.json");

Checkinfo findCheck(QString shenase,QString checksFileAddress = "Documents/Checks.json");


#endif // CHECKINFO_H
