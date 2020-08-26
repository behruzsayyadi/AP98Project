#ifndef DIALOG_MANAGERLOGIN_H
#define DIALOG_MANAGERLOGIN_H

#include <QDialog>

<<<<<<< HEAD
=======
#include <QValidator>
#include <QIntValidator>
#include <QRegularExpressionValidator>

>>>>>>> Development
namespace Ui {
class Dialog_ManagerLogin;
}

class Dialog_ManagerLogin : public QDialog
{
    Q_OBJECT

public:
    QString getUsername();
    QString getPassword();

<<<<<<< HEAD
    explicit Dialog_ManagerLogin(QWidget *parent = nullptr);
=======
    explicit Dialog_ManagerLogin(QString title /*= "ورود"*/, QWidget *parent = nullptr);
>>>>>>> Development
    ~Dialog_ManagerLogin();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog_ManagerLogin *ui;
};

#endif // DIALOG_MANAGERLOGIN_H
