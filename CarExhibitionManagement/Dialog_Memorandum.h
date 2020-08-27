#ifndef DIALOG_MEMORANDUM_H
#define DIALOG_MEMORANDUM_H

#include <QDateTime>

#include <QDialog>
#include "CheckInfo.h"
#include "Dialog_AddCheck.h"

#include "Car.h"
#include "SUV.h"
#include "CityCar.h"
#include "Coupe.h"
#include "Crook.h"
#include "Vanet.h"

#include "Manager.h"

#include "Memorandum.h"
#include "Seller.h"
#include "Customer.h"

namespace Ui {
class Dialog_Memorandum;
}

class Dialog_Memorandum : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Memorandum(QWidget *parent = nullptr);
    explicit Dialog_Memorandum(Car * car, Manager manager, QWidget *parent = nullptr);
    explicit Dialog_Memorandum(QJsonObject memorandum, QWidget * parent);
    ~Dialog_Memorandum();

private slots:

    void on_buttonBox_accepted();

    void getNewCheck();

    void addNewCheck(Checkinfo);
private:
    Ui::Dialog_Memorandum *ui;
    QVector<Checkinfo*> checks_vector;;
signals:
    void memorandumCreated(QString seller_name, QString buyer_name, QString car_info, QString poorsant, QDateTime time, QString shomare_sanad);
    void newIncome(QString poorsant, QString sood, int month_index);
private slots:
    void showIncome();
    void setMaxCkeckMoney();
};

#endif // DIALOG_MEMORANDUM_H
