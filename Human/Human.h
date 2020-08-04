#ifndef HUMAN_H
#define HUMAN_H

#include <QString>

class Human
{
private:
    QString name;
    QString family;
public:
    Human(QString name,QString family);
//    void setName(QString name);
    QString getName();

//    void setFamily(QString family);
    QString getFamily();

};

#endif // HUMAN_H
