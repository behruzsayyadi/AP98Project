#include "Human.h"


Human::Human(QString name,
             QString family) :
    name(name),
    family(family)
{
//    this->name = name;
//    this->family = family;
}

void Human::setName(QString name)
{
    this->name = name;
}

QString Human::getName() const
{
    return this->name;
}

void Human::setFamily(QString family)
{
    this->family = family;
}

QString Human::getFamily() const
{
    return this->family;
}






