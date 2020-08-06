#include "MainWindow.h"

#include <QApplication>
#include "Human.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Human("ali"," ","dsfa","adf",*new QDate,"sdaf");
    MainWindow w;
    w.show();
    return a.exec();
}
