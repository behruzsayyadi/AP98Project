#ifndef COUSTUMER_H
#define COUSTUMER_H
#include "Human.h"

class Coustumer : public Human
{
private:
    QString wealth;
    QString username;
    QString password;
public:
    Coustumer(QString name,QString family,QString birth_date,QString code_melli,QString phone_number,QString address);
};

#endif // COUSTUMER_H
