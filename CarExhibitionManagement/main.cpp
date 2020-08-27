#include "MainWindow.h"

#include <QApplication>
#include "Data.h"


#include "Human.h"
#include "Manager.h"
#include "Customer.h"
#include "Seller.h"
#include <QStyleFactory>

#include "Car.h"
#include "CityCar.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    a.setPalette(darkPalette);

    a.setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");

    if( !Data::dir_documents.exists() )
        Data::dir_root.mkdir("Documents");
    if( !Data::dir_memorandums.exists() )
        Data::dir_documents.mkdir("Memorandums");
    if( !Data::dir_vitrine.exists() )
        Data::dir_documents.mkdir("Vitrine");
    MainWindow w;
    w.show();
    return a.exec();
}
