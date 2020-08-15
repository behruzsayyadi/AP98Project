#include "MainWindow.h"

#include <QApplication>
#include <QDir>

#include "Seller.h"
#include "Customer.h"
#include "Manager.h"
#include "CheckInfo.h"

int main(int argc, char *argv[])
{
    QApplication af(argc, argv);

    if( !QDir("Documents").exists() )
        QDir().mkdir("Documents");

    MainWindow w;
    w.show();
    return af.exec();
}
