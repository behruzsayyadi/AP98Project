#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication af(argc, argv);
    MainWindow w;
    w.show();
    return af.exec();
}
