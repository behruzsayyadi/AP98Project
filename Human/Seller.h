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
    Seller(QString name,QString family,QString birth_date,QString code_melli,QString shomare_shenasname,QString phone_number,QString job,QString job_phone/*,QString wealth,QString username,QString password*/);

};

#endif // SELLER_H
