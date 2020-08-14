#ifndef DIALOG_MANAGERSINGIN_H
#define DIALOG_MANAGERSINGIN_H

#include <QDialog>

namespace Ui {
class Dialog_managerSingIn;
}

class Dialog_managerSingIn : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_managerSingIn(QWidget *parent = nullptr);
    ~Dialog_managerSingIn();

private:
    Ui::Dialog_managerSingIn *ui;
};

#endif // DIALOG_MANAGERSINGIN_H
