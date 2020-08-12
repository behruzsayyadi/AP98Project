#ifndef MEMORANDUM_H
#define MEMORANDUM_H

#include "Car.h"
#include "Document.h"

class Memorandum : public Document
{
public:
    Memorandum( const Car& car );
private:
    QString price;
    const Car& car;
};

#endif // MEMORANDUM_H
