#ifndef HUMAN_H
#define HUMAN_H

#include <QObject>
#include <QDate>
#include <QString>
#include <QApplication>
#include <QJsonValue>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class Human : public QObject
{
private:
    QString name;
    QString family;

public:
    Human(QString name,
          QString family);
    Human()
        : name(""),family("")
    {}


    void setName(QString name);
    QString getName() const;


    void setFamily(QString family);
    QString getFamily() const;


};




#endif // HUMAN_H
