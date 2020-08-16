#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "Manager.h"
#include "CheckInfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
private slots:
    void signin();
    void login();
signals:
    void signinSuccessful();
    void loginSuccessful();
};
#endif // MAINWINDOW_H
