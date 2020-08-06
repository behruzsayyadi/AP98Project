#include "Human.h"

Human::Human(QString name,QString family)
{
    this->name = name;
    this->family = family;
}

/*void Human::setName(QString name)
{
    this->name = name;
}*/

QString Human::getName()
{
    return this->name;
}

/*void Human::setFamily(QString family)
{
    this->family = family;
}*/

QString Human::getFamily()
{
    return this->family;
}
