#ifndef DIALOG_MEMORANDUM_H
#define DIALOG_MEMORANDUM_H

#include <QDialog>
#include "CheckInfo.h"
#include "Dialog_Check.h"
#include "Dialog_AddCheck.h"

#include "Car.h"
#include "SUV.h"
#include "CityCar.h"
#include "Coupe.h"
#include "Crook.h"
#include "Vanet.h"

#include "Manager.h"

namespace Ui {
class Dialog_Memorandum;
}

class Dialog_Memorandum : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Memorandum(QWidget *parent = nullptr);
    explicit Dialog_Memorandum(Car * car, Manager manager, QWidget *parent = nullptr);
    ~Dialog_Memorandum();

private slots:

    void on_buttonBox_accepted();

    void getNewCheck();
private:
    Ui::Dialog_Memorandum *ui;
    QVector<Checkinfo*> checks_vector;;
};

#endif // DIALOG_MEMORANDUM_H
