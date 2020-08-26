#ifndef MEMORANDUM_H
#define MEMORANDUM_H
#include <QMessageBox>

#include "Data.h"

#include "Human.h"
#include "Manager.h"
#include "Customer.h"
#include "Seller.h"

#include "Car.h"

#include "SUV.h"
#include "Crook.h"
#include "CityCar.h"
#include "Coupe.h"
#include "Vanet.h"
#include "CheckInfo.h"

void Memorandum(Car * car,Seller seller,Customer customer,QDateTime date,QVector<Checkinfo*> checks_vector);
QJsonArray loadMemorandums();
QJsonObject findMemorandum(QString shomare_sanad);

#endif // MEMORANDUM_H
