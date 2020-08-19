#include "Dialog_AddCar.h"
#include "ui_Dialog_AddCar.h"

Dialog_AddCar::Dialog_AddCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddCar)
{
    ui->setupUi(this);
}

Dialog_AddCar::~Dialog_AddCar()
{
    delete ui;
}

Car * Dialog_AddCar::getCar()
{
    QString type = ui->comboBox_CarType->currentText();
    Car * result = nullptr;
    if(type == "شاسی بلند")
    {
        result = new SUV( "موجود",
                          ui->lineEdit_Model->text(),
                          ui->lineEdit_Brand->text(),
                          ui->lineEdit_Year->text(),
                          ui->lineEdit_Color->text(),
                          ui->lineEdit_InsideColor->text(),
                          ui->lineEdit_ShomareShasi->text(),
                          ui->lineEdit_ShomareSanad->text(),
                          ui->lineEdit_Gheymat->text().toULongLong() );
    }
    else if(type == "کروک")
    {
        result = new Crook( "موجود",
                          ui->lineEdit_Model->text(),
                          ui->lineEdit_Brand->text(),
                          ui->lineEdit_Year->text(),
                          ui->lineEdit_Color->text(),
                          ui->lineEdit_InsideColor->text(),
                          ui->lineEdit_ShomareShasi->text(),
                          ui->lineEdit_ShomareSanad->text(),
                          ui->lineEdit_Gheymat->text().toULongLong() );
    }
    else if(type == "شهری")
    {
        result = new CityCar( "موجود",
                          ui->lineEdit_Model->text(),
                          ui->lineEdit_Brand->text(),
                          ui->lineEdit_Year->text(),
                          ui->lineEdit_Color->text(),
                          ui->lineEdit_InsideColor->text(),
                          ui->lineEdit_ShomareShasi->text(),
                          ui->lineEdit_ShomareSanad->text(),
                          ui->lineEdit_Gheymat->text().toULongLong() );
    }
    else if(type == "وانت")
    {
        result = new Vanet( "موجود",
                          ui->lineEdit_Model->text(),
                          ui->lineEdit_Brand->text(),
                          ui->lineEdit_Year->text(),
                          ui->lineEdit_Color->text(),
                          ui->lineEdit_InsideColor->text(),
                          ui->lineEdit_ShomareShasi->text(),
                          ui->lineEdit_ShomareSanad->text(),
                          ui->lineEdit_Gheymat->text().toULongLong() );
    }
    else if(type == "کوپه")
    {
        result = new Coupe( "موجود",
                          ui->lineEdit_Model->text(),
                          ui->lineEdit_Brand->text(),
                          ui->lineEdit_Year->text(),
                          ui->lineEdit_Color->text(),
                          ui->lineEdit_InsideColor->text(),
                          ui->lineEdit_ShomareShasi->text(),
                          ui->lineEdit_ShomareSanad->text(),
                          ui->lineEdit_Gheymat->text().toULongLong() );
    }
    else
    {
        result = nullptr;
    }

    return result;
}
