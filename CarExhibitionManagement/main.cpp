#include "MainWindow.h"
#include "LogInDialog.h"

#include <QApplication>
#include <QObject>
#include <QDebug>

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
    MainWindow m;
    m.show();


    return a.exec();
}
