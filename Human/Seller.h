#ifndef SELLER_H
#define SELLER_H
#include "Human.h"

class Seller : public Human
{
private:
    QString wealth;
    QString username;
    QString password;

public:
    Seller(QString name,QString family,QString birth_date,QString code_melli,QString phone_number,QString address/*,QString wealth,QString username,QString password*/);

};

#endif // SELLER_H
