#ifndef WIDGET_SIGNUP_H
#define WIDGET_SIGNUP_H

#include <QWidget>

namespace Ui {
class Widget_signup;
}

class Widget_signup : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_signup(QWidget *parent = nullptr);
    ~Widget_signup();

private:
    Ui::Widget_signup *ui;
};

#endif // WIDGET_SIGNUP_H