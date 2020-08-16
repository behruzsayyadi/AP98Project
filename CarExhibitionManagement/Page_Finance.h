#ifndef PAGE_FINANCE_H
#define PAGE_FINANCE_H

#include <QWidget>
#include <QTableWidget>

#include "CheckInfo.h"

namespace Ui {
class Page_Finance;
}

class Page_Finance : public QWidget
{
    Q_OBJECT

public:
    explicit Page_Finance(QWidget *parent = nullptr);
    ~Page_Finance();

private:
    Ui::Page_Finance *ui;
    void setupChecksTable();
};

#endif // PAGE_FINANCE_H
