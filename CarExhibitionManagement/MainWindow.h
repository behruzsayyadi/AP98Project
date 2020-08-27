#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QInputDialog>
#include <QTableWidgetItem>
#include <QBrush>
#include <QVector>

#include <QPropertyAnimation>

#include <QtCharts/QChartView>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>



#include "Data.h"

#include "Manager.h"
#include "CheckInfo.h"

#include "Dialog_Memorandum.h"
#include "Dialog_AddIncome.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void displayCurrentDateTime();
    void onBackButtonClicked();
    void navigateToCarsPage();
    void navigateToFinancePage();
    void navigateToHomePage();
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Manager *manager;
    int backPageIndex;
    qreal least_car_price;
    void setBackPageIndex(int value);
    void setUpChecksTable();
    void setUpincomeChart();
    void setUpImportantCustomersTable();
    void setUpVitrine();
    void setUpEventsTable();

    void addNewEventRow(QString day, QString title, QString description);
    void addNewCheckRow(Checkinfo check);
    void addIncomeToChart(quint64 poorsant, quint64 sood, int month_index);

    void updateChecksTable();
    QBarSet * barSet_Poorsant;
    QBarSet * barSet_Sood;
    QStackedBarSeries * stackedBarSeries;
    QChart * chart_Income;
    QChartView * chartView_Income;
    static QBrush importantCustomerHighlight;
private slots:
    void signin();
    void login();

    void addNewCheck();
    void addIncome();
    void addIncome(QString poorsant, QString sood, int month_index);
    void addNewEvent();

    void onNewCarAdded(Car);
    void addNewImportantCustomerRow();
    void saveNewImportantCustomerRow();
    void onImportantCustomersTableItemChanged(QTableWidgetItem*);

signals:
    void signinSuccessful();
    void loginSuccessful();

};


#endif // MAINWINDOW_H
