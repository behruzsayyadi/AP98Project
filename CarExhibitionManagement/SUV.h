#ifndef SUV_H
#define SUV_H
#include "Car.h"

class SUV : public Car
{
public:
    SUV( QString brand,
         QString model,
         bool is_new,
         QDate year,
         short max_speed,
         QString price,
         QString color,
         QString motor,
         NumberOfCylinders number_of_cylinders,
         QObject *parent );
};

#endif // SUV_H
