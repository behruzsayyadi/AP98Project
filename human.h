#ifndef HUMAN_H
#define HUMAN_H

#include <QObject>
#include <QString>
class Human : public QObject
{
    Q_OBJECT
public:
    explicit Human( QObject *parent = nullptr);
    Human (QString name, QString family);
    //    void setName(QString name);
        QString getName() const;
    //    void setFamily(QString family);
        QString getFamily() const;
protected:
private:
    QString name;
    QString family;

signals:

};

#endif // HUMAN_H
