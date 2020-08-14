#ifndef DIALOG_MANAGER_PANEL_H
#define DIALOG_MANAGER_PANEL_H

#include <QDialog>

namespace Ui {
class Dialog_Manager_Panel;
}

class Dialog_Manager_Panel : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Manager_Panel(QWidget *parent = nullptr);
    ~Dialog_Manager_Panel();

private:
    Ui::Dialog_Manager_Panel *ui;
};

#endif // DIALOG_MANAGER_PANEL_H
