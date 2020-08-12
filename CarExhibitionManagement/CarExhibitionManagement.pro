QT       += core gui

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
    Cheque.cpp \
    CityCar.cpp \
    Customer.cpp \
    Document.cpp \
    Exhibition.cpp \
    Human.cpp \
    Manager.cpp \
    Memorandum.cpp \
    SUV.cpp \
    Seller.cpp \
    SportCar.cpp \
    UI/Form_login.cpp \
    UI/Form_register.cpp \
    UI/MainWindow.cpp \
    UI/StackedWidget.cpp \
    UI/TabWidget_login_register.cpp \
    main.cpp

HEADERS += \
    Car.h \
    Cheque.h \
    CityCar.h \
    Customer.h \
    Document.h \
    Exhibition.h \
    Human.h \
    Manager.h \
    Memorandum.h \
    SUV.h \
    Seller.h \
    SportCar.h \
    UI/Form_login.h \
    UI/Form_register.h \
    UI/MainWindow.h \
    UI/StackedWidget.h \
    UI/TabWidget_login_register.h

FORMS += \
    UI/Form_login.ui \
    UI/Form_register.ui \
    UI/MainWindow.ui \
    UI/StackedWidget.ui \
    UI/TabWidget_login_register.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
