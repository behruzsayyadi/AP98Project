#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Dialog_ManagerLogin.h"
#include "Dialog_managerSingIn.h"

#include <QFile>
#include <QDebug>
#include <QObject>
#include <QTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , backPageIndex(0)

{
    ui->setupUi(this);
    ui->centralwidget->layout()->setMargin(0);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->pushButton_backPage, SIGNAL(clicked()), this, SLOT(onBackButtonClicked()));
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(displayCurrentDateTime()));
    timer->start(1000);
    manager = new Manager();
    if(QFile("Documents/Managers.json").exists()) ui->pushButton_SignLog_in->setText("Login");
    else ui->pushButton_SignLog_in->setText("Signin");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setBackPageIndex(int value)
{
    backPageIndex = value;
}
void MainWindow::displayCurrentDateTime()
{
//    QTime time = QTime::currentTime();
//    QString time_text = time.toString("hh : mm : ss");
//    if((time.second()%2) == 0)
//    {
//        time_text[3] = ' ';
//        time_text[8] = ' ';
//    }
    ui->label_CurrentDateTime->setText(QDateTime::currentDateTime().toString("h:m:s yy:m:d"));

}
void MainWindow::onBackButtonClicked()
{
    ui->stackedWidget->setCurrentIndex(backPageIndex);
}
void MainWindow::navigateToCarsPage()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::navigateToFinancePage()
{
        ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_pushButton_SignLog_in_clicked()
{
//    int result;
    QFile mngr_open("Documents/Managers.json");

    if(mngr_open.open(QIODevice::ReadOnly) == true)
    {
        mngr_open.close();
        Dialog_ManagerLogin *mngr_dlg = new Dialog_ManagerLogin(this);
        mngr_dlg->setWindowTitle("ورود مدیر");

//        result = mngr_dlg->exec();
        if(mngr_dlg->exec() == Dialog_ManagerLogin::Accepted)
        {
//            Manager temp = loadManager();
//            this->manager->setName(temp.getUsername());
//            this->manager->setFamily(temp.getFamily());
//            this->manager->setID(temp.getID());
//            this->manager->setJob(temp.getJob());
//            this->manager->setJobPhone(temp.getJobPhone());
//            this->manager->setBirthDate(temp.getBirthDate());
//            this->manager->setShShenasname(temp.getShShenasname());
//            this->manager->setPhoneNum(temp.getPhoneNum());
//            this->manager->setUsername(temp.getUsername());
//            this->manager->setPassword(temp.getPassword());
            *(this->manager) = loadManager();
            this->statusBar()->showMessage("Logged in succesfully", 3500);
            ui->stackedWidget->setCurrentIndex(1);
            this->setBackPageIndex(1);

//            QMessageBox msg_box_logIn_succesfully(this);
//            msg_box_logIn_succesfully.information(this,"Logged In","Logged in succesfully");
//            msg_box_logIn_succesfully.show();
        }
        else
        {
//            QMessageBox msg_box_logIn_faild(this);
//            msg_box_logIn_faild.warning(this,"WARNING","Log in Unsuccesfull");
//            msg_box_logIn_faild.show();
            QMessageBox::warning(this, "login failed","could not log in. \n please try again.");
        }

    }
    else
    {
        mngr_open.close();
        Dialog_managerSingIn * mngr_sign_dlg = new Dialog_managerSingIn( "ثبت نام مدیر", this);
//        mngr_sign_dlg->setWindowTitle("ثبت نام مدیر");
//        result = mngr_sign_dlg->exec();
        if(mngr_sign_dlg->exec() == Dialog_managerSingIn::Accepted)
        {
//            Manager temp = loadManager();
//            this->manager->setName(temp.getUsername());
//            this->manager->setFamily(temp.getFamily());
//            this->manager->setID(temp.getID());
//            this->manager->setJob(temp.getJob());
//            this->manager->setJobPhone(temp.getJobPhone());
//            this->manager->setBirthDate(temp.getBirthDate());
//            this->manager->setShShenasname(temp.getShShenasname());
//            this->manager->setPhoneNum(temp.getPhoneNum());
//            this->manager->setUsername(temp.getUsername());
//            this->manager->setPassword(temp.getPassword());
            *(this->manager) = loadManager();
            this->statusBar()->showMessage("signed up successfuly", 3500);
        }
        else
        {

        }
    }
}
