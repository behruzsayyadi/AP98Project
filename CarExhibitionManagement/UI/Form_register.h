#ifndef FORM_REGISTER_H
#define FORM_REGISTER_H

#include <QWidget>

namespace Ui {
class Form_register;
}

class Form_register : public QWidget
{
    Q_OBJECT

public:
    explicit Form_register(QWidget *parent = nullptr);
    ~Form_register();

private:
    Ui::Form_register *ui;
};

#endif // FORM_REGISTER_H
