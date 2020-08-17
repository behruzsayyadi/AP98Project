#ifndef DIALOG_ADDCAR_H
#define DIALOG_ADDCAR_H

#include <QDialog>

namespace Ui {
class Dialog_AddCar;
}

class Dialog_AddCar : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddCar(QWidget *parent = nullptr);
    ~Dialog_AddCar();

private:
    Ui::Dialog_AddCar *ui;
};

#endif // DIALOG_ADDCAR_H
