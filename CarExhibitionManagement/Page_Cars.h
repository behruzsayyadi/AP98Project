#ifndef PAGE_CARS_H
#define PAGE_CARS_H

#include <QWidget>

#include <QTableWidgetItem>

#include "Dialog_AddCar.h"
#include "Dialog_Memorandum.h"

#include "Car.h"
#include "SUV.h"
#include "Coupe.h"
#include "Crook.h"
#include "CityCar.h"
#include "Vanet.h"

#include "Memorandum.h"


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
    void populateMemorandumsTable();
    void addNewRow(Car*, QString type);
    Car * selected_car;
    int selected_car_row;
    QString selected_car_type;
    QString selected_car_shomare_sanad;
public slots:
    void addNewCar();
    void addNewMemorandum();
    void addNewMemorandumRow(QString seller_name, QString buyer_name, QString car_info, QString poorsant, QDateTime time, QString shomare_sanad);
    void showMemorandum(QTableWidgetItem *);
    void sellCar();
    void onCarSelected(QTableWidgetItem *);
signals:
    void newCarAdded(Car);
    void newCheckAdded(Checkinfo);
    void newIncome(QString poorsant, QString sood, int month_index);
};

#endif // PAGE_CARS_H
