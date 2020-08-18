#ifndef PAGE_CARS_H
#define PAGE_CARS_H

#include <QWidget>

#include "Dialog_AddCar.h"
#include "Dialog_Memorandum.h"

#include "Car.h"
#include "SUV.h"
#include "Coupe.h"
#include "Crook.h"
#include "CityCar.h"
#include "Vanet.h"

namespace Ui {
class Page_Cars;
}

class Page_Cars : public QWidget
{
    Q_OBJECT

public:
    explicit Page_Cars(QWidget *parent = nullptr);
    ~Page_Cars();

private:
    Ui::Page_Cars *ui;
    void populateCarsTable();
    void addNewRow( Car*, QString type);
public slots:
    void addNewCar();
    void addNewMemorandum();

};

#endif // PAGE_CARS_H
