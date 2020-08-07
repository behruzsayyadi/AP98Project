#include "Seller.h"

Seller::Seller( QString first_name,
                QString last_name,
                QString id,
                QString address,
                QDate date_of_birth,
                QString phone_number,
                QString wealth,
                QString username,
                QString password,
                QObject *parent ):
    Human{ first_name,
           last_name,
           id,
           address,
           date_of_birth,
           phone_number,
           parent },
    wealth{ wealth },
    username{ username },
    password( password )
{}




