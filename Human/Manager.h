#ifndef MANAGER_H
#define MANAGER_H


#include "Human.h"


class Manager : public Human
{
private:
    QString username;
    QString password;
    QString second_password;

public:
    Manager();
public slots:

};

#endif // MANAGER_H
