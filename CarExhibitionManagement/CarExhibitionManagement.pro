QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Car.cpp \
    CityCar.cpp \
    Coupe.cpp \
    Crook.cpp \
    Data.cpp \
    Dialog_AddCar.cpp \
    Dialog_AddCheck.cpp \
    Dialog_AddIncome.cpp \
    Dialog_Memorandum.cpp \
    Memorandum.cpp \
    Page_Cars.cpp \
    SUV.cpp \
    CheckInfo.cpp \
    Customer.cpp \
    Dialog_ManagerLogin.cpp \
    Dialog_managerSingIn.cpp \
    Human.cpp \
    MainWindow.cpp \
    Manager.cpp \
    Seller.cpp \
    Vanet.cpp \
    main.cpp

HEADERS += \
    Car.h \
    CityCar.h \
    Coupe.h \
    Crook.h \
    Data.h \
    Dialog_AddCar.h \
    Dialog_AddCheck.h \
    Dialog_AddIncome.h \
    Dialog_Memorandum.h \
    Memorandum.h \
    Page_Cars.h \
    SUV.h \
    CheckInfo.h \
    Customer.h \
    Dialog_ManagerLogin.h \
    Dialog_managerSingIn.h \
    Human.h \
    MainWindow.h \
    Manager.h \
    Seller.h \
    Vanet.h

FORMS += \
    Dialog_AddCar.ui \
    Dialog_AddCheck.ui \
    Dialog_AddIncome.ui \
    Dialog_ManagerLogin.ui \
    Dialog_Memorandum.ui \
    Dialog_managerSingIn.ui \
    MainWindow.ui \
    Page_Cars.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
