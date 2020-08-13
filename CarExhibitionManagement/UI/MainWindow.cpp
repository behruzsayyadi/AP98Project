#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Widget_signin.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTabWidget * temp = ui->tabWidget;
    temp->setTabText(0, "نمایشگاه");
    temp->setTabText(1, "ثبت نام");
    temp->setTabText(2, "ورود");
    temp->setTabText(3, "خانه");
    temp->setCurrentIndex(0);

    switch (signinState) {
    case notSignedup:;
    case signedup:;
    case signedin:;
    }
    Widget_signin a;
    a.show();


//  stackedLayout = new QStackedLayout(this);
//    ui->centralwidget->setLayout(stackedLayout);

//  stackedWidget = new QStackedWidget(this);
//  setCentralWidget(stackedWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

