#ifndef HUMAN_H
#define HUMAN_H

#include <QObject>
#include <QString>


class Human : public QObject
{
private:
    QString name;
    QString family;
    QString birth_date;
    QString code_melli;
    QString phone_number;
    QString address;
public:
    Human(QString name,QString family,QString birth_date,QString code_melli,QString phone_number,QString address);


    void setName(QString name);
    QString getName();


    void setFamily(QString family);
    QString getFamily();


    void setBirthDate(QString birth_date);
    QString getBirthDate();


    void setCodeMelli(QString code_melli);
    QString getCodeMelli();


    void setPhoneNum(QString phone_number);
    QString getPhoneNum();


    void setAddress(QString address);
    QString getAddress();


};

#endif // HUMAN_H
