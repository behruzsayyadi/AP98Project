#ifndef DIALOG_ADDEVENT_H
#define DIALOG_ADDEVENT_H

#include <QDialog>

namespace Ui {
class Dialog_AddEvent;
}

class Dialog_AddEvent : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddEvent(QWidget *parent = nullptr);
    ~Dialog_AddEvent();
    QString getDescription();
    QString getTitle();
    QString getDay();
private:
    Ui::Dialog_AddEvent *ui;
    QString title, day, description;
public slots:
    void onAcceptClicked();
};

#endif // DIALOG_ADDEVENT_H
