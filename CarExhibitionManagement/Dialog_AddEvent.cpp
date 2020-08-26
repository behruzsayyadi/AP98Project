#include "Dialog_AddEvent.h"
#include "ui_Dialog_AddEvent.h"

Dialog_AddEvent::Dialog_AddEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddEvent)
{
    ui->setupUi(this);
}

Dialog_AddEvent::~Dialog_AddEvent()
{
    delete ui;
}
void Dialog_AddEvent::onAcceptClicked()
{
    title = ui->lineEdit_title->text();
    description = ui->lineEdit_description->text();
    day = ui->comboBox_day->currentText();
    accept();
}

QString Dialog_AddEvent::getDescription()
{
    return description;
}
QString Dialog_AddEvent::getTitle()
{
    return title;
}
QString Dialog_AddEvent::getDay()
{
    return day;
}
