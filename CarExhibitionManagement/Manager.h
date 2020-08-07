#ifndef MANAGER_H
#define MANAGER_H

#include <QString>
#include <QVector>
#include <QDate>

#include "Human.h"
#include "Exhibition.h"
#include "Cheque.h"

class Manager : public Human
{
public:
    Manager( QString first_name,
             QString last_name,
             QString id,
             QString address,
             QDate date_of_birth,
             QString phone_number,
             QString username,
             QString password,
             QObject *parent = nullptr );
    QString getUsername() const { return username; }
    void setUsername(const QString &value) { username = value; }
protected:
private:
    QString username;
    QString password;
    QVector<Cheque> cheques;
    QVector<Human> important_people;
    QVector<Exhibition> exhibitions;
public slots:
    void chequeExpired( Cheque cheque );

};

#endif // MANAGER_H
