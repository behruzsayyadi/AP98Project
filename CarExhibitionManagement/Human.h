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

    QString getFirstName() const { return first_name; }
    QString getLastName() const { return last_name; }
    QString getId() const { return id; }
    QString getAddress() const { return address; }
    QDate getDateOfBirth() const { return date_of_birth; }

    void setFirstName(const QString &value) { first_name = value; }
    void setLastName(const QString &value) { last_name = value; }
    void setPhoneNumber(const QString &value) { phone_number = value; }

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
