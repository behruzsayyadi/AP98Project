#include "Dialog_Manager_Panel.h"
#include "ui_Dialog_Manager_Panel.h"

Dialog_Manager_Panel::Dialog_Manager_Panel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Manager_Panel)
{
    ui->setupUi(this);
}

Dialog_Manager_Panel::~Dialog_Manager_Panel()
{
    delete ui;
}
