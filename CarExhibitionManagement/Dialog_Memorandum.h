#ifndef DIALOG_MEMORANDUM_H
#define DIALOG_MEMORANDUM_H

#include <QDialog>
#include "CheckInfo.h"
#include "Dialog_Check.h"

namespace Ui {
class Dialog_Memorandum;
}

class Dialog_Memorandum : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Memorandum(QWidget *parent = nullptr);
    ~Dialog_Memorandum();

private slots:
    void on_radioButton_mngr_yes_clicked();

    void on_radioButton_mngr_no_clicked();

    void on_radioButton_check_yes_clicked();

    void on_radioButton_check_no_clicked();

    void on_buttonBox_accepted();

    void getNewChecks();
private:
    Ui::Dialog_Memorandum *ui;
    QVector<Checkinfo*> checks_vector;;
};

#endif // DIALOG_MEMORANDUM_H
