#ifndef DIALOG_ADDINCOME_H
#define DIALOG_ADDINCOME_H

#include <QDialog>
#include <QDate>
#include <QLocale>
namespace Ui {
class Dialog_AddIncome;
}

class Dialog_AddIncome : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddIncome(QWidget *parent = nullptr);
    ~Dialog_AddIncome();
    int getSood();
    int getPoorsant();
    int getMonthIndex();
private:
    Ui::Dialog_AddIncome *ui;
    int month_index;
    int sood;
    int poorsant;
private slots:
    void onAcceptClicked();
};

#endif // DIALOG_ADDINCOME_H
