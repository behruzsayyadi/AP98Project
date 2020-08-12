#ifndef TABWIDGET_LOGIN_REGISTER_H
#define TABWIDGET_LOGIN_REGISTER_H

#include <QTabWidget>

namespace Ui {
class TabWidget_login_register;
}

class TabWidget_login_register : public QTabWidget
{
    Q_OBJECT

public:
    explicit TabWidget_login_register(QWidget *parent = nullptr);
    ~TabWidget_login_register();

private:
    Ui::TabWidget_login_register *ui;
};

#endif // TABWIDGET_LOGIN_REGISTER_H
