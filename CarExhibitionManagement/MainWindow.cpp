#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stackedWidget = new QStackedWidget(this);

    tabWidget_login_and_register = new QTabWidget(stackedWidget);

    widget_login = new QWidget(stackedWidget);
    widget_register = new QWidget(stackedWidget);

    formLayout_login = new QFormLayout(widget_login);
    formLayout_register = new QFormLayout(widget_register);

    label_login_username = new QLabel(tr("نام کاربری"), widget_login);
    label_login_password = new QLabel(tr("رمز عبور"), widget_login);
    label_register_firstName = new QLabel(tr("نام"), widget_register);
    label_register_lastName = new QLabel(tr("نام خانوادگی"), widget_register);
    label_register_id = new QLabel(tr("کد ملی") , widget_register);
    label_register_phoneNumber = new QLabel(tr("شماره موبایل"), widget_register);
    label_register_address = new QLabel(tr("آدرس"), widget_register);
    label_register_dateOfBirth = new QLabel(tr("تاریخ تولد"), widget_register);
    label_register_username = new QLabel(tr("نام کاربری"), widget_register);
    label_register_password = new QLabel(tr("رمز عبور"), widget_register);
    lineEdit_login_username = new QLineEdit(widget_login);
    lineEdit_login_password = new QLineEdit(widget_login);
    lineEdit_register_username = new QLineEdit(widget_register);
    lineEdit_register_password = new QLineEdit(widget_register);
    lineEdit_register_firstName = new QLineEdit(widget_register);
    lineEdit_register_lastName = new QLineEdit(widget_register);
    lineEdit_register_address = new QLineEdit(widget_register);
    lineEdit_register_phoneNumber = new QLineEdit(widget_register);
    lineEdit_register_id = new QLineEdit(widget_register);
    dateEdit_register_dateOfBirth = new QDateEdit(widget_register);

//    label_login_username->setBuddy(lineEdit_login_username);
//    label_login_password->setBuddy(lineEdit_login_password);
//    label_register_username->setBuddy(lineEdit_register_username);
//    label_register_password->setBuddy(lineEdit_register_password);
//    label_register_id->setBuddy(lineEdit_register_id);
//    label_register_address->setBuddy(lineEdit_register_address);
//    label_register_firstName->setBuddy(lineEdit_register_firstName);
//    label_register_lastName->setBuddy(lineEdit_register_lastName);
//    label_register_phoneNumber->setBuddy(lineEdit_register_phoneNumber);
//    label_register_dateOfBirth->setBuddy(dateEdit_register_dateOfBirth);

    formLayout_login->addRow(label_login_username, lineEdit_login_username);
    formLayout_login->addRow(label_login_password, lineEdit_login_password);

    formLayout_register->addRow(label_register_firstName, lineEdit_register_firstName);
    formLayout_register->addRow(label_register_lastName, lineEdit_register_lastName);
    formLayout_register->addRow(label_register_id, lineEdit_register_id);
    formLayout_register->addRow(label_register_address, lineEdit_register_address);
    formLayout_register->addRow(label_register_phoneNumber, lineEdit_register_phoneNumber);
    formLayout_register->addRow(label_register_username, lineEdit_register_username);
    formLayout_register->addRow(label_register_password, lineEdit_register_password);
    formLayout_register->addRow(label_register_dateOfBirth, dateEdit_register_dateOfBirth);

    widget_login->setLayout(formLayout_login);
    widget_register->setLayout(formLayout_register);

    tabWidget_login_and_register->addTab(widget_login, tr("ورود"));
    tabWidget_login_and_register->addTab(widget_register, tr("ثبت نام"));

    stackedWidget->addWidget(tabWidget_login_and_register);

    setCentralWidget(stackedWidget);








}

MainWindow::~MainWindow()
{
    delete ui;
}

