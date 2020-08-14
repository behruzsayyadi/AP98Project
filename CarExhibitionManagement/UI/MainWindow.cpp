#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Widget_signin.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , backPageIndex{ 0 }
{
    ui->setupUi(this);
    ui->centralwidget->layout()->setContentsMargins(0,0,0,0);
    ui->centralwidget->layout()->setMargin(0);

    connect(ui->pushButton_back, &QPushButton::clicked,
            [this]{ui->stackedWidget->setCurrentIndex(backPageIndex);});

    if(managerExisgts())
    {
        connect(ui->pushButton_signin, &QPushButton::clicked,
                [ this ]{ ui->stackedWidget->setCurrentIndex(2); });
    }
    else
    {
        ui->pushButton_signin->setText("ثبت نام");
        connect(ui->pushButton_signin, &QPushButton::clicked,
                [ this ]{ ui->stackedWidget->setCurrentIndex(1); });

    }
    //connect signupSuccessful to signinSuccessgul to a lambda that
    //switches to home page

    connect(ui->page_signup, &Widget_signup::signupSuccessful,
            ui->page_signin, &Widget_signin::signinSuccessful);

    connect(ui->page_signin, &Widget_signin::signinSuccessful,
            [ this ]{
                        ui->stackedWidget->setCurrentIndex(3);
                        setBackPageIndex(3);
                    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::managerExisgts()
{
    return true;
}

