#ifndef PAGE_FINANCE_H
#define PAGE_FINANCE_H

#include <QWidget>


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
};

#endif // PAGE_FINANCE_H
