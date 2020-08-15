#include "MainWindow.h"

#include <QApplication>

#include "Seller.h"
#include "Customer.h"
#include "Manager.h"
#include "CheckInfo.h"

int main(int argc, char *argv[])
{
    QApplication af(argc, argv);




    system("mkdir Documents");
    /*
    Customer me("mamad","sayyadi",QDate(2001,6,19),"2210387973","2210387973","09115726028","daneshjoo","03133912222");
    me.addCustomer();

    Customer me3("behruz","sayyadi",QDate(2001,6,19),"2210387974","2210387973","09115726028","daneshjoo","03133912222");
    me3.addCustomer();

    Customer me2("behruz","sayyadi",QDate(2001,6,19),"2210387973","2210387973","09115726028","daneshjoo","03133912222");
    me2.addCustomer();
    */
//    Customer me4 = findCustomer("2210387974");

//    Manager me5 ;
//    me5.setUsername("behruz");
//    me5.setPassword("sayyadi");
 //   me5.addManager();
/*
    Checkinfo mycheck1("50000000",QDate(2020,7,12),"23145354143453");
    mycheck1.addCheck();
    Checkinfo mycheck2("30000000",QDate(2020,7,12),"23145354143453");
    mycheck2.addCheck();
    Checkinfo mycheck3("80000000",QDate(2020,7,12),"23145354143464");
    mycheck3.addCheck();

*/
 //  qDebug() << loadChecks_jsonArray();

   qDebug() << findCheck("23145354143464").getMoney();
    MainWindow w;
    w.show();
    return af.exec();
}
