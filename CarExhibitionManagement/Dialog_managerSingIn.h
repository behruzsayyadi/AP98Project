#ifndef DIALOG_MANAGERSINGIN_H
#define DIALOG_MANAGERSINGIN_H

#include <QDate>
#include <QDialog>

<<<<<<< HEAD
=======

>>>>>>> Development
namespace Ui {
class Dialog_managerSingIn;
}

class Dialog_managerSingIn : public QDialog
{
    Q_OBJECT

public:
    QString getName();
    QString getFamily();
    QString getID();
    QString getShShenas();
    QString getPhoneNum();
    QString getJob();
    QString getJobPhone();
    QString getUsername();
    QString getPassword();
    QDate getBirthDate();

<<<<<<< HEAD
    explicit Dialog_managerSingIn(QWidget *parent = nullptr);
=======
    explicit Dialog_managerSingIn(QString title /*= "ثبت نام"*/, QWidget *parent = nullptr);
>>>>>>> Development
    ~Dialog_managerSingIn();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog_managerSingIn *ui;
<<<<<<< HEAD
=======
    QStringList validate();

>>>>>>> Development
};

#endif // DIALOG_MANAGERSINGIN_H
