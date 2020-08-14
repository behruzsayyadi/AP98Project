#ifndef PAGE_CARS_H
#define PAGE_CARS_H

#include <QWidget>

namespace Ui {
class Page_Cars;
}

class Page_Cars : public QWidget
{
    Q_OBJECT

public:
    explicit Page_Cars(QWidget *parent = nullptr);
    ~Page_Cars();

private:
    Ui::Page_Cars *ui;
};

#endif // PAGE_CARS_H
