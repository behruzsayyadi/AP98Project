#include "Car.h"

Car::Car( QString brand,
          QString model,
          bool is_new,
          QDate year,
          short max_speed,
          QString price,
          QString color,
          QString motor,
          NumberOfCylinders number_of_cylinders,
          QObject *parent ) :
    QObject{ parent },
    brand{ brand },
    model{ model },
    is_new{ is_new },
    year{ year },
    max_speed{ max_speed },
    price{ price},
    color{ color },
    motor{ motor},
    number_of_cylinders{ number_of_cylinders}
{}

QString Car::getNumberOfCylindersInQString() const
{
    switch (number_of_cylinders)
    {
        case 2: return "two";
        case 4: return "four";
        default: return "";
    }
}
