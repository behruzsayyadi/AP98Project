#include "MainWindow.h"

#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QCalendar>

#include "Human.h"
#include "Manager.h"
#include "Customer.h"
#include "Seller.h"

#include "Car.h"
#include "SUV.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Car c, cc("pride"), ccc("mazsasdf", "sdafsadfsfa", "sadfsdaf");
    SUV s, ss, sss("safdsdfsdf");
    c.addCar();
    cc.addCar();
    s.addCar();
    sss.addCar();
    qDebug() << loadSUVs_jsonArray()
             << loadAvailableCars_jsonArray();
    MainWindow w;
    w.show();
    return a.exec();
}
