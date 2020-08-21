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
        setUpincomeChart();
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
    QT_CHARTS_USE_NAMESPACE

    QBarSet *setPoorsant = new QBarSet("پورسانت");
    QBarSet *setSood = new QBarSet("سود فروش");

    setPoorsant->setColor(Qt::darkYellow);
    setSood->setColor(Qt::darkRed);

    foreach(QJsonValue v, Data::getIncomeInfo())
    {
        *setPoorsant << v.toObject()["poorsant"].toInt();
        *setSood << v.toObject()["sood"].toInt();
    }

    QStackedBarSeries *series = new QStackedBarSeries();

    series->append(setPoorsant);
    series->append(setSood);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Amount of income made from poorsant or selling cars during the year");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun"
               << "Jul" << "Aug" << "Sep" << "Oct" << "Nov" << "Dec";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->layout_FinancePage->addWidget(chartView, 0, 1);
}

//namespace Data
//{
//    QJsonArray load_jsonArray(QString arrayName, QString filePath);
//    void save_jsonArray(QJsonArray array, QString arrayName, QString filePath);



//    void changeIncomeInfo(int poorsant,int sood, int index)
//    {
//        if(index < 1 || index > 12) return;
//        QJsonArray income =  load_jsonArray("income", "Documents/Income.json");
//        if(income.empty())
//        {
//            for(int i = 0; i <12; i++)
//            {
//                QJsonObject O;
//                O["poorsant"] = 0;
//                O["sood"] = 0;
//                income.append(O);
//            }
//        }
//        QJsonObject o;
//        o["poorsant"] = poorsant;
//        o["sood"] = sood;
//        income[index - 1] = o;
//        save_jsonArray(income, "income", "Documents/Income.json");
//    }
//    QJsonArray getIncomeInfo()
//    {
//        return load_jsonArray("income", "Documents/Income.json");
//    }
//    void addIncome(int poorsant, int sood, int index)
//    {
//        if(index < 1 || index > 12) return;
//        QJsonObject obj = getIncomeInfo()[index].toObject();
//        changeIncomeInfo(obj["poorsant"].toInt() + poorsant, obj["sood"].toInt() + sood, index);

//    }

//}
