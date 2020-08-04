#ifndef SELLER_H
#define SELLER_H
#include "Human.h"

class Seller : public Human
{
private:
    QString birth_date;
    QString code_melli;
    QString phone_number;
    QString address;

public:
    Seller(QString name,QString familly,QString birth_date,QString code_melli,QString phone_number,QString address);




};

#endif // SELLER_H
