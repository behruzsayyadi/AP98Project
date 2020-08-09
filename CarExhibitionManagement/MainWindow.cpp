#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "RegisterDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    RegisterDialog registerDialog;
    registerDialog.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

