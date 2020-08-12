#ifndef FORM_LOGIN_H
#define FORM_LOGIN_H

#include <QWidget>

namespace Ui {
class Form_login;
}

class Form_login : public QWidget
{
    Q_OBJECT

public:
    explicit Form_login(QWidget *parent = nullptr);
    ~Form_login();

private:
    Ui::Form_login *ui;
};

#endif // FORM_LOGIN_H
