#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QStackedWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDateEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow * ui;

    QStackedWidget * stackedWidget;
    QWidget * widget_login;
    QWidget * widget_register;
    QFormLayout * formLayout_login;
    QFormLayout * formLayout_register;
    QLabel * label_login_username;
    QLabel * label_login_password;
    QLabel * label_register_firstName;
    QLabel * label_register_lastName;
    QLabel * label_register_id;
    QLabel * label_register_phoneNumber;
    QLabel * label_register_address;
    QLabel * label_register_dateOfBirth;
    QLabel * label_register_username;
    QLabel * label_register_password;
    QLineEdit * lineEdit_login_username;
    QLineEdit * lineEdit_login_password;
    QLineEdit * lineEdit_register_username;
    QLineEdit * lineEdit_register_password;
    QLineEdit * lineEdit_register_firstName;
    QLineEdit * lineEdit_register_lastName;
    QLineEdit * lineEdit_register_address;
    QLineEdit * lineEdit_register_phoneNumber;
    QLineEdit * lineEdit_register_id;
    QDateEdit * dateEdit_register_dateOfBirth;

    //test:
private slots:
    void change(){
        stackedWidget->setCurrentIndex(1);
    }
};
#endif // MAINWINDOW_H
