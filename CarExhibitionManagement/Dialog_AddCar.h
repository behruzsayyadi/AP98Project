#ifndef DIALOG_ADDCAR_H
#define DIALOG_ADDCAR_H

#include <QDialog>
#include "Car.h"
#include "SUV.h"
#include "Coupe.h"
#include "Crook.h"
#include "CityCar.h"
#include "Vanet.h"
namespace Ui {
class Dialog_AddCar;
}

class Dialog_AddCar : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddCar(QWidget *parent = nullptr);
    ~Dialog_AddCar();

    Car *getCar();
private:
    Ui::Dialog_AddCar *ui;

};

#endif // DIALOG_ADDCAR_H
