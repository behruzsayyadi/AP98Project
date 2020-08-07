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
    QString shomare_shenasname;
    QString phone_number;
    QString job;
    QString job_phone;
public:
    Human(QString name,QString family,QString birth_date,QString code_melli,QString shomare_shenasname,QString phone_number,QString job,QString job_phone);


    void setName(QString name);
    QString getName() const;


    void setFamily(QString family);
    QString getFamily() const;


    void setBirthDate(QString birth_date);
    QString getBirthDate() const;


    void setCodeMelli(QString code_melli);
    QString getCodeMelli() const;


    void setShShenasname(QString shomare_shenasname);
    QString getShShenasname() const;


    void setPhoneNum(QString phone_number);
    QString getPhoneNum() const;


    void setJob(QString job);
    QString getJob() const;


    void setJobPhone(QString job_phone);
    QString getJobPhone() const;

};

#endif // HUMAN_H
