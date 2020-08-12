#include "Manager.h"

Manager::Manager( QString first_name,
                QString last_name,
                QString id,
                QString address,
                QDate date_of_birth,
                QString phone_number,
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
    username{ username },
    password( password )
{}
