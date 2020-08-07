#ifndef CHEQUE_H
#define CHEQUE_H

#include "Document.h"

class Cheque : public Document
{
public:
    Cheque();
private:
    QString price;
    QDate expiration;
signals:
    void expired();
};

#endif // CHEQUE_H
