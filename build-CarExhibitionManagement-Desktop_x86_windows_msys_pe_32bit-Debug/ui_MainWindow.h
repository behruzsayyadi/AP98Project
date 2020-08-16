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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "Page_Cars.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogin;
    QAction *actionCalculator;
    QAction *actionSignIn;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_CurrentDateTime;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_backPage;
    QStackedWidget *stackedWidget;
    QWidget *page_Wellcome;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_SignLog_in;
    QWidget *page_Home;
    QPushButton *pushButton_Cars;
    QPushButton *pushButton_Finance;
    Page_Cars *page_Cars;
    QWidget *page_Finance;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget;
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
        actionCalculator = new QAction(MainWindow);
        actionCalculator->setObjectName(QString::fromUtf8("actionCalculator"));
        actionSignIn = new QAction(MainWindow);
        actionSignIn->setObjectName(QString::fromUtf8("actionSignIn"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
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

        gridLayout->addWidget(label, 0, 2, 1, 1);

        label_CurrentDateTime = new QLabel(centralwidget);
        label_CurrentDateTime->setObjectName(QString::fromUtf8("label_CurrentDateTime"));
        label_CurrentDateTime->setMinimumSize(QSize(100, 0));
        QFont font1;
        font1.setPointSize(12);
        label_CurrentDateTime->setFont(font1);
        label_CurrentDateTime->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:1, y1:0, x2:1, y2:1, stop:0.517413 rgba(0, 85, 127, 255));\n"
"border-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"border-style:outset;\n"
"border-width:0 4 4 0;\n"
"border-right:none;\n"
"border-bottom-right-radius:10px;\n"
"\n"
""));

        gridLayout->addWidget(label_CurrentDateTime, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        pushButton_backPage = new QPushButton(centralwidget);
        pushButton_backPage->setObjectName(QString::fromUtf8("pushButton_backPage"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_backPage->sizePolicy().hasHeightForWidth());
        pushButton_backPage->setSizePolicy(sizePolicy);
        pushButton_backPage->setMinimumSize(QSize(10, 10));

        gridLayout->addWidget(pushButton_backPage, 1, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(100, 0));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page_Wellcome = new QWidget();
        page_Wellcome->setObjectName(QString::fromUtf8("page_Wellcome"));
        gridLayout_2 = new QGridLayout(page_Wellcome);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_SignLog_in = new QPushButton(page_Wellcome);
        pushButton_SignLog_in->setObjectName(QString::fromUtf8("pushButton_SignLog_in"));
        pushButton_SignLog_in->setFont(font1);
        pushButton_SignLog_in->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:1, y1:0, x2:1, y2:1, stop:0.517413 rgba(0, 85, 127, 255));\n"
"border-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"border-style:outset;\n"
"border-width:4;\n"
""));

        gridLayout_2->addWidget(pushButton_SignLog_in, 1, 0, 1, 1);

        stackedWidget->addWidget(page_Wellcome);
        page_Home = new QWidget();
        page_Home->setObjectName(QString::fromUtf8("page_Home"));
        pushButton_Cars = new QPushButton(page_Home);
        pushButton_Cars->setObjectName(QString::fromUtf8("pushButton_Cars"));
        pushButton_Cars->setGeometry(QRect(490, 100, 80, 21));
        pushButton_Finance = new QPushButton(page_Home);
        pushButton_Finance->setObjectName(QString::fromUtf8("pushButton_Finance"));
        pushButton_Finance->setGeometry(QRect(490, 140, 80, 21));
        stackedWidget->addWidget(page_Home);
        page_Cars = new Page_Cars();
        page_Cars->setObjectName(QString::fromUtf8("page_Cars"));
        stackedWidget->addWidget(page_Cars);
        page_Finance = new QWidget();
        page_Finance->setObjectName(QString::fromUtf8("page_Finance"));
        gridLayout_3 = new QGridLayout(page_Finance);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableWidget = new QTableWidget(page_Finance);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_3->addWidget(tableWidget, 0, 0, 1, 1);

        stackedWidget->addWidget(page_Finance);

        gridLayout->addWidget(stackedWidget, 2, 0, 1, 3);

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
        menuTools->addAction(actionCalculator);
        menuTools->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(pushButton_Cars, SIGNAL(clicked()), MainWindow, SLOT(navigateToCarsPage()));
        QObject::connect(pushButton_Finance, SIGNAL(clicked()), MainWindow, SLOT(navigateToFinancePage()));

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        actionCalculator->setText(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        actionSignIn->setText(QCoreApplication::translate("MainWindow", "SignIn", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Taskhir AutoGallery", nullptr));
        label_CurrentDateTime->setText(QString());
        pushButton_backPage->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        pushButton_SignLog_in->setText(QCoreApplication::translate("MainWindow", "Log(Sign) In", nullptr));
        pushButton_Cars->setText(QCoreApplication::translate("MainWindow", "Cars", nullptr));
        pushButton_Finance->setText(QCoreApplication::translate("MainWindow", "Finance", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
