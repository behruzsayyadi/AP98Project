#ifndef HUMAN_H
#define HUMAN_H

#include <QObject>
#include <QString>
#include <QDate>

class Human : public QObject
{
    Q_OBJECT
public:
    Human( QString first_name,
           QString last_name,
           QString id,
           QString address,
           QDate date_of_birth,
           QString phone_number,
           QObject *parent = nullptr );

    QString getFirstName() const;
    QString getLastName() const;
    QString getId() const;
    QString getAddress() const;
    QDate getDateOfBirth() const;
    void setFirstName();
    void setLastName();
    void setAddress(QString);
private:
    QString first_name;
    QString last_name;
    const QString id;
    QString address;
    const QDate date_of_birth;
    QString phone_number;
signals:

};

#endif // HUMAN_H
