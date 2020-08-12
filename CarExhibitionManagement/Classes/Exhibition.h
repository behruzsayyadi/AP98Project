#ifndef EXHIBITION_H
#define EXHIBITION_H

#include <QObject>
#include <QString>
#include <QVector>

#include "Car.h"

class Exhibition : public QObject
{
    Q_OBJECT
public:
    explicit Exhibition(QObject *parent = nullptr);
private:
    QString wealth;
    QVector <Car> available_cars;
signals:

};

#endif // EXHIBITION_H
