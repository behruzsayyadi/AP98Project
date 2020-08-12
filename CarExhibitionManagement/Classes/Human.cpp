#include "Human.h"

Human::Human( QString first_name,
              QString last_name,
              QString id,
              QString address,
              QDate date_of_birth,
              QString phone_number,
              QObject *parent ):
    QObject{ parent },
    first_name{ first_name },
    last_name{ last_name},
    id{ id },
    address{ address },
    date_of_birth{ date_of_birth },
    phone_number{ phone_number }
{}








