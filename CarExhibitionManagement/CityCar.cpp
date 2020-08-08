#include "CityCar.h"

CityCar::CityCar( QString brand,
                  QString model,
                  bool is_new,
                  QDate year,
                  short max_speed,
                  QString price,
                  QString color,
                  QString motor,
                  NumberOfCylinders number_of_cylinders,
                  QObject *parent ) :
        Car { brand,
              model,
              is_new,
              year,
              max_speed,
              price,
              color,
              motor,
              number_of_cylinders,
              parent }
{}
