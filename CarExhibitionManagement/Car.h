#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QDate>
#include <QString>

class Car : public QObject
{
    Q_OBJECT

public:
    enum NumberOfCylinders {
        two = 2,
        four = 4,
    };
    Car( QString brand,
         QString model,
         bool is_new,
         QDate year,
         short max_speed,
         QString price,
         QString color,
         QString motor,
         NumberOfCylinders number_of_cylinders,
         QObject *parent = nullptr );
    /**
     * getters
     * all getters return the same type as the field they get ecxept for getNumberOfCylinders wich returns a QString specifying numver of Cylinders
    */
    QString getBrand() const { return brand; }
    QString getModel() const { return model; };
    bool isNew() const { return is_new; }
    QDate getYear() const { return year; }
    short getMaxSpeed() const { return max_speed; }
    QString getPrice() const {return price; }
    QString getColor() const { return color; }
    QString getMotor() const { return motor; }
    NumberOfCylinders getNumberOfCylinders() const { return number_of_cylinders; }
    QString getNumberOfCylindersInQString() const;
    /**
     * setters
     * setters for non-const fields
    */

    void setColor( QString color ) { this->color = color; }
    void setPrice( QString price) { this->price = price; }
    void setMotor( QString motor ) { this->motor= motor; }

protected:

private:
    const QString brand;
    const QString model;
    const bool is_new;
    const QDate year;
    const short max_speed;
    QString price;
    QString color;
    QString motor;
    const NumberOfCylinders number_of_cylinders;
signals:

};

#endif // CAR_H
