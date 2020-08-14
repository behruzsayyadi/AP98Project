#include "MainWindow.h"

#include <QApplication>

#include "Seller.h"
#include "Customer.h"
#include "Manager.h"
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
    Customer me4 = findCustomer("2210387974");

    Manager me5 = loadManager();
//    me5.setUsername("behruz");
//    me5.setPassword("sayyadi");

    qDebug() << loadManager().getUsername();
    MainWindow w;
    w.show();
    return af.exec();
}
