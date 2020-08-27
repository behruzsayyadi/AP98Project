#ifndef DIALOG_ADDCHECK_H
#define DIALOG_ADDCHECK_H

#include <QDialog>
#include <QRegExp>

#include "CheckInfo.h"

namespace Ui {
class Dialog_AddCheck;
}

class Dialog_AddCheck : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddCheck(QWidget *parent = nullptr);
    ~Dialog_AddCheck();
    Checkinfo * getCheck();
private:
    Ui::Dialog_AddCheck *ui;
    QStringList validate();
    Checkinfo * check;
private slots:
    void onAcceptClicked();
};

#endif // DIALOG_ADDCHECK_H
