#ifndef WIDGET_SIGNIN_H
#define WIDGET_SIGNIN_H

#include <QWidget>

namespace Ui {
class Widget_signin;
}

class Widget_signin : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_signin(QWidget *parent = nullptr);
    ~Widget_signin();

private:
    Ui::Widget_signin *ui;
public slots:
    void signin();
};

#endif // WIDGET_SIGNIN_H
