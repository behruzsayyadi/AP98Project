#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QInputDialog>

#include <QCalendar>

#include <QVector>

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
    void setBackPageIndex(int value);
    void setUpChecksTable();
    void setUpincomeChart();

    QBarSet * barSet_Poorsant;
    QBarSet * barSet_Sood;
    QStackedBarSeries * stackedBarSeries;
    QChart * chart_Income;
    QChartView * chartView_Income;
private slots:
    void signin();
    void login();
    void addNewCheck();
    void addIncome();

signals:
    void signinSuccessful();
    void loginSuccessful();

};


#endif // MAINWINDOW_H
