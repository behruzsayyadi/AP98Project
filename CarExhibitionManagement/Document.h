#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>
#include <QDateTime>

class Document : public QObject
{
    Q_OBJECT
public:
    explicit Document(QObject *parent = nullptr);
protected:
private:
    QDateTime date;
signals:

};

#endif // DOCUMENT_H
