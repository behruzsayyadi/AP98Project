#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Dialog_ManagerLogin.h"
#include "Dialog_managerSingIn.h"

#include <QFile>
#include <QDebug>
#include <QObject>
#include <QTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , backPageIndex(0)

{
    ui->setupUi(this);
    ui->centralwidget->layout()->setMargin(0);
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->pushButton_backPage, SIGNAL(clicked()), this, SLOT(onBackButtonClicked()));
    connect(this, SIGNAL(signinSuccessful()), this, SIGNAL(loginSuccessful()));
    connect(this, SIGNAL(loginSuccessful()), this, SLOT(navigateToHomePage()));

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(displayCurrentDateTime()));
    timer->start(1000);

    manager = new Manager();

    if(QFile("Documents/Managers.json").exists())
    {
        ui->pushButton_SignLog_in->setText("ورود");
        connect(ui->pushButton_SignLog_in, SIGNAL(clicked()), this, SLOT(login()));
    }
    else
    {
        ui->pushButton_SignLog_in->setText("ثبت نام");
        connect(ui->pushButton_SignLog_in, SIGNAL(clicked()), this, SLOT(signin()));
    }
//    setUpChecksTable();
//    setUpincomeChart();
    barSet_Poorsant = new QBarSet("پورسانت", this);
    barSet_Sood = new QBarSet("سود فروش", this);
    stackedBarSeries = new QStackedBarSeries(this);
    chart_Income = new QChart();
    chartView_Income = new QChartView(this);

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setBackPageIndex(int value)
{
    backPageIndex = value;
}
void MainWindow::displayCurrentDateTime()
{
    ui->label_CurrentDateTime->setText(QDateTime::currentDateTime().toString("h:m:s yy:m:d"));

}
void MainWindow::onBackButtonClicked()
{
    ui->stackedWidget->setCurrentIndex(backPageIndex);
}
void MainWindow::navigateToCarsPage()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::navigateToFinancePage()
{
        ui->stackedWidget->setCurrentIndex(3);
        setUpChecksTable();
//        setUpincomeChart();
}
void MainWindow::navigateToHomePage()
{
    ui->stackedWidget->setCurrentIndex(1);
    this->setBackPageIndex(1);
}
void MainWindow::signin()
{

    Dialog_managerSingIn * mngr_sign_dlg = new Dialog_managerSingIn( "ثبت نام مدیر", this);
    if(mngr_sign_dlg->exec() == Dialog_managerSingIn::Accepted)
    {
        *(this->manager) = loadManager();
        this->statusBar()->showMessage("signed up successfuly", 3500);
        emit signinSuccessful();
    }
    else
    {
        QMessageBox::warning(this, "signin failed","could not log in. \n please try again.");

    }
}
void MainWindow::login()
{
    Dialog_ManagerLogin *mngr_dlg = new Dialog_ManagerLogin("ورود ", this);
    if(mngr_dlg->exec() == Dialog_ManagerLogin::Accepted)
    {
        *(this->manager) = loadManager();
        this->statusBar()->showMessage("Logged in succesfully", 3500);
        emit loginSuccessful();
    }
    else
    {
        QMessageBox::warning(this, "login failed","could not log in. \n please try again.");
    }
}
void MainWindow::setUpChecksTable()
{
    ui->tableWidget->clearContents();

    QJsonArray checks_in_table_widget = checks_jsonArray_sort_by_date(loadChecks_jsonArray());
    foreach(QJsonValue x,checks_in_table_widget)
    {
        QString money,bank,shobe_bank,shenase;
        QDate date;
        money = (x.toObject())["money"].toString();
        bank = (x.toObject())["bank"].toString();
        shobe_bank = (x.toObject())["shobe bank"].toString();
        shenase = (x.toObject())["shenase check"].toString();
        date = dateFromJsonObject((x.toObject())["date"].toObject());

        int temp_row_count;
        ui->tableWidget->setDisabled(1);
        temp_row_count = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(temp_row_count,0,new QTableWidgetItem(date.toString("yyyy/MM/dd")));
        ui->tableWidget->setItem(temp_row_count,1,new QTableWidgetItem(money));
        ui->tableWidget->setItem(temp_row_count,2,new QTableWidgetItem(bank));
        ui->tableWidget->setItem(temp_row_count,3,new QTableWidgetItem(shobe_bank));
        ui->tableWidget->setItem(temp_row_count,4,new QTableWidgetItem(shenase));

    }

}
void MainWindow::setUpincomeChart()
{
    barSet_Sood->setColor(Qt::red);
    barSet_Poorsant->setColor(Qt::blue);

    foreach(QJsonValue v, Data::getIncomeInfo())
    {
        *barSet_Poorsant << v.toObject()["poorsant"].toInt();
        *barSet_Sood << v.toObject()["sood"].toInt();
    }
    stackedBarSeries->append(barSet_Sood);
    stackedBarSeries->append(barSet_Poorsant);

    chart_Income->addSeries(stackedBarSeries);
    chart_Income->setTitle("درآمد حاصل از پورسانت ها و سود ها");
    chart_Income->setAnimationOptions(QChart::AllAnimations);

    QStringList months;

    QCalendar cal;
    QLocale c(QLocale::English);
    for( int i = 1, max_months = QDate::currentDate().month(); i <= max_months; i++ )
    {
        months << cal.monthName(c, i, QCalendar::Unspecified, QLocale::ShortFormat);
    }

    QBarCategoryAxis *axisX = new QBarCategoryAxis(this);
    axisX->append(months);
    chart_Income->addAxis(axisX, Qt::AlignBottom);
    stackedBarSeries->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis(this);
    chart_Income->addAxis(axisY, Qt::AlignLeft);
    stackedBarSeries->attachAxis(axisY);

    chart_Income->legend()->setAlignment(Qt::AlignBottom);
    chart_Income->legend()->setVisible(true);

    chartView_Income->setChart(chart_Income);
    chartView_Income->setRenderHint(QPainter::Antialiasing);

    ui->layout_FinancePage->replaceWidget(ui->widget_ChartPlaceHolder, chartView_Income);


}

void MainWindow::addIncome()
{
    Dialog_AddIncome * d = new Dialog_AddIncome(this);
    if(d->exec() == Dialog_AddIncome::Accepted)
    {
        Data::addIncome(d->getPoorsant(),d->getSood(),d->getMonthIndex());
    }
//    setUpincomeChart();

}

void MainWindow::addNewCheck()
{
    Dialog_AddCheck * d = new Dialog_AddCheck(this);
    if(d->exec() == Dialog_AddCheck::Accepted)
    {
        Checkinfo * a = d->getCheck();
        a->addCheck();
        delete a;
    }
}
