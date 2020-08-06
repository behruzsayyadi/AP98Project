#ifndef CITYCAR_H
#define CITYCAR_H

#include "Car.h"

class CityCar : public Car
{
public:
    CityCar( QString brand,
             QString model,
             bool is_new,
             QDate year,
             short max_speed,
             QString price,
             QString color,
             QString motor,
             NumberOfCylinders number_of_cylinders,
             QObject *parent = nullptr );
};

#endif // CITYCAR_H
