#include "MainWindow.h"

#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QCalendar>

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

    QCalendar cal { QCalendar::System::Jalali };
    QDate date{1399, 6, 17, cal};
    //qDebug() << date;

//    qDebug() << QDate::fromString("17/06/1399", Qt::LocalDate);
//    qDebug() << QDate::fromString("17/06/1399", "dd/MM/yyyy", cal);
//    qDebug() << QDate::fromString("17/06/1399", "dd/MM/yyyy", cal).toString(Qt::ISODate);

//    qDebug() << QDate::fromString("2020-09-07", Qt::ISODate);
//    qDebug() << QDate::fromString("2020-09-07", Qt::ISODate).toString(Qt::DefaultLocaleLongDate, cal);
//    qDebug() << QDate::fromString("2020-09-07", "yyyy-MM-dd").toString(Qt::DefaultLocaleLongDate);
//    qDebug() << QDate::fromString("2020-09-07").toString(Qt::DefaultLocaleLongDate);
//    qDebug() << QDate::fromString("2020-09-07", Qt::ISODate).toString(Qt::TextDate);
//    qDebug() << QDate::fromString("2020-09-07");
//    qDebug() << QDate::fromString("2020-09-07", Qt::TextDate);
//    qDebug() << QDate::fromString("2020-09-07", Qt::ISODate);
//    qDebug() << QDate::fromString("2020-09-07", Qt::SystemLocaleShortDate);
//    qDebug() << QDate::fromString("2020-09-07", Qt::SystemLocaleLongDate);
//    qDebug() << QDate::fromString("2020-09-07", Qt::DefaultLocaleShortDate);
//    qDebug() << QDate::fromString("2020-09-07", Qt::DefaultLocaleLongDate);
//    qDebug() << QDate::fromString("2020-09-07", Qt::RFC2822Date);
//    qDebug() << QDate::fromString("2020-09-07", Qt::ISODateWithMs);

//    qDebug() << QDate { 2020, 07, 9 }.toString();
//    qDebug() << QDate { 2020, 07, 9 }.toString(Qt::TextDate);
//    qDebug() << QDate { 2020, 07, 9 }.toString(Qt::ISODate);
//    qDebug() << QDate { 2020, 07, 9 }.toString(Qt::SystemLocaleShortDate);
//    qDebug() << QDate { 2020, 07, 9 }.toString(Qt::SystemLocaleLongDate);
//    qDebug() << QDate { 2020, 07, 9 }.toString(Qt::DefaultLocaleShortDate);
//    qDebug() << QDate { 2020, 07, 9 }.toString(Qt::DefaultLocaleLongDate);
//    qDebug() << QDate { 2020, 07, 9 }.toString(Qt::RFC2822Date);
//    qDebug() << QDate { 2020, 07, 9 }.toString(Qt::ISODateWithMs);

//    qDebug() << QDate{ 1399, 4, 5, cal };
//    qDebug() << QDate{ 1399, 4, 5, cal }.toString();
//    qDebug() << QDate{ 1399, 4, 5, cal }.toString(Qt::DefaultLocaleShortDate);
//    qDebug() << QDate{ 2002, 4, 15 }.toString(Qt::DefaultLocaleShortDate);
//    qDebug() << QDate::fromString("2020-06-03", "yyyy-MM-dd").toString(Qt::DefaultLocaleShortDate);
    qDebug() << QDate::fromString("2020-06-03", "yyyy-MM-dd").toString(Qt::DefaultLocaleShortDate, cal);
//    qDebug() << QDate::fromString("05/04/1399", "dd/MM/yyyy", cal).toString();

//    qDebug() << cal.dateFromParts(1399, 4, 5);
    qDebug() << cal.partsFromDate(QDate{2020, 3, 5}).year;
    QLocale l;
    qDebug() << l.toString(date, "MMMM, dddd, yyyy");

//    qDebug() << cal.partsFromDate({2020, 3, 5}).year;


    MainWindow w;
    w.show();
    return a.exec();
}
