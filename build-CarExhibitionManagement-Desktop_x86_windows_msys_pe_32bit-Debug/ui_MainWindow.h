/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogin;
    QAction *actionCalculator_2;
    QAction *actionSignIn;
    QWidget *centralwidget;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page_Home;
    QPushButton *pushButton_SignLog_in;
    QWidget *page_2;
    QWidget *page_3;
    QWidget *page_4;
    QLabel *label_2;
    QLabel *label_myClock;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuTools;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(778, 592);
        QPalette palette;
        QBrush brush(QColor(0, 85, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient(1, 0, 1, 1);
        gradient.setSpread(QGradient::ReflectSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0.517413, QColor(0, 125, 187, 255));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QLinearGradient gradient1(1, 0, 1, 1);
        gradient1.setSpread(QGradient::ReflectSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0.517413, QColor(0, 125, 187, 255));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QLinearGradient gradient2(1, 0, 1, 1);
        gradient2.setSpread(QGradient::ReflectSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0.517413, QColor(0, 125, 187, 255));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient3(1, 0, 1, 1);
        gradient3.setSpread(QGradient::ReflectSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0.517413, QColor(0, 125, 187, 255));
        QBrush brush4(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        QLinearGradient gradient4(1, 0, 1, 1);
        gradient4.setSpread(QGradient::ReflectSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0.517413, QColor(0, 125, 187, 255));
        QBrush brush5(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        QLinearGradient gradient5(1, 0, 1, 1);
        gradient5.setSpread(QGradient::ReflectSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0.517413, QColor(0, 125, 187, 255));
        QBrush brush6(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        QBrush brush7(QColor(120, 120, 120, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        QLinearGradient gradient6(1, 0, 1, 1);
        gradient6.setSpread(QGradient::ReflectSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0.517413, QColor(0, 125, 187, 255));
        QBrush brush8(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        QLinearGradient gradient7(1, 0, 1, 1);
        gradient7.setSpread(QGradient::ReflectSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0.517413, QColor(0, 125, 187, 255));
        QBrush brush9(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        QLinearGradient gradient8(1, 0, 1, 1);
        gradient8.setSpread(QGradient::ReflectSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0.517413, QColor(0, 125, 187, 255));
        QBrush brush10(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        MainWindow->setPalette(palette);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:1, y1:0, x2:1, y2:1, stop:0.517413 rgba(0, 125, 187, 255));\n"
""));
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionCalculator_2 = new QAction(MainWindow);
        actionCalculator_2->setObjectName(QString::fromUtf8("actionCalculator_2"));
        actionSignIn = new QAction(MainWindow);
        actionSignIn->setObjectName(QString::fromUtf8("actionSignIn"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(470, 10, 291, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Footlight MT Light"));
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:1, y1:0, x2:1, y2:1, stop:0.517413 rgba(0, 85, 127, 255));\n"
"border-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"border-style:outset;\n"
"border-width:4;\n"
"border-radius:10px;\n"
"\n"
""));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 70, 741, 451));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page_Home = new QWidget();
        page_Home->setObjectName(QString::fromUtf8("page_Home"));
        pushButton_SignLog_in = new QPushButton(page_Home);
        pushButton_SignLog_in->setObjectName(QString::fromUtf8("pushButton_SignLog_in"));
        pushButton_SignLog_in->setGeometry(QRect(40, 50, 161, 41));
        QFont font1;
        font1.setPointSize(12);
        pushButton_SignLog_in->setFont(font1);
        pushButton_SignLog_in->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:1, y1:0, x2:1, y2:1, stop:0.517413 rgba(0, 85, 127, 255));\n"
"border-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"border-style:outset;\n"
"border-width:4;\n"
""));
        stackedWidget->addWidget(page_Home);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget->addWidget(page_4);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 10, 71, 31));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:1, y1:0, x2:1, y2:1, stop:0.517413 rgba(0, 85, 127, 255));\n"
"border-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"border-style:outset;\n"
"border-width:4;\n"
"border-radius:0px;\n"
"border-left:none;\n"
"border-top-right-radius:10px;\n"
"border-bottom-right-radius:10px;"));
        label_myClock = new QLabel(centralwidget);
        label_myClock->setObjectName(QString::fromUtf8("label_myClock"));
        label_myClock->setGeometry(QRect(10, 10, 111, 31));
        label_myClock->setFont(font1);
        label_myClock->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:1, y1:0, x2:1, y2:1, stop:0.517413 rgba(0, 85, 127, 255));\n"
"border-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"border-style:outset;\n"
"border-width:4;\n"
"border-right:none;\n"
"border-top-left-radius:10px;\n"
"border-bottom-left-radius:10px;\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 778, 20));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuTools->menuAction());
        menuTools->addAction(actionCalculator_2);
        menuTools->addSeparator();

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        actionCalculator_2->setText(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        actionSignIn->setText(QCoreApplication::translate("MainWindow", "SignIn", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Taskhir AutoGallery", nullptr));
        pushButton_SignLog_in->setText(QCoreApplication::translate("MainWindow", "Log(Sign) In", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\330\263\330\247\330\271\330\252 :", nullptr));
        label_myClock->setText(QString());
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
