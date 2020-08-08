#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<QString>
#include <QDate>

#include "Human.h"

class Customer : public Human
{
public:
    Customer( QString first_name,
              QString last_name,
              QString id,
              QString address,
              QDate date_of_birth,
              QString phone_number,
              QString wealth,
              QString username,
              QString password,
              QObject *parent = nullptr );
    QString getUsername() const { return username; }
    void setUsername(const QString &value) { username = value; }
protected:
private:
    QString wealth;
    QString username;
    QString password;
};

#endif // CUSTOMER_H
