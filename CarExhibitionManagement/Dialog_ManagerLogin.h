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
    explicit Dialog_ManagerLogin(QWidget *parent = nullptr);
    ~Dialog_ManagerLogin();

private:
    Ui::Dialog_ManagerLogin *ui;
};

#endif // DIALOG_MANAGERLOGIN_H
