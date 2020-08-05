
#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QString>
#include <QDate>


class Car : public QObject
{
    Q_OBJECT
public:
    enum NumberOfCylinders {
        two = 2,
        four = 4,
    };
    Car ();
protected:
private:
    const NumberOfCylinders numberOfCylinders;
    const bool unused;
    const QString brand;
    const QString model;
    const QDate year;
    const short maxSpeed;
    QString price;
    QString color;
    QString motor;
};


#endif // CAR_H
