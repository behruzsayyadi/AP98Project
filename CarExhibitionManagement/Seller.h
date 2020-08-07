#ifndef SELLER_H
#define SELLER_H

#include <QString>
#include <QDate>

#include "Human.h"

class Seller : public Human
{
public:
    Seller( QString first_name,
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

#endif // SELLER_H
