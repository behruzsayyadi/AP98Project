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
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(mySlot()));
    timer->start(1000);
    manager = new Manager();








}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mySlot()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    if((time.second()%2) == 0)
    {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    ui->label_myClock->setText(time_text);
}

void MainWindow::on_pushButton_SignLog_in_clicked()
{
    int result;
    QFile mngr_open("Documents/Managers.json");
    if(mngr_open.open(QIODevice::ReadOnly) == true)
    {
        mngr_open.close();
        Dialog_ManagerLogin *mngr_dlg = new Dialog_ManagerLogin(this);
        mngr_dlg->setWindowTitle("ورود مدیر");

        result = mngr_dlg->exec();
        if(result == Dialog_ManagerLogin::Accepted)
        {
            this->manager->setName(loadManager().getUsername());
            this->manager->setFamily(loadManager().getFamily());
            this->manager->setID(loadManager().getID());
            this->manager->setJob(loadManager().getJob());
            this->manager->setJobPhone(loadManager().getJobPhone());
            this->manager->setBirthDate(loadManager().getBirthDate());
            this->manager->setShShenasname(loadManager().getShShenasname());
            this->manager->setPhoneNum(loadManager().getPhoneNum());
            this->manager->setUsername(loadManager().getUsername());
            this->manager->setPassword(loadManager().getPassword());
            QMessageBox msg_box_logIn_succesfully(this);
            msg_box_logIn_succesfully.information(this,"Logged In","Logged in succesfully");
            msg_box_logIn_succesfully.show();
        }
        else
        {
            QMessageBox msg_box_logIn_faild(this);

            msg_box_logIn_faild.warning(this,"WARNING","Log in Unsuccesfull");
            msg_box_logIn_faild.show();
        }

    }
    else
    {
        mngr_open.close();
        Dialog_managerSingIn * mngr_sign_dlg = new Dialog_managerSingIn(this);
        mngr_sign_dlg->setWindowTitle("ثبت نام مدیر");
        result = mngr_sign_dlg->exec();
        if(result == Dialog_managerSingIn::Accepted)
        {
            this->manager->setName(loadManager().getUsername());
            this->manager->setFamily(loadManager().getFamily());
            this->manager->setID(loadManager().getID());
            this->manager->setJob(loadManager().getJob());
            this->manager->setJobPhone(loadManager().getJobPhone());
            this->manager->setBirthDate(loadManager().getBirthDate());
            this->manager->setShShenasname(loadManager().getShShenasname());
            this->manager->setPhoneNum(loadManager().getPhoneNum());
            this->manager->setUsername(loadManager().getUsername());
            this->manager->setPassword(loadManager().getPassword());
        }
        else
        {

        }
    }
}
