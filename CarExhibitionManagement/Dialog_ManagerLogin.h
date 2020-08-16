#ifndef DIALOG_MANAGERLOGIN_H
#define DIALOG_MANAGERLOGIN_H

#include <QDialog>

namespace Ui {
class Dialog_ManagerLogin;
}

class Dialog_ManagerLogin : public QDialog
{
    Q_OBJECT

public:
    QString getUsername();
    QString getPassword();

    explicit Dialog_ManagerLogin(QString title = "ورود", QWidget *parent = nullptr);
    ~Dialog_ManagerLogin();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog_ManagerLogin *ui;
};

#endif // DIALOG_MANAGERLOGIN_H
