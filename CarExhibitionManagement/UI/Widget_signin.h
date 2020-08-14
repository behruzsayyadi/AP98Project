#ifndef WIDGET_SIGNIN_H
#define WIDGET_SIGNIN_H

#include <QWidget>
#include <QRegExp>

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

    QRegExp username_regExp;
    QRegExp password_regExp;

public slots:
    bool signin(QString username, QString password);
    int validateSigninInfo(QString username, QString password);

signals:
    void signinSuccessful();

};

#endif // WIDGET_SIGNIN_H
