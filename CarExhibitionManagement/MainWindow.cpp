#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Dialog_ManagerLogin.h"
#include "Dialog_managerSingIn.h"
#include "Dialog_AddEvent.h"

#include <QFile>
#include <QDebug>
#include <QObject>
#include <QTime>
#include <QMessageBox>
#include <algorithm>
#include <QRegExp>

QBrush MainWindow::importantCustomerHighlight(QColor(10, 200, 10, 90));
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , backPageIndex(0)
    , least_car_price(99999999999)
{
    ui->setupUi(this);
    ui->centralwidget->layout()->setMargin(0);
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton_backPage->hide();
    this->setWindowTitle("نمایشگاه اتومبیل تسخیر");
//    this->setWindowIcon(QIcon(":/resources/icon_car_2.png"));

    connect(ui->page_Cars, SIGNAL(newCarAdded(Car)), this, SLOT(onNewCarAdded(Car)));

    connect(ui->pushButton_backPage, SIGNAL(clicked()), this, SLOT(onBackButtonClicked()));
    connect(this, SIGNAL(signinSuccessful()), this, SIGNAL(loginSuccessful()));
    connect(this, SIGNAL(loginSuccessful()), this, SLOT(navigateToHomePage()));

    connect(ui->page_Cars, SIGNAL(newIncome(QString, QString, int)), this, SLOT(addIncome(QString, QString, int)));

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

    barSet_Poorsant = new QBarSet("پورسانت", this);
    barSet_Sood = new QBarSet("سود فروش", this);
    stackedBarSeries = new QStackedBarSeries(this);
    chart_Income = new QChart();
    chartView_Income = new QChartView(this);


    setUpChecksTable();
    setUpincomeChart();
    setUpImportantCustomersTable();
    setUpEventsTable();
    ui->pushButton_saveImportantCustomerRow->setEnabled(false);


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
    ui->label_CurrentDateTime->setText(QDateTime::currentDateTime().toString("dddd dd/MM/yyyy hh:mm:ss"));

}
void MainWindow::onBackButtonClicked()
{
    ui->stackedWidget->setCurrentIndex(backPageIndex);
    if(ui->stackedWidget->currentIndex() == 1)
    {
        ui->pushButton_backPage->hide();
    }

    QWidget * page = ui->stackedWidget->widget(1);
    QPropertyAnimation * animation = new QPropertyAnimation(page, "geometry");
    animation->setEasingCurve(QEasingCurve::InOutSine);
    animation->setDuration(750);
    animation->setStartValue(QRect(page->width() * 2,0, page->width(), page->height()));
    animation->setEndValue(QRect(0, 0,page->width(), page->height()));
    animation->start(QPropertyAnimation::DeleteWhenStopped);

}
void MainWindow::navigateToCarsPage()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->pushButton_backPage->show();

    QWidget * page = ui->stackedWidget->widget(2);
    QPropertyAnimation * animation = new QPropertyAnimation(page, "geometry");
    animation->setEasingCurve(QEasingCurve::InOutSine);
    animation->setDuration(750);
    animation->setStartValue(QRect(-page->width(),0, page->width(), page->height()));
    animation->setEndValue(QRect(0, 0,page->width(), page->height()));
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}
void MainWindow::navigateToFinancePage()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->pushButton_backPage->show();
    updateChecksTable();

    QWidget * page = ui->stackedWidget->widget(3);
    QPropertyAnimation * animation = new QPropertyAnimation(page, "geometry");
    animation->setEasingCurve(QEasingCurve::InOutSine);
    animation->setDuration(750);
    animation->setStartValue(QRect(-page->width(),0, page->width(), page->height()));
    animation->setEndValue(QRect(0, 0,page->width(), page->height()));
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}
void MainWindow::navigateToHomePage()
{
    ui->stackedWidget->setCurrentIndex(1);
    this->setBackPageIndex(1);
    ui->pushButton_backPage->hide();

    QWidget * page = ui->stackedWidget->widget(1);
    QPropertyAnimation * animation = new QPropertyAnimation(page, "geometry");
    animation->setEasingCurve(QEasingCurve::InOutSine);
    animation->setDuration(750);
    animation->setStartValue(QRect(-page->width(),0, page->width(), page->height()));
    animation->setEndValue(QRect(0, 0,page->width(), page->height()));
    animation->start(QPropertyAnimation::DeleteWhenStopped);

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
        QJsonObject o = x.toObject();
        addNewCheckRow(Checkinfo ( o["money"].toString(),
                                   o["bank"].toString(),
                                   o["shobe bank"].toString(),
                                   dateFromJsonObject(o["date"].toObject()),
                                   o["shenase check"].toString() ));
    }

}
void MainWindow::setUpincomeChart()
{
    foreach(QJsonValue v, Data::getIncomeInfo())
    {
        *barSet_Poorsant << v.toObject()["poorsant"].toString().toULongLong();
        *barSet_Sood << v.toObject()["sood"].toString().toULongLong();
    }
    stackedBarSeries->append(barSet_Sood);
    stackedBarSeries->append(barSet_Poorsant);

    chart_Income->addSeries(stackedBarSeries);
    chart_Income->setTitle("درآمد حاصل از پورسانت ها و سود ها");
    chart_Income->setAnimationOptions(QChart::SeriesAnimations);

    QStringList months;

    QLocale c(QLocale::English);
    for( int i = 1, max_months = QDate::currentDate().month(); i <= max_months; i++ )
    {
        months << c.monthName(i);
    }

    QBarCategoryAxis *axisX = new QBarCategoryAxis(this);
    axisX->append(months);
    chart_Income->addAxis(axisX, Qt::AlignBottom);
    stackedBarSeries->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis(this);

    if(Data::areAllIncomesEmpty())
    {
        axisY->setMax(1000000000);
    }

    chart_Income->addAxis(axisY, Qt::AlignLeft);
    stackedBarSeries->attachAxis(axisY);

    chart_Income->legend()->setAlignment(Qt::AlignBottom);
    chart_Income->legend()->setVisible(true);

    chart_Income->setTheme(QChart::ChartThemeDark);

    barSet_Sood->setColor(Qt::red);
    barSet_Poorsant->setColor(Qt::blue);

    chartView_Income->setChart(chart_Income);
    chartView_Income->setRenderHint(QPainter::Antialiasing);

    ui->layout_FinancePage->replaceWidget(ui->widget_ChartPlaceHolder, chartView_Income);
}

void MainWindow::setUpImportantCustomersTable()
{
    QList<qreal> car_prices_list;
    for(auto v : loadCoupes_jsonArray())
    {
        car_prices_list << v.toObject()["gheymat"].toString().toULongLong();
    }
    for(auto v : loadCityCars_jsonArray())
    {
        car_prices_list << v.toObject()["gheymat"].toString().toULongLong();
    }
    for(auto v : loadCrooks_jsonArray())
    {
        car_prices_list << v.toObject()["gheymat"].toString().toULongLong();
    }
    for(auto v : loadVanets_jsonArray())
    {
        car_prices_list << v.toObject()["gheymat"].toString().toULongLong();
    }
    for(auto v : loadSUVs_jsonArray())
    {
        car_prices_list << v.toObject()["gheymat"].toString().toULongLong();
    }
    std::sort(car_prices_list.begin(), car_prices_list.end());
    if(!car_prices_list.isEmpty()) least_car_price = *car_prices_list.begin();
    QTableWidget * table = ui->tableWidget_important_customers;
    QJsonObject o;
    int i = 0;

    QTableWidgetItem * name, * phone_number, * money;
    for(QJsonValue v : Data::load_jsonArray(Data::default_important_customers_array_name, Data::default_important_customers_path))
    {
        o = v.toObject();
        table->insertRow(i);
        name = new QTableWidgetItem(o["name"].toString());
        phone_number = new QTableWidgetItem(o["phone number"].toString());
        money = new QTableWidgetItem(o["money"].toString());
        if(!car_prices_list.isEmpty())
        {
            if(o["money"].toString().toULongLong() > least_car_price)
            {
                name->setBackground(importantCustomerHighlight);
                phone_number->setBackground(importantCustomerHighlight);
                money->setBackground(importantCustomerHighlight);
            }
        }
        table->setItem(i, 0, name);
        table->setItem(i, 1, phone_number);
        table->setItem(i, 2, money);
        i++;
    }
}

void MainWindow::setUpEventsTable()
{
    for(auto x : Data::load_jsonArray("events", "Documents/Events.json"))
    {
        QJsonObject o = x.toObject();
        addNewEventRow(o["day"].toString(), o["title"].toString(), o["description"].toString());
    }
}

void MainWindow::addNewEventRow(QString day, QString title, QString description)
{
    QTableWidget * table = ui->tableWidget_Events;
    int row = table->rowCount();
    table->insertRow(row);
    QTableWidgetItem * item_day = new QTableWidgetItem(day),
                     * item_title = new QTableWidgetItem(title),
                     * item_description = new QTableWidgetItem(description);
    table->setItem(row, 0, item_day);
    table->setItem(row, 1, item_title);
    table->setItem(row, 2, item_description);

}

void MainWindow::addIncome()
{
    Dialog_AddIncome * d = new Dialog_AddIncome(this);
    if(d->exec() == Dialog_AddIncome::Accepted)
    {
        int month_index = d->getMonthIndex();
        quint64 poorsant = d->getPoorsant();
        quint64 sood = d->getSood();
        Data::addIncome(poorsant, sood, month_index);
        addIncomeToChart(poorsant, sood, month_index);

    }
}

void MainWindow::addIncome(QString poorsant, QString sood, int month_index)
{
    Data::addIncome(poorsant.toULongLong(), sood.toULongLong(), month_index);
    addIncomeToChart(poorsant.toULongLong(), sood.toULongLong(), month_index);
}

void MainWindow::addNewEvent()
{
    Dialog_AddEvent * d = new Dialog_AddEvent(this);
    if(d->exec() == Dialog_AddEvent::Accepted)
    {
        QJsonObject o;
        QString day = d->getDay(), title = d->getTitle(), description = d->getDescription();
        o["day"] = day;
        o["title"] = title;
        o["description"] = description;
        Data::add(o, "description", o["description"], "events", "Documents/Events.json");
        addNewEventRow(day, title, description);
    }
}

void MainWindow::onNewCarAdded(Car c)
{
    QTableWidget * table = ui->tableWidget_important_customers;
    int row_count = table->rowCount(), column_count = table->columnCount();
    qreal gheymat = c.getGheymat();
    if(gheymat < least_car_price) least_car_price = gheymat;
    for(int i = 0; i < row_count; i++)
    {
        if(table->item(i, 2)->text().toULongLong() < gheymat)
        {
            for(int j = 0; j < column_count; j++)
            {
                table->item(i, j)->setBackground(importantCustomerHighlight);
            }
        }
    }
}

void MainWindow::addNewImportantCustomerRow()
{
    QTableWidget * table = ui->tableWidget_important_customers;
    int row_count = table->rowCount();
    table->insertRow(row_count);
    table->setItem(row_count, 0, new QTableWidgetItem);
    table->setItem(row_count, 1, new QTableWidgetItem);
    table->setItem(row_count, 2, new QTableWidgetItem);
    ui->pushButton_saveImportantCustomerRow->setEnabled(true);
    ui->pushButton_addImportantCustomerRow->setEnabled(false);

}

void MainWindow::saveNewImportantCustomerRow()
{
    QTableWidget * table = ui->tableWidget_important_customers;
    int row_count = table->rowCount();
    QString name = table->item(row_count - 1 , 0)->text();
    QString phone_number  = table->item(row_count - 1, 1)->text();
    QString money = table->item(row_count - 1, 2)->text();
    if(money.isEmpty() || phone_number.isEmpty() || name.isEmpty())
    {
        QMessageBox::warning(this, "خطا", "تمام اطلاعات جدول ضروری هستند");
        return;
    }
    QJsonObject o;
    o["name"] = name;
    o["phone number"] = phone_number;
    o["money"] = money;

    Data::add(o,
            "name",
            o["name"].toString(),
            Data::default_important_customers_array_name,
            Data::default_important_customers_path );
    ui->pushButton_addImportantCustomerRow->setEnabled(true);
    ui->pushButton_saveImportantCustomerRow->setEnabled(false);
}

void MainWindow::onImportantCustomersTableItemChanged(QTableWidgetItem * item)
{
    if(item->column() == 2)
    {
        if(item->text().toULongLong() > least_car_price)
        {
            int row = item->row();
            item->setBackground(importantCustomerHighlight);
            ui->tableWidget_important_customers->item(row, 0)->setBackground(importantCustomerHighlight);
            ui->tableWidget_important_customers->item(row, 1)->setBackground(importantCustomerHighlight);
        }
    }
}

void MainWindow::addNewCheck()
{
    Dialog_AddCheck * d = new Dialog_AddCheck(this);
    if(d->exec() == Dialog_AddCheck::Accepted)
    {
        Checkinfo * a = d->getCheck();
        a->addCheck();
        addNewCheckRow(*a);
        delete a;
    }
}
void MainWindow::addNewCheckRow(Checkinfo c)
{
    QTableWidget * table = ui->tableWidget_checks;
    int temp_row_count = table->rowCount();
    table->insertRow(temp_row_count);
    table->setItem(temp_row_count,0,new QTableWidgetItem(c.getDate().toString("yyyy/MM/dd")));
    table->setItem(temp_row_count,1,new QTableWidgetItem(c.getMoney()));
    table->setItem(temp_row_count,2,new QTableWidgetItem(c.getBank()));
    table->setItem(temp_row_count,3,new QTableWidgetItem(c.getShobeBank()));
    table->setItem(temp_row_count,4,new QTableWidgetItem(c.getShenase()));
}
void MainWindow::addIncomeToChart(quint64 poorsant, quint64 sood, int month_index)
{
    quint64 current_poorsant = barSet_Poorsant->at(month_index);
    quint64 current_sood = barSet_Sood->at(month_index);

    barSet_Poorsant->replace(month_index, current_poorsant + poorsant);
    barSet_Sood->replace(month_index, current_sood + sood);

    chart_Income->update(chart_Income->geometry());
}

void MainWindow::updateChecksTable()
{
    QTableWidget * table = ui->tableWidget_checks;
    QJsonArray checks_array = checks_jsonArray_sort_by_date(loadChecks_jsonArray());
    int number_of_new_checks = checks_array.size() - table->rowCount();
    if(number_of_new_checks > 0)
    {
        int index_of_last_check = table->rowCount();
        for(int i = 0 ; i < number_of_new_checks ; i++)
        {
            QJsonObject o = checks_array[index_of_last_check].toObject();
            addNewCheckRow(findCheck(o["shenase check"].toString()));
            index_of_last_check ++;
        }
    }

}
