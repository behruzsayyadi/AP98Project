#include "MainWindow.h"

#include <QApplication>

#include "Exhibition.h"
#include "Human.h"
#include "Manager.h"
#include "Customer.h"
#include "Seller.h"
#include "Car.h"
#include "SportCar.h"
#include "CityCar.h"
#include "SUV.h"
#include "Document.h"
#include "Memorandum.h"
#include "Cheque.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Human("ali"," ","dsfa","adf",*new QDate,"sdaf");
    MainWindow w;
    w.show();
    return a.exec();
}
