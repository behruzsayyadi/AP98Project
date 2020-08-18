#ifndef DIALOG_CHECK_H
#define DIALOG_CHECK_H

#include <QDialog>
#include <QVector>
#include <QList>


#include "CheckInfo.h"
namespace Ui {
class Dialog_Check;
}

class Dialog_Check : public QDialog
{
    Q_OBJECT

public:
    QVector<Checkinfo*> getChecks();
    explicit Dialog_Check(QWidget *parent = nullptr);
    ~Dialog_Check();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::Dialog_Check *ui;
    QVector <Checkinfo*> checks;
};

#endif // DIALOG_CHECK_H
