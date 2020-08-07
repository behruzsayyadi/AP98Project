#ifndef SPORTCAR_H
#define SPORTCAR_H
#include "Car.h"

class SportCar : public Car
{
public:
    SportCar( QString brand,
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

#endif // SPORTCAR_H
