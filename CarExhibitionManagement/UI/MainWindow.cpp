#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QTabBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTabBar * b = new QTabBar(this);
    b->addTab("signup");
    b->addTab("signup");
    b->addTab("signup");
    b->addTab("signup");
    b->addTab("signup");
    b->setShape(QTabBar::TriangularNorth);
//  stackedLayout = new QStackedLayout(this);
//    ui->centralwidget->setLayout(stackedLayout);

//  stackedWidget = new QStackedWidget(this);
//  setCentralWidget(stackedWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

